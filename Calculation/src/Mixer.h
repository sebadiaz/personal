#ifndef MIXER_H
#define MIXER_H

#include <abstractstrategy.h>


class Mixer : public AbstractStrategy
{
    public:
        /** Default constructor */
        Mixer(AbstractStrategy *left,AbstractStrategy *right, std::vector<int> nbLeft);
        /** Default destructor */
        virtual ~Mixer( );
        virtual std::vector<int> getValues(int section,int nb);
        virtual std::vector<int> getScoreValues(int section,int nb);
        virtual std::vector<int> getTirage(int section,int nbNum,int numTirage,int nbTirage);
        virtual void read(int list,int line, int column,int value);
        virtual void calculate();
    protected:
    private:
        AbstractStrategy *left;
        AbstractStrategy *right;
         std::vector<int> nbLeft;

};

#endif // MIXER_H
