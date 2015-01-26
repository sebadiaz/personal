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
#include<vector>

class MaxMinCounter : public AbstractStrategy 
{
    std::vector<int> nbNumbers;
    std::vector<int*> counters;
public:
    MaxMinCounter(std::vector<int> nbNumbers);
    virtual std::set<std::string> getValues(int nb);
    virtual void read(int list,int line, int column,int value);
    virtual void calculate();
};

#endif // MAXMINCOUNTER_H
