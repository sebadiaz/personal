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

std::set<std::string> MaxMinCounter::getValues(int nb){
  std::set<std::string> ret;
  return ret;
}

void MaxMinCounter::read(int section,int line, int column,int value){  
  counters.at(section)[value]++;
}

void MaxMinCounter::calculate(){
  
}