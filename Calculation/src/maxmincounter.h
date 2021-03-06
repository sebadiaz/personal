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

#ifndef MAXMINCOUNTER_H
#define MAXMINCOUNTER_H
#include<abstractstrategy.h>

class MaxMinCounter : public AbstractStrategy
{
private:
    std::vector<int> nbNumbers;
    std::vector<std::vector<int> > counters;
    std::vector<std::vector<int> > orderedCounters;
    bool inverse;
    int minLine;
    int maxLine;
    bool notin(std::vector< int > ret, int target);
	std::string name;

public:
    std::vector<int> getFullValues(int section);

    MaxMinCounter(std::string name,std::vector<int> nbNumbers,bool inverse=false,int minline=0,int maxline=-1);
    ~MaxMinCounter();
    virtual std::vector<int> getValues(int section,int nb);
    virtual std::vector<int> getScoreValues(int section,int nb);
    virtual void read(int list,int line, int column,int value);
    virtual std::vector<int> getTirage(int section,int nbNum,int numTirage,int nbTirage);
    virtual void calculate();
    int getValue(int arg1, int arg2);
	virtual std::string getName();

};

#endif // MAXMINCOUNTER_H
