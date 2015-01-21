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

`unzip euromillions_3.zip`;
`unzip euromillions_2.zip`;
`unzip euromillions.zip`;
`unzip nouveau_loto.zip`;
`unzip nouveau_superloto.zip`;
`unzip keno.zip`;
`unzip keno_gagnant_a_vie.zip`;