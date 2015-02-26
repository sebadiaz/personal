#include "Mixer.h"
#include<iostream>
Mixer::Mixer(AbstractStrategy *left,AbstractStrategy *right, std::vector<int>  nbLeft)
{
    this->left=left;
    this->right=right;
    this->nbLeft=nbLeft;

}

Mixer::~Mixer()
{
    //dtor
}

bool notin(std::vector< int > ret, int target){
  for(int i=0;i<ret.size();i++){
    if(ret.at(i)==target)
      return false;
  }
  return true;
}

std::vector<int> Mixer::getValues(int section,int nb){
    std::vector<int> vvv;
    return vvv;
}
std::vector<int> Mixer::getScoreValues(int section,int nb){
    std::vector<int> vvv;
    return vvv;
}

std::vector<int> righty(std::vector<int> &view,AbstractStrategy *right,int section,int nbNum,int numTirage,int nbTirage){
	if(numTirage>20){
		std::vector<int> rightV;
		return rightV;
	}
	
	std::vector<int> rightV=right->getTirage(section,nbNum,numTirage,nbTirage);
    if(rightV.size()==0||numTirage>20){
		return rightV;	
		}
	int need=0;
    for(int i=0;i<rightV.size();i++){
        if(notin(view,rightV[i])){
            view.push_back(rightV[i]);
        }
        else{
            need++;
        }
    }
	if (need>0){
		rightV=righty( view,right,section, nbNum, numTirage+1, nbTirage);
		
	}
	return rightV;
	}

std::vector<int> Mixer::getTirage(int section,int nbNum,int numTirage,int nbTirage){
    std::vector<int> view;
	int leftNN=nbLeft[section];
    std::vector<int> leftV=left->getTirage(section,leftNN,numTirage,leftNN);


    for(int i=0;i<leftV.size();i++){
        view.push_back(leftV[i]);
    }
    std::vector<int> rightV=righty(view,right,section,nbTirage-leftNN,numTirage,nbTirage-leftNN);

	int need=0;
    for(int i=0;i<rightV.size();i++){
        if(notin(view,rightV[i])){
            view.push_back(rightV[i]);
        }
        else{
            need++;
        }
    }
    std::vector<int> viewNext;
	if(nbNum>0){
		int yuyu=(nbNum<view.size())?nbNum:view.size();
	for(int j=0;j<yuyu;j++){
		viewNext.push_back(view[j]);
	}}
    return viewNext;
}
void Mixer::read(int list,int line, int column,int value){

}
void Mixer::calculate(){
}
