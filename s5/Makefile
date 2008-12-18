RSTOPTS=--strict --language=fr
RSTHTMLOPTS=--embed-stylesheet --stylesheet-path=lsr.css

SOURCES=asr.rst plc.rst plctp.rst xmltp.rst
HTML=$(foreach t,$(filter %.rst,$(SOURCES)),$(basename $(t)).html)
PDF=$(foreach t,$(filter %.rst,$(SOURCES)),$(basename $(t)).pdf)
TMPS=$(foreach t,$(filter %.rst,$(SOURCES)),$(basename $(t)).txt.tmp)

COMMIT_DATE=$(shell git-show | grep ^Date | sed "s/^Date: *//")
COMMIT_REV=$(shell git-show | grep ^commit | sed "s/^commit *//")

default: html

%.rst.tmp: %.rst
	@sed -e "s/@DATE@/$(COMMIT_DATE)/" -e "s/@REV@/$(COMMIT_REV)/" $^ > $@

%.html: %.rst.tmp
	rst2html.py $(RSTOPTS) $(RSTHTMLOPTS) $^ > $@

%.pdf: %.rst.tmp
	rst2latex.py $(RSTOPTS) $^ > $(basename $@).tex
	pdflatex $(basename $@).tex
	rm -f $(basename $@).log $(basename $@).out $(basename $@).tex $(basename $@).aux

html: $(HTML)
pdf: $(PDF)

all: html pdf

clean:
	rm -f $(HTML)
	rm -f $(PDF)
	rm -f $(TMPS)
