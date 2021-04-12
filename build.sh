#!/bin/bash

# Action Variables
CLEAN=true
EPUB=true
PDF=true
HTML=true
REBUILD=false

# Dependency Variables
BIBER=1
GIT=1
KPSEWHICH=1
LATEXMK=1
LUALATEX=1
LUAOTFLOAD=1

# Latex Package Dependencies
SCANNEDPACKAGES=()

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
	for x in `grep '^\\\\usepackage\|^\\\\RequirePackage' ${1}.tex | sed -e 's:^.*{\(.*\)}$:\1:g'`; do
		scanHeader "${x}"
	done
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
	check "$GIT" "git" "GIT"
	GIT=$?

	echo "<ul>" > html/articles.inc
	for x in tips/*.tex; do
		TMPDIR=$(mktemp -d)
		NUM=${x/tips\//}
		NUM=${NUM/\.tex/}
		echo -n "Building ${NUM}..."
		ARTICLENAME="UNKNOWN"
		cp templates/article.tex templates/sources.bib ${TMPDIR}/
		cp templates/article.html ${TMPDIR}/article_template.html
		cp tips/${NUM}.* ${TMPDIR}/
		ARTICLENAME=$(grep ArticleName ${TMPDIR}/${NUM}.pre | sed -e 's:\\def \\ArticleName{::g' -e 's:}::g')
		if [ ! -f "html/articles/${NUM}.pdf" ] || [ $REBUILD == true ]; then
			pushd ${TMPDIR} > /dev/null
			sed -i -e "s:NUM:${NUM}:g" article.tex
			sed -i -e "s:NUM:${NUM}:g" article_template.html
			lmk article >/dev/null 2>&1
			if [ $HTML == true ]; then
				make4ht -l article > /dev/null
				head -n 11 article.html > ${NUM}.html
				cat article_template.html >> ${NUM}.html
				tail -n +12 article.html >> ${NUM}.html
				sed -i -z "s|<title>.*</title>|<title>${ARTICLENAME}</title>|g" ${NUM}.html
			fi
			popd >/dev/null
			cp ${TMPDIR}/article.pdf html/articles/${NUM}.pdf
			git ls-files --error-unmatch html/articles/${NUM}.pdf > /dev/null || git add html/articles/${NUM}.pdf > /dev/null
			cp ${TMPDIR}/${NUM}.html html/articles/
			git ls-files --error-unmatch html/articles/${NUM}.html >/dev/null || git add html/articles/${NUM}.html > /dev/null
		fi
		echo "<li>${NUM} - <a href=\"articles/${NUM}.html\">${ARTICLENAME}</a></li>" >> html/articles.inc
		rm -rf ${TMPDIR}
	done
	echo "OK!"
	echo "</ul>" >> html/articles.inc
fi