#!/usr/bin/perl

use warnings;
my %inFilesToCopy=();
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
					$inFilesToCopy{$bbook} = 1;
					open (MYFILE, '>>',$bbook);
					print MYFILE $nrow;
					close MYFILE;
						
				}
			}
			print "$dirname/$_\n";
		}
    }
    closedir $dh;
my %dateresult=();
open(my $fh, '<',$first_name); 
while ( $row = <$fh>) {
	my @values = split(',', $row);
	my $first=$values[0];
	$first=~ s/\//-/g;
	print $first . " ".$row;
	$dateresult{$first} = $row;
}	
close ($fh);
foreach  $k (keys(%inFilesToCopy)) {
	open( $fh, '<',$k);
	open (MYFILE, '>',$k.".cop");
	while (my $row = <$fh>) {
		my @values = split(',', $row);
		my $first=$values[0];
		my $cleaned=$row;
		$cleaned=~ s/\n//;
		print $first . " \n";
		#print $cleaned . " ";
		#print $dateresult{$first} . " \n";
		if($dateresult{$first}){
			print MYFILE $cleaned.$dateresult{$first};
		}else{
			print MYFILE $row;	
		}
	}	
	close MYFILE;
	unlink($k);
	rename($k.".cop",$k);
}