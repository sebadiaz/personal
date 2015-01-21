


calculateStats <- function(counterBoule, tirage ,boule_1 ,annee_numero_de_tirage ){
		counterBoule[boule_1,]$value= boule_1
		if (is.null(counterBoule[boule_1,]$date)||is.na(counterBoule[boule_1,]$date) ) {
			counterBoule[boule_1,]$date=selectBoule[tirage,]$annee_numero_de_tirage
		}
		counterBoule[boule_1,]$counterTotal<-counterBoule[boule_1,]$counterTotal+1
		if (tirage<50) 
		counterBoule[boule_1,]$counterTotal50<-counterBoule[boule_1,]$counterTotal50+1
		if (tirage<100) 
		counterBoule[boule_1,]$counterTotal100<-counterBoule[boule_1,]$counterTotal100+1
		if (tirage<150)
		counterBoule[boule_1,]$counterTotal150<-counterBoule[boule_1,]$counterTotal150+1
		if (tirage<200)
		counterBoule[boule_1,]$counterTotal200<-counterBoule[boule_1,]$counterTotal200+1
		if (tirage<250)
		counterBoule[boule_1,]$counterTotal250<-counterBoule[boule_1,]$counterTotal250+1

		return(counterBoule)
}

calculateAllStats <- function( selectBoule ,nbBoule ,nbCol,tirageDate,tirageOth){
	counterBoule<-data.frame(matrix(NA, nrow = nbBoule, ncol = 0))
	counterBoule[,"value"]=0
	counterBoule[,"date"]=NA
	counterBoule[,"counterTotal"]=0
	counterBoule[,"counterTotal50"]=0
	counterBoule[,"counterTotal100"]=0
	counterBoule[,"counterTotal150"]=0
	counterBoule[,"counterTotal200"]=0
	counterBoule[,"counterTotal250"]=0
	for ( tirage in 1: nrow(selectBoule) ){
		for ( coln in 1: nbCol )
		{
			counterBoule =calculateStats(counterBoule, tirage ,selectBoule[tirage, coln+1],selectBoule[tirage,]$annee_numero_de_tirage)
		}

	}

	index <- with(counterBoule,order(date,decreasing=FALSE))
	counterBouledate <-counterBoule[index,]
	index <- with(counterBoule,order(counterTotal,decreasing=FALSE))
	counterBouleTotal <-counterBoule[index,]
	index <- with(counterBoule,order(counterTotal50,decreasing=FALSE))
	counterBouleTotal50 <-counterBoule[index,]
	index <- with(counterBoule,order(counterTotal100,decreasing=FALSE))
	counterBouleTotal100 <-counterBoule[index,]
	index <- with(counterBoule,order(counterTotal150,decreasing=FALSE))
	counterBouleTotal150 <-counterBoule[index,]

	index <- with(counterBoule,order(counterTotal200,decreasing=FALSE))
	counterBouleTotal200 <-counterBoule[index,]

	index <- with(counterBoule,order(counterTotal250,decreasing=FALSE))
	counterBouleTotal250 <-counterBoule[index,]


	index <- with(counterBoule,order(counterTotal,decreasing=TRUE))
	counterBouleTotalM <-counterBoule[index,]
	index <- with(counterBoule,order(counterTotal50,decreasing= TRUE))
	counterBouleTotal50M <-counterBoule[index,]
	index <- with(counterBoule,order(counterTotal100,decreasing= TRUE))
	counterBouleTotal100M <-counterBoule[index,]
	index <- with(counterBoule,order(counterTotal150,decreasing= TRUE))
	counterBouleTotal150M <-counterBoule[index,]

	index <- with(counterBoule,order(counterTotal200,decreasing= TRUE))
	counterBouleTotal200M <-counterBoule[index,]

	index <- with(counterBoule,order(counterTotal250,decreasing= TRUE))
	counterBouleTotal250M <-counterBoule[index,]

	counterBouledate[1: tirageDate,"value"]
	counterBouleTotal[1: tirageOth,"value"]
	counterBouleTotal50[1: tirageOth,"value"]
	counterBouleTotal100[1: tirageOth,"value"]
	counterBouleTotal150[1: tirageOth,"value"]
	counterBouleTotal200[1: tirageOth,"value"]
	counterBouleTotal250[1: tirageOth,"value"]
	counterBouleTotalM[1: tirageOth,"value"]
	counterBouleTotal50M[1: tirageOth,"value"]
	counterBouleTotal100M[1: tirageOth,"value"]
	counterBouleTotal150M[1: tirageOth,"value"]
	counterBouleTotal200M[1: tirageOth,"value"]
	counterBouleTotal250M[1: tirageOth,"value"]
	regroup<-list(intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal50[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal100[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal150[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal200[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotalM[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal50M[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal100M[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal150M[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal200M[1: tirageOth,"value"]),
	intersect(counterBouledate[1: tirageDate,"value"], counterBouleTotal250M[1: tirageOth,"value"]))
	lastList<-unlist(regroup)
	return (lastList[!duplicated(lastList)])


}


#Euromillion
download.file("https://media.fdj.fr/generated/game/euromillions/euromillions_3.zip",method="curl",destfile="tempo.zip")
datanew <- read.csv(unz("tempo.zip", "euromillions_3.csv"),sep=";")
download.file("https://media.fdj.fr/generated/game/euromillions/euromillions_2.zip",method="curl",destfile="tempo.zip")
dataold <- read.csv(unz("tempo.zip", "euromillions_2.csv"),sep=";")
download.file("https://media.fdj.fr/generated/game/euromillions/euromillions.zip",method="curl",destfile="tempo.zip")
dataveryold <- read.csv(unz("tempo.zip", "euromillions.csv"),sep=";")

summary(dataveryold[,c("boule_1","boule_2","boule_3","boule_4","boule_5","etoile_1","etoile_2")])
summary(dataold[,c("boule_1","boule_2","boule_3","boule_4","boule_5","etoile_1","etoile_2")])
summary(datanew[,c("boule_1","boule_2","boule_3","boule_4","boule_5","etoile_1","etoile_2")])

selectBoule<-rbind(dataveryold[,c("annee_numero_de_tirage","boule_1","boule_2","boule_3","boule_4","boule_5")],dataold[,c("annee_numero_de_tirage","boule_1","boule_2","boule_3","boule_4","boule_5")],datanew[,c("annee_numero_de_tirage","boule_1","boule_2","boule_3","boule_4","boule_5")])
selectEtoile<-rbind(dataold[,c("annee_numero_de_tirage","etoile_1","etoile_2")],datanew[,c("annee_numero_de_tirage","etoile_1","etoile_2")])

index <- with(selectBoule, order(annee_numero_de_tirage,decreasing=TRUE))
selectBoule <-selectBoule[index,]

index <- with(selectEtoile,order(annee_numero_de_tirage,decreasing=TRUE))
selectEtoile <-selectEtoile[index,]

#loto

download.file("https://media.fdj.fr/generated/game/loto/nouveau_loto.zip",method="curl",destfile="tempo.zip")
datanew <- read.csv(unz("tempo.zip", "nouveau_loto.csv"),sep=";")

summary(datanew)

selectBouleLoto<-(datanew[,c("annee_numero_de_tirage","boule_1","boule_2","boule_3","boule_4","boule_5")])
selectChanceLoto<-(datanew[,c("annee_numero_de_tirage","numero_chance")])

index <- with(selectBouleLoto, order(annee_numero_de_tirage,decreasing=TRUE))
selectBouleLoto <-selectBouleLoto[index,]

index <- with(selectChanceLoto,order(annee_numero_de_tirage,decreasing=TRUE))
selectChanceLoto <-selectChanceLoto[index,]

#superloto
download.file("https://media.fdj.fr/generated/game/loto/nouveau_superloto.zip",method="curl",destfile="tempo.zip")
datanew <- read.csv(unz("tempo.zip", "nouveau_superloto.csv"),sep=";")

summary(datanew)

selectBouleSuperLoto<-(datanew[,c("annee_numero_de_tirage","boule_1","boule_2","boule_3","boule_4","boule_5")])
selectChanceSuperLoto<-(datanew[,c("annee_numero_de_tirage","numero_chance")])

index <- with(selectBouleSuperLoto, order(annee_numero_de_tirage,decreasing=TRUE))
selectBouleSuperLoto <-selectBouleSuperLoto[index,]

index <- with(selectChanceSuperLoto,order(annee_numero_de_tirage,decreasing=TRUE))
selectChanceSuperLoto <-selectChanceSuperLoto[index,]


#Keno
download.file("https://media.fdj.fr/generated/game/keno/keno.zip",method="curl",destfile="tempo.zip")
dataold <- read.csv(unz("tempo.zip", "keno.csv"),sep=";")
download.file("https://media.fdj.fr/generated/game/keno/keno_gagnant_a_vie.zip",method="curl",destfile="tempo.zip")
datanew <- read.csv(unz("tempo.zip", "keno_gagnant_a_vie.csv"),sep=";")

selectBouleKeno<-rbind(datanew[,c("annee_numero_de_tirage","boule1","boule2","boule3","boule4","boule5","boule6","boule7","boule8","boule9","boule10","boule11","boule12","boule13","boule14","boule15","boule16","boule17","boule18","boule19","boule20")],dataold[,c("annee_numero_de_tirage","boule1","boule2","boule3","boule4","boule5","boule6","boule7","boule8","boule9","boule10","boule11","boule12","boule13","boule14","boule15","boule16","boule17","boule18","boule19","boule20")]

)
index <- with(selectBouleKeno, order(annee_numero_de_tirage,decreasing=TRUE))
selectBouleKeno <-selectBouleKeno[index,]

euromillion<-list(calculateAllStats(selectBoule,50,5,12,10),
calculateAllStats(selectEtoile,11,2,4,3))
loto<-list(calculateAllStats(selectBouleLoto,49,5,13,10),
calculateAllStats(selectChanceLoto,10,1,3,3))
superLoto<-list(calculateAllStats(selectBouleSuperLoto,49,5,15,15),
calculateAllStats(selectChanceSuperLoto,10,1,3,3))
keno<-(calculateAllStats(selectBouleKeno,70,20,20,20))

print(paste("euromillion:", euromillion))
print(paste("loto:",loto))
print(paste("superLoto:", superLoto))
print(paste("keno:", keno))

dump(euromillion, file = "euromillion.last",
      append = FALSE)
dump(loto, file = "loto.last",
            append = FALSE)
dump( superLoto, file = "superLoto.last",
            append = FALSE)
dump(keno, file = "keno.last",
            append = FALSE)





