#include <maxmincounter.h>
#include <Mixer.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include<list>
#include <string.h>
#include <unistd.h>

std::vector<AbstractStrategy*> mix(std::vector<AbstractStrategy*>list1,std::vector<AbstractStrategy*>list2,std::vector<int> nbTirages){
	std::vector<AbstractStrategy*> list;
	std::cout << " nb tirage :" << nbTirages.size() << std::endl;
	for(int ii=0;ii<list1.size();ii++)
		for(int jj=ii;jj<list2.size();jj++)
			for(int i=0;i<nbTirages[0]+1;i++){
				if(nbTirages.size()>1){
					for(int j=0;j<nbTirages[1]+1;j++){
						std::vector<int> lisy;
						lisy.push_back(i);
				
						lisy.push_back(j);
						if(list1[ii]!=list2[jj]){
							Mixer *maxii4=new Mixer(list1[ii],list2[jj],lisy);
							list.push_back(maxii4);
						}
					}
				}else
				if(list1[ii]!=list2[jj]){
					std::vector<int> lisy;
					lisy.push_back(i);
				
					Mixer *maxii4=new Mixer(list1[ii],list2[jj],lisy);
					list.push_back(maxii4);
				}
				
			}
	return list;
}

int main(int argc, char **argv)
{
  int nbLineToFollow = -1;
  int nbtir=1;
  int maximu=-1;
  std::vector<int> nbBoules;
  std::vector<int> nbTirages;
  char* fichier=NULL;
  std::string outfileName;
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;
  char * pch;  
  opterr = 0;
  while ((c = getopt (argc, argv, "o:l:b:t:f:j:")) != -1)
    switch (c)
      {
      case 'l':
        nbLineToFollow = atoi(optarg);
	std::cout << " nb line :" << nbLineToFollow << std::endl;
        break;
      case 'b':
	  std::cout << " nb boule :" << optarg << " first:"<<pch<< std::endl;
	pch = strtok (optarg,",");
	std::cout << " nb boule :" << optarg << " first:"<<pch<< std::endl;
	while(pch !=NULL){
		int nuu=atoi(pch);
		if (maximu<nuu) maximu=nuu;
	  nbBoules.push_back(nuu);
	  pch = strtok (NULL,",");
	  
	}
        break;
      case 't':
  	pch = strtok (optarg,",");
	std::cout << " nb tirage :" << optarg << " first:"<<pch<< std::endl;
	while(pch !=NULL){
	  nbTirages.push_back(atoi(pch));
	  pch = strtok (NULL,",");
	  
	}
        break;
      case 'f':
  	fichier=optarg;
	std::cout << " file :" << fichier << std::endl;
        break;
		case 'o':
  	outfileName=optarg;
	std::cout << " output :" << optarg << std::endl;
        break;
		case 'j':
		nbtir=atoi(optarg);
		std::cout << " tirages :" << optarg << std::endl;
    break;
      case '?':
        if (optopt == 'l' || optopt == 'b' || optopt == 't' || optopt == 'f')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
      if(outfileName.empty()||fichier==NULL||nbBoules.size()==0||nbTirages.size()==0){
	std::cout<<"Need -j tirage -b (nb boules ex:60:10) -t (nb tirage ex:5:2) -f (nom du fichier) -o (output) arguments" <<std::endl;
	exit(0);
      }
  
	std::cout << " start file reading " << argc <<" "<<maximu<< std::endl;
  

  
  std::vector<AbstractStrategy*> list;
  
  
  list.push_back(new MaxMinCounter("TotalMax",nbBoules,false));
  list.push_back(new MaxMinCounter("TotalMin",nbBoules,true));
  list.push_back(new MaxMinCounter("LastMax",nbBoules,false,0,maximu));
  list.push_back(new MaxMinCounter("LastMin",nbBoules,true,0,maximu));
  list.push_back(new MaxMinCounter("MoreLastMax",nbBoules,false,maximu,2*maximu));
  list.push_back(new MaxMinCounter("MoreLastMin",nbBoules,true,maximu,2*maximu));
  
  std::vector<AbstractStrategy*> list2=mix(list,list,nbTirages);
  //std::vector<AbstractStrategy*> list3=mix(list2,list,nbTirages);
  std::vector<AbstractStrategy*> list4=mix(list2,list2,nbTirages);
  //std::vector<AbstractStrategy*> list5=mix(list3,list,nbTirages);
  //std::vector<AbstractStrategy*> list6=mix(list3,list2,nbTirages);
  //std::vector<AbstractStrategy*> list7=mix(list4,list4,nbTirages);
  std::vector<AbstractStrategy*> finale;
  finale.insert(finale.end(), list.begin(), list.end());
  finale.insert(finale.end(), list2.begin(), list2.end());
  //finale.insert(finale.end(), list3.begin(), list3.end());
  //finale.insert(finale.end(), list4.begin(), list4.end());
  //finale.insert(finale.end(), list5.begin(), list5.end());
  //finale.insert(finale.end(), list6.begin(), list6.end());
  //finale.insert(finale.end(), list7.begin(), list7.end());
  list=finale;
  std::cout << " max " << finale.size() << std::endl;
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbline = 0;
  int startline = 1;

  fp = fopen(fichier, "r");
  if (fp == NULL){
    std::cout <<"Error, file:"<<fichier<< " unknown."<<std::endl; 
    exit(EXIT_FAILURE);
  }
  std::cout <<"Read file:"<<fichier<<std::endl; 
  while ((read = getline(&line, &len, fp)) != -1&&(nbline<nbLineToFollow||nbLineToFollow==-1)) {
	  if (nbline >= startline){
		  std::cout << "."<<std::flush;
		  int column = 0;
		  char * pch;
		  pch = strtok(line, ",");
		  int nb1=nbTirages[0];
		  while (pch != NULL&&column<nb1+1){
			  if (column != 0){
				  int a=atoi(pch);
				  for (int i=0;i<list.size();i++){
					list[i]->read(0, nbline, column, a);
				  }
				  
			  }
			  column++;
			  pch = strtok(NULL, ",");
		  }
		  if(nbTirages.size()>0){
				int nb2=nbTirages[1];
		  
			  while (pch != NULL&&column<nb1+1+nb2&&column>=nb1+1){
				  if (column != 0){
					  int a=atoi(pch);
					  for (int i=0;i<list.size();i++){
						list[i]->read(1, nbline, column, a);
					  }
					  
				  }
				  column++;
				  pch = strtok(NULL, ",");
			  }
		  }
	  }
	  nbline++;
  }
  std::cout << std::endl<<" a = " << nbline << std::endl;
for (int i=0;i<list.size();i++){
  list[i]->calculate();
}
  
    fclose(fp);
    if (line)
	  free(line);
  std::ofstream outfile (outfileName.c_str());
  std::cout <<"Extracting to "<<outfileName<<std::endl;
  for (int k=0;k<nbtir;k++)
  for (int i=0;i<list.size();i++){
	  std::cout << "."<<std::flush;
	outfile <<list[i]->getName()<<"-T"<<k<<","<<list[i]->toString(nbTirages,k)<< std::endl;
  }
  outfile.close();
  std::cout <<std::endl<<"Finish"<<std::endl;
    return 0;
}
