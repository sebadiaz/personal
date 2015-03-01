#!/usr/bin/perl
use strict;
use warnings;

my $first_name=$ARGV[0];
my $dirname=$first_name;
$dirname=~ s/\..*$//;

opendir(my $dh, $dirname) || die;
    while(readdir $dh) {
		if(-d $dirname."/".$_) { 
			my $dirname2=$dirname."/".$_;
			printf("Read file ".$dirname2."/".$first_name.".res\n");
			if ( open(my $fh, '<', $dirname2."/".$first_name.".res")) {
				while (my $row = <$fh>) {
					my @values = split(',', $row);
					my $first=$values[0];
					my $bbook=$dirname."/".$first.".csv";
					my $nrow=$row;
					$nrow=~ s/$first/$_/;
					open (MYFILE, '>>',$bbook);
					print MYFILE $nrow;
					close MYFILE;
						
				}
			}
			print "$dirname/$_\n";
		}
    }
    closedir $dh;