//Horse.h

#ifndef HORSE_H
#define HORSE_H

#include <iostream>

class Horse {
    private:
        int position;
        int jump;
        
    public:
        Horse();
        void advance();
        int getPosition();
        void superJump();
        void reset();
};
#endif

