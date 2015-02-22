#include <iostream>
#include <maxmincounter.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  std::vector<int> list;
  list.push_back(5);
  list.push_back(5);
  MaxMinCounter max(list);
  MaxMinCounter max2(list,true);
  MaxMinCounter max3(list,true,0,2);
  for(int i=0;i<100;i++){
    max.read(0,0,0,(rand()%5)+1);
    max.read(1,0,0,(rand()%5)+1);
    max2.read(0,0,0,(rand()%5)+1);
    max2.read(1,0,0,(rand()%5)+1);
    max3.read(0,rand()%3,0,(rand()%5)+1);
    max3.read(1,rand()%3,0,(rand()%5)+1);
  }
  max.calculate();
  max2.calculate();
  max3.calculate();

  std::cout <<"PASS : 2 " <<max2.getValues(0,5).size()<< std::endl;
  std::cout <<"PASS : 2 " <<max2.getValues(0,5).at(0)<<" " <<max2.getScoreValues(0,5).at(0)<<std::endl;
  std::cout <<"PASS : 2 " <<max2.getValues(0,5).at(1)<<" " <<max2.getScoreValues(0,5).at(1)<<std::endl;
  std::cout <<"PASS : 2 " <<max2.getValues(0,5).at(2)<<" " <<max2.getScoreValues(0,5).at(2)<<std::endl;
  std::cout <<"PASS : 2 " <<max2.getValues(0,5).at(3)<<" " <<max2.getScoreValues(0,5).at(3)<<std::endl;
  std::cout <<"PASS : 2 " <<max2.getValues(0,5).at(4)<<" " <<max2.getScoreValues(0,5).at(4)<<std::endl;


  std::cout <<"PASS :  " <<max.getValues(0,5).size()<< std::endl;
  std::cout <<"PASS :  " <<max.getValues(0,5).at(0)<<" " <<max.getScoreValues(0,5).at(0)<<std::endl;
  std::cout <<"PASS :  " <<max.getValues(0,5).at(1)<<" " <<max.getScoreValues(0,5).at(1)<<std::endl;
  std::cout <<"PASS :  " <<max.getValues(0,5).at(2)<<" " <<max.getScoreValues(0,5).at(2)<<std::endl;
  std::cout <<"PASS :  " <<max.getValues(0,5).at(3)<<" " <<max.getScoreValues(0,5).at(3)<<std::endl;
  std::cout <<"PASS :  " <<max.getValues(0,5).at(4)<<" " <<max.getScoreValues(0,5).at(4)<<std::endl;

  std::cout <<"PASS : 3 " <<max3.getValues(0,5).size()<< std::endl;
  std::cout <<"PASS : 3 " <<max3.getValues(0,5).at(0)<<" " <<max3.getScoreValues(0,5).at(0)<<std::endl;
  std::cout <<"PASS : 3 " <<max3.getValues(0,5).at(1)<<" " <<max3.getScoreValues(0,5).at(1)<<std::endl;
  std::cout <<"PASS : 3 " <<max3.getValues(0,5).at(2)<<" " <<max3.getScoreValues(0,5).at(2)<<std::endl;
  std::cout <<"PASS : 3 " <<max3.getValues(0,5).at(3)<<" " <<max3.getScoreValues(0,5).at(3)<<std::endl;
  std::cout <<"PASS : 3 " <<max3.getValues(0,5).at(4)<<" " <<max3.getScoreValues(0,5).at(4)<<std::endl;

  std::cout <<"PASS : 4 " <<max.getTirage(0,2,5).at(0)<<std::endl;
  std::cout <<"PASS : 4 " <<max.getTirage(0,2,5).at(1)<<std::endl;
  std::cout <<"PASS : 4 " <<max.getTirage(0,3,5).at(2)<<std::endl;

   // std::cout << "Hello, world!" << std::endl;
    std::cout << "PASS : TestCryptoHash::initTestCase()" << std::endl;
    return 0;
}
