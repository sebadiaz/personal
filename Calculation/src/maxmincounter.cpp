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

MaxMinCounter::MaxMinCounter(std::vector<int> nbNumbers){
  this->nbNumbers=nbNumbers;
  int count=0;
  for (std::vector<int>::iterator it=nbNumbers.begin(); it != nbNumbers.end(); ++it){
      int size=*it;
      int *litou=new int[size];
      counters.push_back(litou);
      for(int i=0;i<*it;i++)
      {
	(counters.at(count))[i]=0;
      }
  }
}

MaxMinCounter::~MaxMinCounter(){
  for (std::vector<int*>::iterator it=counters.begin(); it != counters.end(); ++it){
    delete (*it);
  }
  for (std::vector<int*>::iterator it=orderedCounters.begin(); it != orderedCounters.end(); ++it){
    delete (*it);
  }
  
}

bool MaxMinCounter::notin(std::vector< int > ret, int target){
  for(int i=0;i<ret.size();i++){
    if(ret.at(i)-1==target)
      return false;
  }
  return true;
}

std::vector<int> MaxMinCounter::getValues(int section,int nb){
  std::vector<int> ret;
  for(int i=0;i<nb;i++)
  {
    int target=orderedCounters.at(section)[i];
    for (int j=0;j<nbNumbers.at(section);j++){
        std::cout <<"target "<<target<<" "<<counters.at(section)[j]<<" "<<notin(ret,target)<<std::endl;
	if(counters.at(section)[j]==target&&ret.size()<nb&&notin(ret,target)){
	  ret.push_back(j+1);
	}
    }
  }
  return ret;
}

void MaxMinCounter::read(int section,int line, int column,int value){  
  counters.at(section)[value-1]++;
}

std::vector< int* > MaxMinCounter::clone(std::vector< int* > at){
  std::vector< int* > toRet;
  int section=0;
  for (std::vector<int>::iterator it=nbNumbers.begin(); it != nbNumbers.end(); ++it){
    int *comple= new int[*it];
    for(int i=0;i<*it;i++){
      comple[i]=at.at(section)[i];
    }
    section++;
    toRet.push_back(comple);
  }
  return toRet;
}

void quickSort(int tableau[], int debut, int fin);

void MaxMinCounter::calculate(){
  int section=0;
  orderedCounters=clone(counters);
  for (std::vector<int>::iterator it=nbNumbers.begin(); it != nbNumbers.end(); ++it){
    quickSort(orderedCounters.at(section), 0, (*it)-1);
    section++;
  }
}

int MaxMinCounter::getValue(int arg1, int arg2){
  return counters.at(arg1)[arg2+1];
}

void echanger(int tableau[], int a, int b)
{
    int temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(int tableau[], int debut, int fin)
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