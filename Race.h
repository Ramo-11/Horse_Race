//Race.h

#ifndef RACE_H
#define RACE_H

#include "Horse.h"

class Race {
    private: 
        Horse h[5]; 
        int length;
    public:
        Race();
        void printLane(int horseNum);
        void start();
        int userGuess();
        int getRandom();
};
#endif

