#!/usr/bin/perl
`rm *.zip`;
`rm *.csv`;
`wget --secure-protocol=SSLv3 https://media.fdj.fr/generated/game/euromillions/euromillions_3.zip`;
`wget --secure-protocol=SSLv3 https://media.fdj.fr/generated/game/euromillions/euromillions_2.zip`;
`wget --secure-protocol=SSLv3 https://media.fdj.fr/generated/game/euromillions/euromillions.zip`;
`wget --secure-protocol=SSLv3 https://media.fdj.fr/generated/game/loto/nouveau_loto.zip`;
`wget --secure-protocol=SSLv3 https://media.fdj.fr/generated/game/loto/nouveau_superloto.zip`;
`wget --secure-protocol=SSLv3 https://media.fdj.fr/generated/game/keno/keno.zip`;
`wget --secure-protocol=SSLv3 https://media.fdj.fr/generated/game/keno/keno_gagnant_a_vie.zip`;

`wget http://www.playusalotteries.com/en/winnings/download/lottery/5.html`;
`wget http://www.powerball.com/powerball/winnums-text.txt`;
open FILE, "<winnums-text.txt" or die $!;
open FILEOUT, ">winnums-text.csv" or die $!;
print FILEOUT $str;
while (<FILE>) {
	$str=$_;
	$str =~ s/  /,/g;
	$str =~ s/ /,/g;
	print FILEOUT $str;
}
close FILEOUT;
close fILE;

`mv 5.html usa_lottery.csv`;

`unzip euromillions_3.zip`;
`unzip euromillions_2.zip`;
`unzip euromillions.zip`;
`unzip nouveau_loto.zip`;
`unzip nouveau_superloto.zip`;
`unzip keno.zip`;
`unzip keno_gagnant_a_vie.zip`;
