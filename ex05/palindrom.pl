#!/usr/bin/perl
my $in = "Enter a string :";
print $in;
my $line = <STDIN>;
chop $line;
my $rev = reverse ($line);

if($line eq $rev)
{
	print "The string is a palindrome!\n";
}
else
{
	print "The string is not a palindrome.\n"
}