#!/usr/bin/perl
use strict;
use warnings;


open(INFILE,$ARGV[0]) or die "$!";

print sort { "\L$a" cmp "\L$b"} <INFILE>;


close INFILE;
