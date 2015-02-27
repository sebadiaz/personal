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
int main(int argc, char **argv)
{
  int nbLineToFollow = -1;
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
  while ((c = getopt (argc, argv, "o:l:b:t:f:")) != -1)
    switch (c)
      {
      case 'l':
        nbLineToFollow = atoi(optarg);
	std::cout << " nb line :" << nbLineToFollow << std::endl;
        break;
      case 'b':
	pch = strtok (optarg,",");
	std::cout << " nb boule :" << optarg << " first:"<<pch<< std::endl;
	while(pch !=NULL){
	  nbBoules.push_back(atoi(pch));
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
	std::cout << " file :" << fichier << std::endl;
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
	std::cout<<"Need -b (nb boules ex:60,10) -t (nb tirage ex:5,2) -f (nom du fichier) -o (output) arguments" <<std::endl;
	exit(0);
      }
  
	std::cout << " start file reading " << argc << std::endl;
  
  MaxMinCounter maxii2("First",nbBoules,true);
  MaxMinCounter maxii3("Second",nbBoules,false);
  std::vector<AbstractStrategy*> list;
  
  
  list.push_back(&maxii3);
  list.push_back(&maxii2);
  
  for(int i=0;i<nbTirages[0]+1;i++){
	for(int j=0;j<nbTirages[1]+1;j++){
	
		std::vector<int> lisy;
		lisy.push_back(i);
		lisy.push_back(j);
		Mixer *maxii4=new Mixer(&maxii2,&maxii3,lisy);
		list.push_back(maxii4);
	}
  }
  
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
		  int column = 0;
		  char * pch;
		  pch = strtok(line, ",");
		  while (pch != NULL&&column<6){
			  if (column != 0){
				  int a=atoi(pch);
				  for (int i=0;i<list.size();i++){
					list[i]->read(0, nbline, column, a);
				  }
				  
			  }
			  column++;
			  pch = strtok(NULL, ",");
		  }
		  while (pch != NULL&&column<7&&column>=6){
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
	  nbline++;
  }
  std::cout << " a = " << nbline << std::endl;
for (int i=0;i<list.size();i++){
  list[i]->calculate();
}
  
    fclose(fp);
    if (line)
	  free(line);
  std::ofstream outfile (outfileName.c_str());
  for (int i=0;i<list.size();i++){
	  std::cout <<"Extract"<<std::endl;
	outfile <<list[i]->getName()<<","<<list[i]->toString(nbTirages)<< std::endl;
  }
  outfile.close();
    return 0;
}
