#include "Horse.h"

#include <string>
#include <cstdlib>

Horse::Horse () {   //Constructor
    position = 0;
    jump = 1;
}
void Horse::advance() {     //Generates the random number (1 or 0)
    int x = rand()%2;
    position += x;
}
void Horse::superJump(){
    position += jump;
}
void Horse::reset() {
    position = 0;
}
int Horse::getPosition() {      //Return the position
    return position;    
}
