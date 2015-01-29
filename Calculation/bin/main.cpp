#include <maxmincounter.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include<list>
#include <string.h>
int main(int argc, char **argv)
{
	std::cout << " start" << argc << std::endl;
  std::vector<int> list;
  list.push_back(60);
  list.push_back(60);
  MaxMinCounter maxii(list);

  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbline = 0;
  int startline = 1;

  fp = fopen("euromillions.csv", "r");
  if (fp == NULL)
	  exit(EXIT_FAILURE);
  while ((read = getline(&line, &len, fp)) != -1) {
	  if (nbline >= startline){
		  int column = 0;
		  char * pch;
		  pch = strtok(line, ",");
		  while (pch != NULL){
			  if (column != 0){
				  int a=atoi(pch);
				  maxii.read(0, nbline, column, a);
				  
			  }
			  column++;
			  pch = strtok(NULL, ",");
		  }
	  }
	  printf("Retrieved line of length %zu :\n", read);
	  printf("%s", line);
	  nbline++;
  }
  std::cout << " a = " << nbline << std::endl;

  fclose(fp);
  if (line)
	  free(line);
  /*exit(EXIT_SUCCESS);
  std::ifstream infile;
  infile.open("euromillions.csv",std::ifstream::in);
  std::string line;
  int nbline=0;
  int startline=1;
  char buff[1024];
  while (infile.getline( buff,1024))
  {
    line=buff;
    if(nbline>=startline){
      std::istringstream iss(line);
      std::string token;
      int column=0;
      char * pch;
      pch = strtok (line.c_str(),",");
      while(pch !=NULL)//std::getline(iss, token, ',')&&column<6) {
	
	if (column!=0){
	  std::string token=*pch;
	  std::istringstream isstok(token);
	  int a;
	  if (!(iss >> a)) { 
	    break; 
	  } 
	  else
	  {
	    //std::cout << " a = " <<a<<std::endl;
	    maxii.read(0,nbline,column,a);
	  }
	}
	column++;
	pch = strtok (NULL, ",");
      }	
    }
    
    
    // process pair (a,b)
    nbline++;
  }
  std::cout << " a = " <<nbline<<std::endl;
  infile.close();*/
  maxii.calculate();
  
  
  
  
  std::cout <<"PASS : 3 " <<maxii.getValues(0,5).size()<< std::endl;
  std::cout <<"PASS : 3 " <<maxii.getValues(0,5).at(0)<<" " <<maxii.getScoreValues(0,5).at(0)<<std::endl;
  std::cout <<"PASS : 3 " <<maxii.getValues(0,5).at(1)<<" " <<maxii.getScoreValues(0,5).at(1)<<std::endl;
  std::cout <<"PASS : 3 " <<maxii.getValues(0,5).at(2)<<" " <<maxii.getScoreValues(0,5).at(2)<<std::endl;
  std::cout <<"PASS : 3 " <<maxii.getValues(0,5).at(3)<<" " <<maxii.getScoreValues(0,5).at(3)<<std::endl;
  std::cout <<"PASS : 3 " <<maxii.getValues(0,5).at(4)<<" " <<maxii.getScoreValues(0,5).at(4)<<std::endl;
   
   // std::cout << "Hello, world!" << std::endl;
    std::cout << "PASS : TestCryptoHash::initTestCase()" << std::endl;
    return 0;
}
