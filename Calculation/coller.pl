#!/usr/bin/perl
use strict;
use warnings;

my $first_name=$ARGV[0];
my $dirname=$first_name;
$dirname=~ s/\..*$//;

if (!-d $dirname) { 
	printf("Create directory ".$dirname."\n");
	mkdir($dirname)  ; 
}
my $ligne ="";
my $ligne2 ="";
open SORTIE, "md5sum ".$first_name." |";
$ligne = <SORTIE>;
close SORTIE;
open SORTIE, "md5sum ".$dirname."/".$first_name." |";
$ligne2 = <SORTIE>;
close SORTIE;
$ligne=~ s/ .*$//;
$ligne2=~ s/ .*$//;
$ligne=~ s/\n//;
$ligne2=~ s/\n//;
print ("Hash =".$ligne." ".$ligne2."\n");
if(!$ligne == $ligne2)  {
	printf("Copy ".$first_name." to ".$dirname."/".$first_name."\n");
	open SORTIE, "cp ".$first_name." ".$dirname."/".$first_name." |";
	close SORTIE;
}else{
	printf("Nothing todo\n");
	exit(0);
}
printf ("bin/calculator.exe -b ".$ARGV[1].",".$ARGV[2]." -t ".$ARGV[3].",".$ARGV[4]." -f ".$dirname."/".$first_name." -o ".$dirname."/".$first_name.".res -j 5 |\n");
open SORTIE, "bin/calculator.exe -b ".$ARGV[1].",".$ARGV[2]." -t ".$ARGV[3].",".$ARGV[4]." -f ".$dirname."/".$first_name." -o ".$dirname."/".$first_name.".res -j 5 |";
while (my $row = <SORTIE>) {
    print "$row\n";
  }
close SORTIE;
