/*
 * Copyright 2015 Sebastien DIAZ sebastien.disaz@gmail.com
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

#ifndef ABSTRACTSTRATEGY_H
#define ABSTRACTSTRATEGY_H
#include <vector>
#include <string>
#include <sstream>
class AbstractStrategy
{
public:
   virtual std::vector<int> getValues(int section,int nb)=0;
   virtual std::vector<int> getScoreValues(int section,int nb)=0;
   virtual std::vector<int> getTirage(int section,int nbNum,int numTirage,int nbTirage)=0;
   virtual void read(int list,int line, int column,int value)=0;
   virtual void calculate()=0;
   
   std::string toString(std::vector<int> list,int tirage=0){
	   std::stringstream stream;
	   for(int i=0;i<list.size();i++){
		   int nb=list[i];
		   std::vector<int> fr=getTirage(i,nb,tirage,nb);
		   for(int j=0;j<fr.size();j++){
			stream<<fr[j]<<",";
		   }
		   
	   }
	   stream<<std::endl;
	   std::string ig=stream.str();
	   return ig;
   }
};

#endif // ABSTRACTSTRATEGY_H
