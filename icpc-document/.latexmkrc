#!/usr/bin/env perl

# platex
$latex = 'platex --shell-escape -synctex=1 -halt-on-error';
# platex less-error-message
$latex_silent = 'platex -shell-escape -synctex=1 -halt-on-error -interaction=batchmode';

$bibtex = 'pbibtex';
$dvipdf = 'dvipdfmx %O -o %D %S';
$makeindex = 'mendex %O -o %D %S';
$max_repeat = 4;
$pdf_mode = 3;
$pdf_update_method = 4;