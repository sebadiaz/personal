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

#include "core.h"
void core::calculate(){

  int section=0;
  int numero=47;
  int column=2;
  int line=5;
  
  for (std::list<AbstractStrategy*>::iterator it=list.begin(); it != list.end(); ++it){
      (*it)->read(section,line,column,numero);
  }
  
  
    

}