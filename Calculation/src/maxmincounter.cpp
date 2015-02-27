/*
 * Copyright 2015 seb <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "maxmincounter.h"
#include<iostream>
#include <algorithm>

MaxMinCounter::MaxMinCounter(std::string nameP,std::vector<int> nbNumbers,bool inverse,int minline,int maxline){
  this->nbNumbers=nbNumbers;
  this->inverse=inverse;
  this->minLine=minline;
  this->maxLine=maxline;
  this->name=nameP;
  int count=0;
  for (std::vector<int>::iterator it=nbNumbers.begin(); it != nbNumbers.end(); ++it){
      int size=*it;
      std::vector<int> litou;
      for(int i=0;i<*it;i++)
      {
	litou.push_back(0);
      }
      counters.push_back(litou);

  }
}

MaxMinCounter::~MaxMinCounter(){


}

bool MaxMinCounter::notin(std::vector< int > ret, int target){
  for(int i=0;i<ret.size();i++){
    if(ret.at(i)==target)
      return false;
  }
  return true;
}

std::vector<int> MaxMinCounter::getScoreValues(int section,int nb){
  std::vector<int> ret;
  int from=0;
  if(orderedCounters.size()>0){
    for(int i=0;i<nb;i++)
    {
      from=i;
      if(inverse){
	from=orderedCounters.at(section).size()-i-1;
	if(from<0){
	  from=0;
	}
      }

      int target=orderedCounters.at(section)[from];
      ret.push_back(target);
    }
  }
  return ret;
}

std::vector<int> MaxMinCounter::getValues(int section,int nb){
  std::vector<int> ret;
  int from=0;
  if(orderedCounters.size()>0){
    for(int i=0;i<nb;i++)
    {
      from=i;
      if(inverse){
	from=orderedCounters.at(section).size()-i-1;
	if(from<0){
	  from=0;
	}
      }

      int target=orderedCounters.at(section)[from];
      for (int j=0;j<nbNumbers.at(section);j++){
	  std::cout <<"target "<<target<<" "<<counters.at(section)[j]<<" "<<notin(ret,target)<<std::endl;
	  if(counters.at(section)[j]==target&&ret.size()<nb&&notin(ret,j+1)){
	    ret.push_back(j+1);
	  }
      }
    }
  }
  return ret;
}

std::vector<int> MaxMinCounter::getFullValues(int section){
  std::vector<int> ret;
  int from=0;
  //std::cout<<counters.at(section).size()<<" "<<orderedCounters.at(section).size()<<std::endl;
  int sizeE=orderedCounters.at(section).size();
  if(sizeE>0){
    for(int i=0;i<sizeE;i++)
    {
      from=i;
      if(inverse){
	from=sizeE-i-1;
	if(from<0){
	  from=0;
	}
      }

      int target=orderedCounters.at(section)[from];
      for (int j=0;j<counters.at(section).size();j++){
	  //std::cout <<"target "<<target<<" "<<counters.at(section)[j]<<" "<<notin(ret,target)<<" "<<sizeE<<" "<<counters.at(section).size()<<std::endl;
	  if(counters.at(section)[j]==target&&notin(ret,j+1)){
	    ret.push_back(j+1);
	  }
      }
    }
  }
  return ret;
}

void MaxMinCounter::read(int section,int line, int column,int value){
  if(line<minLine||(line>maxLine&&maxLine!=-1)){
    std::cout<<"line="<<line<< " limit "<< minLine <<" " <<maxLine<<std::endl;
    return;
  }
  if(value <1){
    value=1;
  }
  counters.at(section)[value-1]++;
}

void quickSort(std::vector<int> &tableau, int debut, int fin);

void MaxMinCounter::calculate(){
  int section=0;
  //orderedCounters=clone(counters);
  orderedCounters=counters;
  for (std::vector<int>::iterator it=nbNumbers.begin(); it != nbNumbers.end(); ++it){
    std::sort (orderedCounters.at(section).begin(), orderedCounters.at(section).end());
    //quickSort(orderedCounters.at(section), 0, orderedCounters.at(section).size()-1);
    section++;
  }
}

int MaxMinCounter::getValue(int arg1, int arg2){
  return counters.at(arg1)[arg2+1];
}

void echanger(std::vector<int> &tableau, int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(std::vector<int> &tableau, int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const int pivot = tableau[debut];

    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);

        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

std::vector<int> MaxMinCounter::getTirage(int section,int nbNum,int numTirage,int nbTirage){
    std::vector<int> returnNum;
    std::vector<int> comple=getFullValues(section);
    int maxe=(comple.size()>nbNum)?nbNum:comple.size();
    for(int i=0;i<maxe;i++){
        int index=i+(nbTirage*numTirage);
        index=(comple.size()>index)?index:comple.size();
        returnNum.push_back(comple[index]);
    }
    return returnNum;
}

std::string MaxMinCounter::getName(){
	return name;
}

