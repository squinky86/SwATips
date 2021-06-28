#!/bin/bash

# Action Variables
CLEAN=false
EPUB=true
PDF=true
HTML=true
REBUILD=false
AUTOADD=false

# Dependency Variables
BIBER=1
GIT=1
KPSEWHICH=1
LATEXMK=1
LUALATEX=1
LUAOTFLOAD=1
JUICE=1

# Latex Package Dependencies
SCANNEDPACKAGES=()

# Article List
ARTICLES=()
NUMS=()

if [ -f "build.sh.cache" ]; then
	. build.sh.cache
fi

function check() {
	if [ $1 -gt 0 ]; then
		echo -n "Checking for $2..."
		checkCommand $2 "e"
		RET=$?
		if [ $RET -gt 0 ]; then
			exit 1
		fi
		echo "OK!"
		if [ ! -z "${3}" ]; then
			echo "${3}=0" >> build.sh.cache
		fi
		return $RET
	fi
	return 0
}

function scanHeader() {
	if [[ " ${SCANNEDPACKAGES[@]} " =~ " ${1} " ]]; then
		return 0
	fi
	SCANNEDPACKAGES+=( $1 )
	check "$KPSEWHICH" "kpsewhich" "KPSEWHICH"
	KPSEWHICH=$?
	echo -n "Checking for ${1}.sty..."
	kpsewhich ${1}.sty > /dev/null 2>&1
	if [ $? -gt 0 ]; then
		echo "Please install the LaTeX package corresponding to ${1}.sty."
		exit 1
	fi
	echo "SCANNEDPACKAGES+=( \"${1}\" )" >> build.sh.cache
	echo "OK!"
	return 0
}

function findPackages() {
	#get dependencies
	if [ -f "${1}.tex" ]; then
		for x in `grep '^\\\\usepackage\|^\\\\RequirePackage' ${1}.tex | sed -e 's:^.*{\(.*\)}$:\1:g'`; do
			scanHeader "${x}"
		done
	fi
	if [ -f "${1}.pre" ]; then
	for x in `grep '^\\\\usepackage\|^\\\\RequirePackage' ${1}.pre | sed -e 's:^.*{\(.*\)}$:\1:g'`; do
			scanHeader "${x}"
		done
	fi
}

function lmk() {
	latexmk -quiet -e '$biber='"'"'biber --isbn-normalise %O %S'"'" -pdflatex=lualatex -pdf $1
}

function checkCommand() {
	if ! command -v $1 > /dev/null 2>&1; then
		echo "Please install $1."
		if [ "$2" != "e" ]; then
			exit 1
		fi
		return 1
	fi
	return 0
}

if [ $# -gt 0 ]; then
	CLEAN=false
	EPUB=false
	PDF=false
	HTML=false
fi

while [ "$1" != "" ]; do
	case $1 in
		-a | --add )	AUTOADD=true
			;;
		-c | --clean )	CLEAN=true
			;;
		-e | --epub )	EPUB=true
			;;
		-p | --pdf )	PDF=true
			;;
		-H | --html )	HTML=true
			PDF=true
			;;
		-r | --rebuild ) REBUILD=true
			;;
		-h | --help )
			echo "Usage: $0 to build all options. Optional flags:"
			echo -e "\t-a (--add) auto-add generated files to repo"
			echo -e "\t-c (--clean) only clean extraneous files"
			echo -e "\t-e (--epub)  only build .epub file"
			echo -e "\t-p (--pdf)   only build .pdf articles"
			echo -e "\t-H (--html)  only build .html articles"
			echo -e "\t-r (--rebuild) rebuild already built files"
			echo -e "\t-h (--help)  this help message"
			exit
			;;
		*) echo "Unknown option $1"
			exit 1
	esac
	shift
done

if [ $CLEAN == true ]; then
	echo -n "Cleaning extraneous files..."
	if [ -e "build.sh.cache" ]; then
		rm build.sh.cache
	fi
	echo "OK!"
fi

if [ $PDF == true ]; then
	check "$LUALATEX" "lualatex" "LUALATEX"
	LUALATEX=$?
	check "$BIBER" "biber" "BIBER"
	BIBER=$?
	check "$LATEXMK" "latexmk" "LATEXMK"
	LATEXMK=$?
	check "$LUAOTFLOAD" "luaotfload-tool" "LUAOTFLOAD"
	LUAOTFLOAD=$?
	check "$JUICE" "juice" "JUICE"
	JUICE=$?
	check "$GIT" "git" "GIT"
	GIT=$?

	echo -n "" > html/articles.inc
	echo -n "" > html/articles-full.inc
	echo -n "" > html/rss.inc
	echo "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" > html/sitemap.xml
	echo "<urlset xmlns=\"http://www.sitemaps.org/schemas/sitemap/0.9\">" >> html/sitemap.xml
	echo "<url>" >> html/sitemap.xml
	echo -e "\t<loc>https://www.SwATips.com/</loc>" >> html/sitemap.xml
	echo -e "\t<lastmod>$(date -Iseconds)</lastmod>" >> html/sitemap.xml
	echo "</url>" >> html/sitemap.xml
	echo "<url>" >> html/sitemap.xml
	echo -e "\t<loc>https://www.SwATips.com/articles.php</loc>" >> html/sitemap.xml
	echo -e "\t<lastmod>$(date -Iseconds)</lastmod>" >> html/sitemap.xml
	echo "</url>" >> html/sitemap.xml
	for x in tips/*.tex; do
		TMPDIR=$(mktemp -d)
		NUM=${x/tips\//}
		NUM=${NUM/\.tex/}
		echo -n "Building ${NUM}..."
		ARTICLENAME="UNKNOWN"
		cp templates/article.tex templates/sources.bib ${TMPDIR}/
		cp templates/article.html ${TMPDIR}/article_template.html
		cp tips/${NUM}.* ${TMPDIR}/
		ARTICLENAME=$(grep ArticleName ${TMPDIR}/${NUM}.pre | sed -e 's:\\def \\ArticleName{::g' -e 's:}::g' -e 's:\\::g')
		if [ ! -f "html/articles/${NUM}.pdf" ] || [ $REBUILD == true ]; then
			pushd ${TMPDIR} > /dev/null
			sed -i -e "s:NUM:${NUM}:g" article.tex
			sed -i -e "s:NUM:${NUM}:g" article_template.html
			lmk article >/dev/null 2>&1
			if [ $HTML == true ]; then
				make4ht -l article "fn-in,svg" > /dev/null
				echo "<!DOCTYPE html>" > ${NUM}.html
				echo "<html xml:lang='en-US' lang='en-US'>" >> ${NUM}.html
				echo "<head>" >> ${NUM}.html
				xmllint --pretty --format --xpath "//head/node()" article.html >> ${NUM}.html
				echo "<script async=\"async\" src=\"https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client=ca-pub-4110907817782130\" crossorigin=\"anonymous\"></script>" >> ${NUM}.html
				echo "<style>" >> ${NUM}.html
				cat article.css >> ${NUM}.html
				echo "</style>" >> ${NUM}.html
				echo "</head>" >> ${NUM}.html
				echo "<body>" >> ${NUM}.html
				cat article_template.html >> ${NUM}.html
				tail -n +12 article.html >> ${NUM}.html
				sed -i -z "s|<title>.*</title>|<title>${ARTICLENAME}</title>|g" ${NUM}.html
				sed -i -e '/article.css/d' ${NUM}.html
				#copy images
				mkdir images
				i=0
				if compgen -G "*.svg" > /dev/null; then
					for x in *.svg; do
						#remove extraneous png file if we use the SVG instead
						if [ -f "${x/.svg/.png}" ]; then
							rm ${x/.svg/.png}
						fi
						((i=i+1))
						NEWNAME="images/${NUM}-${i}.svg"
						cp ${x} ${NEWNAME}
						sed -i -e "s:${x}:${NEWNAME}:g" ${NUM}.html
					done
				fi
				if compgen -G "*.png" > /dev/null; then
					for x in *.png; do
						((i=i+1))
						NEWNAME="images/${NUM}-${i}.png"
						cp ${x} ${NEWNAME}
						sed -i -e "s:${x}:${NEWNAME}:g" ${NUM}.html
					done
				fi
			fi
			if [ -f "${NUM}.post" ]; then
				. ${NUM}.post
			fi
			popd >/dev/null
			cp ${TMPDIR}/article.pdf html/articles/${NUM}.pdf
			if [ ${AUTOADD} == true ]; then
				git ls-files --error-unmatch html/articles/${NUM}.pdf > /dev/null 2>&1 || git add html/articles/${NUM}.pdf > /dev/null
			fi
			cp ${TMPDIR}/${NUM}.html html/articles/
			if compgen -G "${TMPDIR}/images/*.svg" > /dev/null; then
				cp ${TMPDIR}/images/*.svg html/articles/images/
			fi
			if compgen -G "${TMPDIR}/images/*.png" > /dev/null; then
				cp ${TMPDIR}/images/*.png html/articles/images/
			fi
			if [ ${AUTOADD} == true ]; then
				git ls-files --error-unmatch html/articles/${NUM}.html >/dev/null 2>&1 || git add html/articles/${NUM}.html > /dev/null
			fi
			if compgen -G "html/articles/images/${NUM}-*.svg" > /dev/null; then
				for x in html/articles/images/${NUM}-*.svg; do
					git ls-files --error-unmatch ${x} >/dev/null 2>&1 || git add ${x} > /dev/null
				done
			fi
			if compgen -G "html/articles/images/${NUM}-*.png" > /dev/null; then
				for x in html/articles/images/${NUM}-*.png; do
					git ls-files --error-unmatch ${x} >/dev/null 2>&1 || git add ${x} > /dev/null
				done
			fi
			echo "OK!"
		else
			echo "Already built!"
		fi
		ARTICLES+=( "${ARTICLENAME}" )
		NUMS+=( "${NUM}" )
		echo "<li>${NUM} - <a href=\"articles/${NUM}.html\">${ARTICLENAME}</a></li>" >> html/articles-full.inc
		echo "<url>" >> html/sitemap.xml
		echo -e "\t<loc>https://www.SwATips.com/articles/${NUM}.html</loc>" >> html/sitemap.xml
		echo -e "\t<lastmod>$(date -Iseconds -r tips/${NUM}.tex)</lastmod>" >> html/sitemap.xml
		echo "</url>" >> html/sitemap.xml
		rm -rf ${TMPDIR}
	done
	echo "</urlset>" >> html/sitemap.xml
	MAXNUMARTICLES=${#ARTICLES[@]}
	for ((i=${MAXNUMARTICLES} - 1; i >= ($MAXNUMARTICLES >= 10 ? ${MAXNUMARTICLES} - 10 : 0); i--)); do
		echo "<li>${NUMS[$i]} - <a href=\"articles/${NUMS[$i]}.html\">${ARTICLES[$i]}</a></li>" >> html/articles.inc
		echo "	<item>" >> html/rss.inc
		echo "		<title>${ARTICLES[$i]}</title>" >> html/rss.inc
		echo "		<link>https://www.SwATips.com/articles/${NUMS[$i]}.html</link>" >> html/rss.inc
		echo "		<pubDate>$(date -R -d "${NUMS[$i]}")</pubDate>" >> html/rss.inc
		echo -n "<description><![CDATA[" >> html/rss.inc
		TMPFILE=html/articles/${NUMS[$i]}.html.tmp
		TMPFILE2=html/articles/${NUMS[$i]}.html.tmp2
		cp html/articles/${NUMS[$i]}.html ${TMPFILE2}
		sed -i -e '/<script/d' ${TMPFILE2}
		juice --remove-style-tags true --xml-mode true ${TMPFILE2} ${TMPFILE}
		xmllint --pretty --format --xpath "//body/node()" ${TMPFILE} | sed -e "s:href=\"${NUMS[$i]}.pdf\":href=\"articles/${NUMS[$i]}.pdf\":g" -e "s:href=\"../\":href=\"/\":g" -e "s:images/:https\://www.swatips.com/articles/images/:g" >> html/rss.inc
		rm ${TMPFILE} ${TMPFILE2}
		echo "]]></description>" >> html/rss.inc
		echo "	</item>" >> html/rss.inc
	done
fi
