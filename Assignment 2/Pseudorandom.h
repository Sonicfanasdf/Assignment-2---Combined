#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

// Credit:  Saul Merino & John Kim - Pseudorandom

int inputInteger(std::string prompt);
char inputChar(std::string prompt);
void mainMenu();

class Pseudorandom
{
private:
    int seed;
    int multiplier;
    int increment;
    int modulus;

public:
    //Precondition: None
    //Postcondition: None
    Pseudorandom();
    
    int getSeed() const;
    int getMultiplier() const;
    int getIncrement() const;
    int getModulus() const;
    void setSeed(int newSeed);
    void setMultiplier(int newMultiplier);
    void setIncrement(int newIncrement);
    void setModulus(int newModulus);
    void generateSeed();
    double generateNextIndirectNum();
    void pseudorandomMenu();
    char pseudorandomMenuOption();
    void generateIndirectNumTable();
};
