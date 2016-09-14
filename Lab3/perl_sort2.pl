#!/usr/bin/perl

use strict;
use warnings;

#print "The file that will be sorted: $ARGV[0]\n";

open(my $INFILE, '<', $ARGV[0]) or die "$!";

print "Below are the words in the file\n";
print <$INFILE>;

open($INFILE, '<', $ARGV[0]) or die "$!";

print "Enter the word you want to search for\n";
my $word = <STDIN>;
chomp($word);

my $match = 0;
my $regex = qr/$word/;
my @lines = <$INFILE>; 

print "the word entered is: $word\n";

foreach (0 .. $#lines)
{
if ($lines[$_] =~ $word)
{
	printf "match found on line %d\n", ($_ + 1);
	$match = 1;
}
}
print "Not found\n" unless $match;


close $INFILE;
