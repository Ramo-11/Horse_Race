//Race.cpp

#include "Horse.h"
#include "Race.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

Race::Race () {   //Default Constructor
    length = 8;
}
void Race::printLane(int horseNum) {
        for (horseNum = 0; horseNum < 5; horseNum++) {
            for (int unit = 0; unit < 6; unit++) {
                if(unit == h[horseNum].getPosition()) { //Print dots everywhere except at position
                    std::cout << horseNum;
                }
                else {
                    std::cout << ".";
                }
            }   //End for
            std::cout << std::endl;
        } //End for
}   //End method

int Race::getRandom(){
    int y = rand()%5;    
    return y;
}

int Race::userGuess() {
    int uGuess = 0;
    std::cout << "Guess the horse with the super position this round(0 to 4): ";
    std::cin >> uGuess;
    return uGuess;
}

void Race::start () {
    int seed; 
    int choice;
    int proRand;
    int totalGuesses = 0;
    int horseNum = 0;
    int checking = 0;
    std::cout << "Please enter a random seed: "; //Get seed from user
    std::cin >> seed;
    std::srand(seed);
    
    for (int repeat = 0; repeat < 100; repeat++) { 
        for (horseNum = 0; horseNum < 5; horseNum++) {
            h[horseNum].advance();

            proRand = getRandom();
            choice = userGuess();

            h[proRand].superJump();

            if(choice == proRand) {
                std::cout << std::endl << "You guessed it right! it was horse " << choice << "!\n";
                totalGuesses++;                              
            }
            
            else {
                std::cout << std::endl << "your guess wasn't right, the horse you guessed will go back to the starting point :( \n";
                h[choice].reset();
            }
            
            for (checking = 0; checking < 5; checking++) {
                if(h[checking].getPosition() == 6) {
                    printLane(checking);
                    std::cout << std::endl;
                    std::cout << "Horse " << checking << " wins!\n";
                    std::cout << "Your total right guesses is: " << totalGuesses << "\n";
                    exit(0);
                }  //end if
            }   //end for
            printLane(horseNum);
            std::cout << std::endl;
        }   //end for
    }   //end for
}   //end method
