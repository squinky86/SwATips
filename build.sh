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
LATEXMK=1
LUALATEX=1
LUAOTFLOAD=1
JUICE=1

# Article List
ARTICLES=()
NUMS=()

if [ -f "build.sh.cache" ]; then
	. build.sh.cache
fi

function check() {
	if [ $1 -gt 0 ]; then
		echo -n "Checking for $2..."
		if ! command -v $2 > /dev/null 2>&1; then
			echo "Please install $2."
			exit 1
		fi
		echo "OK!"
		if [ -n "${3}" ]; then
			echo "${3}=0" >> build.sh.cache
		fi
	fi
	return 0
}

function lmk() {
	latexmk -quiet -e '$biber='"'"'biber --isbn-normalise %O %S'"'" -pdflatex=lualatex -pdf $1
}

function build_article() {
	local NUM=$1
	local TMPDIR=$(mktemp -d)
	local ARTICLENAME="UNKNOWN"
	cp templates/article.tex templates/sources.bib templates/listings-rust.sty ${TMPDIR}/
	cp templates/article.html ${TMPDIR}/article_template.html
	cp tips/${NUM}.* ${TMPDIR}/
	ARTICLENAME=$(grep ArticleName ${TMPDIR}/${NUM}.pre | sed -e 's:\\sout{\([^}]*\)}:<del>\1</del>:g' | sed -e 's:\\def \\ArticleName{::g' -e 's:}::g' -e 's:\\::g')
	echo "${ARTICLENAME}" > html/articles/${NUM}.meta
	if [ ! -f "html/articles/${NUM}.pdf" ] || [ $REBUILD == true ]; then
		pushd ${TMPDIR} > /dev/null
		sed -i -e "s:NUM:${NUM}:g" article.tex
		sed -i -e "s:NUM:${NUM}:g" article_template.html
		lmk article >/dev/null 2>&1
		if [ $HTML == true ]; then
			make4ht -l article "fn-in,svg" >/dev/null 2>&1
			if [ ! -f article.html ] || [ ! -f article.css ]; then
				echo "Error: make4ht failed to generate article.html or article.css for ${NUM}"
				popd >/dev/null
				rm -rf ${TMPDIR}
				return 1
			fi
			cat <<-HTMLHEAD > ${NUM}.html
			<!DOCTYPE html>
			<html xml:lang='en-US' lang='en-US'>
			<head>
			<meta charset="utf-8">
			<meta name="viewport" content="width=device-width, initial-scale=1.0">
			<title>${ARTICLENAME}</title>
			<link rel="stylesheet" href="../styles.css">
			<script async="async" src="https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client=ca-pub-4110907817782130" crossorigin="anonymous"></script>
			<style>
			HTMLHEAD
			cat article.css >> ${NUM}.html
			cat <<-HTMLBODY >> ${NUM}.html
			</style>
			</head>
			<body>
			<div class="container">
			<article>
			HTMLBODY
			cat article_template.html >> ${NUM}.html
			sed -n '/<body/,/<\/body>/p' article.html | sed -e '1d;$d' >> ${NUM}.html
			cat <<-HTMLFOOT >> ${NUM}.html
			</article>
			<footer>
			<p>&copy; 2021-2026 Software Assurance Tips. Some rights reserved. Please see the terms of the Creative Commons Attribution license.</p>
			</footer>
			</div>
			HTMLFOOT
			#copy images
			mkdir images
			local i=0
			for ext in svg png; do
				if compgen -G "*.${ext}" > /dev/null; then
					for x in *.${ext}; do
						if [ "${ext}" = "svg" ] && [ -f "${x/.svg/.png}" ]; then
							rm ${x/.svg/.png}
						fi
						((i=i+1))
						local NEWNAME="images/${NUM}-${i}.${ext}"
						cp ${x} ${NEWNAME}
						sed -i -e "s:${x}:${NEWNAME}:g" ${NUM}.html
					done
				fi
			done
		fi
		if [ -f "${NUM}.post" ]; then
			. ${NUM}.post
		fi
		popd >/dev/null
		cp ${TMPDIR}/article.pdf html/articles/${NUM}.pdf
		if [ ${AUTOADD} == true ]; then
			git ls-files --error-unmatch html/articles/${NUM}.pdf > /dev/null 2>&1 || git add html/articles/${NUM}.pdf > /dev/null
		fi
		if [ $HTML == true ]; then
			cp ${TMPDIR}/${NUM}.html html/articles/
			for ext in svg png; do
				if compgen -G "${TMPDIR}/images/*.${ext}" > /dev/null; then
					cp ${TMPDIR}/images/*.${ext} html/articles/images/
				fi
			done
			if [ ${AUTOADD} == true ]; then
				git ls-files --error-unmatch html/articles/${NUM}.html >/dev/null 2>&1 || git add html/articles/${NUM}.html > /dev/null
				for ext in svg png; do
					if compgen -G "html/articles/images/${NUM}-*.${ext}" > /dev/null; then
						for x in html/articles/images/${NUM}-*.${ext}; do
							git ls-files --error-unmatch ${x} >/dev/null 2>&1 || git add ${x} > /dev/null
						done
					fi
				done
			fi
		fi
		echo "Built ${NUM}."
	else
		echo "Already built ${NUM}."
	fi
	rm -rf ${TMPDIR}
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
	cat <<-SITEMAP > html/sitemap.xml
	<?xml version="1.0" encoding="UTF-8"?>
	<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
	<url>
		<loc>https://www.SwATips.com/</loc>
		<lastmod>$(date -Iseconds)</lastmod>
	</url>
	<url>
		<loc>https://www.SwATips.com/articles.php</loc>
		<lastmod>$(date -Iseconds)</lastmod>
	</url>
	SITEMAP
	# Phase 1: Build articles in parallel
	MAXJOBS=$(nproc)
	JOBCOUNT=0
	for x in tips/*.tex; do
		NUM=${x/tips\//}
		NUM=${NUM/\.tex/}
		build_article "${NUM}" &
		((JOBCOUNT=JOBCOUNT+1))
		if [ $JOBCOUNT -ge $MAXJOBS ]; then
			wait -n
			((JOBCOUNT=JOBCOUNT-1))
		fi
	done
	wait

	# Phase 2: Collect metadata sequentially
	for x in tips/*.tex; do
		NUM=${x/tips\//}
		NUM=${NUM/\.tex/}
		if [ -f "html/articles/${NUM}.meta" ]; then
			ARTICLENAME=$(cat html/articles/${NUM}.meta)
			rm html/articles/${NUM}.meta
		else
			ARTICLENAME="UNKNOWN"
		fi
		ARTICLES+=( "${ARTICLENAME}" )
		NUMS+=( "${NUM}" )
		echo "<li>${NUM} - <a href=\"articles/${NUM}.html\">${ARTICLENAME}</a></li>" >> html/articles-full.inc
		cat <<-SITEMAPENTRY >> html/sitemap.xml
		<url>
			<loc>https://www.SwATips.com/articles/${NUM}.html</loc>
			<lastmod>$(date -Iseconds -r tips/${NUM}.tex)</lastmod>
		</url>
		SITEMAPENTRY
	done
	echo "</urlset>" >> html/sitemap.xml
	MAXNUMARTICLES=${#ARTICLES[@]}
	for ((i=${MAXNUMARTICLES} - 1; i >= ($MAXNUMARTICLES >= 10 ? ${MAXNUMARTICLES} - 10 : 0); i--)); do
		echo "<li>${NUMS[$i]} - <a href=\"articles/${NUMS[$i]}.html\">${ARTICLES[$i]}</a></li>" >> html/articles.inc
		TMPFILE=html/articles/${NUMS[$i]}.html.tmp
		TMPFILE2=html/articles/${NUMS[$i]}.html.tmp2
		cp html/articles/${NUMS[$i]}.html ${TMPFILE2}
		sed -i -e '/<script/d' -e '/<style/,/<\/style>/d' ${TMPFILE2}
		juice --remove-style-tags true ${TMPFILE2} ${TMPFILE} 2>/dev/null || cp ${TMPFILE2} ${TMPFILE}
		RSS_BODY=$(sed -n '/<article/,/<\/article>/p' ${TMPFILE} | sed -e '1d;$d' -e "s:href=\"${NUMS[$i]}.pdf\":href=\"articles/${NUMS[$i]}.pdf\":g" -e "s:href=\"../\":href=\"/\":g" -e "s:images/:https\://www.swatips.com/articles/images/:g")
		rm ${TMPFILE} ${TMPFILE2}
		cat <<-RSSITEM >> html/rss.inc
			<item>
				<title>${ARTICLES[$i]}</title>
				<link>https://www.SwATips.com/articles/${NUMS[$i]}.html</link>
				<pubDate>$(date -R -d "${NUMS[$i]}")</pubDate>
				<description><![CDATA[${RSS_BODY}]]></description>
			</item>
		RSSITEM
	done
fi
