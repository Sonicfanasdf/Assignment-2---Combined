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
    //Precondition:NA
    //Postcondition: returns seed
    int getSeed() const;
    //Precondition:NA
    //Postcondition: return multiplier
    int getMultiplier() const;
    //Precondition:NA
    //Postcondition:returns increment
    int getIncrement() const;
    //Precondition:NA
    //Postcondition: returns modulus
    int getModulus() const;
    //Precondition: A Positve or Negative Integer
    //Postcondition: None
    void setSeed(int newSeed);
    //Precondition: A Positive or Negative Integer
    //Postcondition: None
    void setMultiplier(int newMultiplier);
    //Precondition: A Positive or Negative Integer
    //Postcondition: None
    void setIncrement(int newIncrement);
    //Precondition: A Positive or Negative Integer
    //Postcondition: None
    void setModulus(int newModulus);
    //Precondition: None
    //Postcondition: None
    void generateSeed();
    //Precondition: None
    //Postcondition: Returns a Double
    double generateNextIndirectNum();
    //Pre-Condition: NA
    //Post-Condition: displays pseudorandom menu
    void pseudorandomMenu();
    //Pre-Condition: NA
    //Post-Condition: Returns user option
    char pseudorandomMenuOption();
    //Pre-Condition: NA
    //Post-Condition: Generates number table
    void generateIndirectNumTable();
};
