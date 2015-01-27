#include <iostream>
#include <maxmincounter.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  std::vector<int> list;
  list.push_back(5);
  list.push_back(5);
  MaxMinCounter max(list);
  for(int i=0;i<100;i++){
    max.read(0,0,0,(rand()%5)-1);
    max.read(1,0,0,(rand()%5)-1);
  }
  max.calculate();
  std::cout <<"PASS : " <<max.getValues(0,5).at(0)<< std::endl;
  std::cout <<"PASS : " <<max.getValues(0,5).at(1)<< std::endl;
  std::cout <<"PASS : " <<max.getValues(0,5).at(2)<< std::endl;
  std::cout <<"PASS : " <<max.getValues(0,5).at(3)<< std::endl;
  std::cout <<"PASS : " <<max.getValues(0,5).at(4)<< std::endl;
    
   // std::cout << "Hello, world!" << std::endl;
    std::cout << "PASS : TestCryptoHash::initTestCase()" << std::endl;
    return 0;
}
