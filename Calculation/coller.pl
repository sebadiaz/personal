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
printf ("bin/calculator.exe -b ".$ARGV[1].",".$ARGV[2]." -t ".$ARGV[3].",".$ARGV[4]." -f ".$dirname."/".$first_name." -o ".$dirname."/".$first_name.".res -j ".$ARGV[5]." |\n");
open SORTIE, "bin/calculator.exe -b ".$ARGV[1].",".$ARGV[2]." -t ".$ARGV[3].",".$ARGV[4]." -f ".$dirname."/".$first_name." -o ".$dirname."/".$first_name.".res -j ".$ARGV[5]." |";
while (my $row = <SORTIE>) {
    print "$row\n";
  }
close SORTIE;
	if (open(my $fh, '<', $dirname."/".$first_name)) {
  while (my $row = <$fh>) {
  my @values = split(',', $row);
	my $first=$values[0];
	my $original=$values[0];
	$first=~ s/\//-/g;
    #print $first."\n";
	if (!-d $dirname."/".$first) {
		printf("Create directory ".$dirname."/".$first."\n");
		mkdir($dirname."/".$first)  ; 
		if (open(my $fh2, '<', $dirname."/".$first_name)) {
			printf("Create  $dirname/$first/$first_name\n");
			my $bbook=$dirname."/".$first."/".$first_name;
			open (MYFILE, '>',$bbook);
			my $counter=0;
			my $write=0;
			my $nextLine=0;
			while (my $row2 = <$fh2>) {
				if($counter>0)
				{
					if($write>0)
					{
						print MYFILE $row2;
					}
					else{
						if($nextLine==1){
							print MYFILE $row2;
							$write=$write+1;
							$nextLine+0;
						}
						if($row2 =~ /$original/)
						{
							$nextLine=1;
							
						}
						
						
					}
				}
				else{
					printf("h=$row2\n");
					print MYFILE $row2;
					$counter=$counter+1;
				}
			}
			close MYFILE;
			printf ("bin/calculator.exe -b ".$ARGV[1].",".$ARGV[2]." -t ".$ARGV[3].",".$ARGV[4]." -f ".$bbook." -o ".$bbook.".res -j ".$ARGV[5]." |\n");
			open SORTIE, "bin/calculator.exe -b ".$ARGV[1].",".$ARGV[2]." -t ".$ARGV[3].",".$ARGV[4]." -f ".$bbook." -o ".$bbook.".res -j ".$ARGV[5]." |";
			while (my $row = <SORTIE>) {
				#print "$row\n";
			  }
			close SORTIE;
		}
	}
  }
}
