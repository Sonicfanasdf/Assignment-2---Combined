#include "Pseudorandom.h"

// Credit:  Saul Merino & John Kim - Pseudorandom

Pseudorandom::Pseudorandom()
{
    seed = 1;
    multiplier = 40;
    increment = 725;
    modulus = 729;
}

void Pseudorandom::setSeed(int newSeed)
{
    seed = newSeed;
}

void Pseudorandom::setMultiplier(int newMultiplier)
{
    multiplier = newMultiplier;
}

void Pseudorandom::setIncrement(int newIncrement)
{
    increment = newIncrement;
}

void Pseudorandom::setModulus(int newModulus)
{
    modulus = newModulus;
}

void Pseudorandom::generateSeed()
{
    int newSeed = (multiplier * seed + increment) % modulus;
    setSeed(newSeed);
}

double Pseudorandom::generateNextIndirectNum()
{
    generateSeed();
    return static_cast<double>(seed) / modulus;
}

// Pre-Condition: 
// Post-Condition:
void Pseudorandom::pseudorandomMenu()
{
    Pseudorandom pseudorandom;

    do
    {
        switch (pseudorandomMenuOption())
        {
        case '0':
        {
            system("cls");
            mainMenu();
            break;
        }
        case 'A':
        {
            std::cout << "Seed: " << pseudorandom.getSeed();
            break;
        }
        case 'B':
        {
            pseudorandom.setSeed(inputInteger("Enter Seed:"));
            break;
        }
        case 'C':
        {
            std::cout << "Multiplier: " << pseudorandom.getMultiplier();
            break;
        }
        case 'D':
        {
            pseudorandom.setMultiplier(inputInteger("Enter Multiplier:"));
            break;
        }
        case 'E':
        {
            std::cout << "Modulus: " << pseudorandom.getModulus();
            break;
        }
        case 'F':
        {
            pseudorandom.setModulus(inputInteger("Enter Modulus:"));
            break;
        }
        case 'G':
        {
            std::cout << "Increment: " << pseudorandom.getIncrement();
            break;
        }
        case 'H':
        {
            pseudorandom.setIncrement(inputInteger("Enter Increment:"));
            break;
        }
        case 'I':
        {
            pseudorandom.generateSeed(); std::cout << pseudorandom.getSeed();
            break;
        }
        case 'J':
        {
            std::cout << "Indirect Next Number: " << pseudorandom.generateNextIndirectNum();
            break;
        }
        case 'K':
        {
            pseudorandom.generateIndirectNumTable(pseudorandom);
            break;
        }
        default:
        {
            std::cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        }

        std::cout << "\n";
        system("pause");

    } while (true);
}

// Pre-Condition: 
// Post-Condition:
char Pseudorandom::pseudorandomMenuOption()
{
    system("cls");
    std::cout << "2: Pseudorandom" << std::endl;
    std::cout << std::string(100, char(205)) << std::endl;
    std::cout << "A. Get Seed" << std::endl;
    std::cout << "B. Set Seed" << std::endl;
    std::cout << "C. Get Multiplier" << std::endl;
    std::cout << "D. Set Multiplier" << std::endl;
    std::cout << "E. Get Modulus" << std::endl;
    std::cout << "F. Set Modulus" << std::endl;
    std::cout << "G. Get Increment" << std::endl;
    std::cout << "H. Set Increment" << std::endl;
    std::cout << "I. Get Next Number" << std::endl;
    std::cout << "J. Get Next Indirect Number" << std::endl;
    std::cout << "K. Run Experiment With Different Numbers (Multiplier, Increment, and Modulus)" << std::endl;
    std::cout << std::string(100, char(205)) << std::endl;
    std::cout << "0. Return" << std::endl;
    std::cout << std::string(100, char(205)) << std::endl;

    char option = toupper(inputChar("Option : "));
    return option;
}

// Pre-Condition: 
// Post-Condition:
void Pseudorandom::generateIndirectNumTable(Pseudorandom pseudorandom)
{
    pseudorandom.setMultiplier(21);
}
