#!/bin/bash

echo "<ul>" > html/articles.inc
for x in tips/*.tex; do
	TMPDIR=$(mktemp -d)
	NUM=${x/tips\//}
	NUM=${NUM/\.tex/}
	ARTICLENAME="UNKNOWN"
	cp ${x} ${TMPDIR}/
	if [ -f "tips/${NUM}.bib" ]; then
		cp "tips/${NUM}.bib" ${TMPDIR}/
	fi
	if [ -f "tips/${NUM}.pre" ]; then
		cp "tips/${NUM}.pre" ${TMPDIR}/
		ARTICLENAME=$(grep ArticleName ${TMPDIR}/${NUM}.pre | sed -e 's:\\def \\ArticleName{::g' -e 's:}::g')
	fi
	cp templates/sources.bib templates/article.tex ${TMPDIR}/
	cp templates/article.html ${TMPDIR}/article_template.html
	pushd ${TMPDIR}
	sed -i -e "s:NUM:${NUM}:g" article.tex
	sed -i -e "s:NUM:${NUM}:g" article_template.html
	latexmk -e '$biber='"'"'biber --isbn-normalise %O %S'"'" -pdflatex=lualatex -pdf article
	make4ht -l article
	head -n 11 article.html > ${NUM}.html
	cat article_template.html >> ${NUM}.html
	tail -n +12 article.html >> ${NUM}.html
	popd
	cp ${TMPDIR}/article.pdf html/articles/${NUM}.pdf
	git ls-files --error-unmatch html/articles/${NUM}.pdf || git add html/articles/${NUM}.pdf
	cp ${TMPDIR}/${NUM}.html html/articles/
	git ls-files --error-unmatch html/articles/${NUM}.html || git add html/articles/${NUM}.html
	echo "<li>${NUM} - <a href=\"articles/${NUM}.html\">${ARTICLENAME}</a></li>" >> html/articles.inc
	rm -rf ${TMPDIR}
done

echo "</ul>" >> html/articles.inc
