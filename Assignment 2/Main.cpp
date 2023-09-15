/*
 Joe Bryant
 9/4/23
 CPMR 131 - Professor Q

 Description:

 Part 1 is a quadratic expression class that allows the user to view a quadratic formula with coefficients of their choosing. 
 You can also solve for the roots and calculate the amount of roots
 Part 2 is a Pseudorandom class that lets the user input a multiplier, seed, increment, and modulus. 
 With these values, it generates a pseudorandom number.
 Part 3 is a Rational class that lets the user input 2 fractions and do mathematical processes with these two fractions.
 this includes addition, subtraction, division, and multiplication.

 Credit:
 Joe Bryant & Erik Santana - Part 1: Quadratic Expression
 Saul Merino & John Kim - Part 2: Pseudorandom
 Otoniel Torres Bernal & Thanh Tran   - Part 3: Rational Number
 */

#include <iomanip>
#include "QuadraticExpression.h"
#include "Pseudorandom.h"
#include "Rational.h"
#include "input.h"

void mainMenu();

int main()
{

    mainMenu();

    return 0;
}
//Precondition: NA
//Postcondition: Displays main menu
void mainMenu()
{
    QuadraticExpression quadraticExpression;
    Pseudorandom pseudorandom;
    Rational rational;

    // Main Menu

    cout << endl;
    cout << "\tCMPR131 - Chapter 2 ADT Assignment by Erik Santana (9 / 4 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1> Quadratic Expression" << endl;
    cout << "\t2> Pseudorandom" << endl;
    cout << "\t3> Rational number" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > exit" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    // get user input/option of main menu
    int option = inputInteger("\n\tOption: ", 0, 3);

    // loop through main menu until user exits
    do
    {
        switch (option)
        {
        case 0: exit(1); break;
        case 1: system("cls"); quadraticExpression.quadraticExpressionMenu(); break;
        case 2: system("cls"); pseudorandom.pseudorandomMenu(); break;
        case 3: system("cls"); rational.rational_Menu(); break;

        }

        // new line
        cout << "\n";

    } while (true);
}

