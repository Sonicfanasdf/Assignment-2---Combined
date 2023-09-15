#include "Pseudorandom.h"

// Credit:  Saul Merino & John Kim - Pseudorandom

//Precondition: None
//Postcondition: None
Pseudorandom::Pseudorandom()
{
    seed = 1;
    multiplier = 40;
    increment = 725;
    modulus = 729;
}
int Pseudorandom::getSeed() const
{
    return seed;
}

int Pseudorandom::getMultiplier() const
{
    return multiplier;
}
int Pseudorandom::getIncrement() const
{
    return increment;
}
int Pseudorandom::getModulus() const
{
    return modulus;
}
//Precondition: A Positve or Negative Integer
//Postcondition: None
void Pseudorandom::setSeed(int newSeed)
{
    seed = newSeed;
}
//Precondition: A Positive or Negative Integer
//Postcondition: None 
void Pseudorandom::setMultiplier(int newMultiplier)
{
    multiplier = newMultiplier;
}
//Precondition: A Positive or Negative Integer
//Postcondition: None
void Pseudorandom::setIncrement(int newIncrement)
{
    increment = newIncrement;
}
//Precondition: A Positive or Negative Integer
//Postcondition: None
void Pseudorandom::setModulus(int newModulus)
{
    modulus = newModulus;
}
//Precondition: None
//Postcondition: None
void Pseudorandom::generateSeed()
{
    int newSeed = (multiplier * seed + increment) % modulus;
    setSeed(newSeed);
}
//Precondition: None
//Postcondition: Returns a Double
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
            pseudorandom.generateIndirectNumTable();
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

// Pre-Condition: NA
// Post-Condition: Returns user option
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

// Pre-Condition: NA
// Post-Condition: Generates number table
void Pseudorandom::generateIndirectNumTable()
{
    const int SIZE = 1000000;

    double sum = 0;
    double mean = 0;
    double difference = 0;
    double differenceSum = 0;
    double deviation = 0;
    double gDistribution = 0;



    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    int count9 = 0;
    int count10 = 0;

    double* dataArray = new double[SIZE];

    setMultiplier(rand());
    setIncrement(rand());
    setModulus(rand());
    std::cout << "\n\t experiment of pseudorandom with random multiplier, increment and modulus: \n\n";
    std::cout << "\t============================================================================\n";
    std::cout << "\tmultiplier = " << multiplier << ", increment = " << increment << ", modulus = " << modulus << std::endl << std::endl;

    for (int i = 0; i < SIZE; i++)
    {

        dataArray[i] = generateNextIndirectNum();

        sum += dataArray[i];

        //std::cout << dataArray[i] << std::endl;
    }

    for (int j = 0; j < SIZE; j++)
    {
        if (0 <= dataArray[j] && dataArray[j] < 0.1)
        {
            count1++;
        }
        else if (0.1 <= dataArray[j] && dataArray[j] < 0.2)
        {
            count2++;
        }
        else if (0.2 <= dataArray[j] && dataArray[j] < 0.3)
        {
            count3++;
        }
        else if (0.3 <= dataArray[j] && dataArray[j] < 0.4)
        {
            count4++;
        }
        else if (0.4 <= dataArray[j] && dataArray[j] < 0.5)
        {
            count5++;
        }
        else if (0.5 <= dataArray[j] && dataArray[j] < 0.6)
        {
            count6++;
        }
        else if (0.6 <= dataArray[j] && dataArray[j] < 0.7)
        {
            count7++;
        }
        else if (0.7 <= dataArray[j] && dataArray[j] < 0.8)
        {
            count8++;
        }
        else if (0.8 <= dataArray[j] && dataArray[j] < 0.9)
        {
            count9++;
        }
        else if (0.9 <= dataArray[j] && dataArray[j] < 1)
        {
            count10++;
        }
    }

    std::cout << "\tRange           Number of Occurrences\n";
    std::cout << "\t[0.0 ... 0.1)   " << count1 << std::endl;
    std::cout << "\t[0.1 ... 0.2)   " << count2 << std::endl;
    std::cout << "\t[0.2 ... 0.3)   " << count3 << std::endl;
    std::cout << "\t[0.3 ... 0.4)   " << count4 << std::endl;
    std::cout << "\t[0.4 ... 0.5)   " << count5 << std::endl;
    std::cout << "\t[0.5 ... 0.6)   " << count6 << std::endl;
    std::cout << "\t[0.6 ... 0.7)   " << count7 << std::endl;
    std::cout << "\t[0.7 ... 0.8)   " << count8 << std::endl;
    std::cout << "\t[0.8 ... 0.9)   " << count9 << std::endl;
    std::cout << "\t[0.9 ... 1.0)   " << count10 << std::endl;

    mean = sum / SIZE;

    for (int k = 0; k < SIZE; k++)
    {
        difference = pow((dataArray[k] - mean), 2);

        differenceSum += difference;
    }

    double median = (dataArray[499999] + dataArray[500000]) / 2;

    deviation = sqrt((differenceSum / SIZE));


    gDistribution = deviation * (mean - 6) + median;


    

    delete [] dataArray;
}
