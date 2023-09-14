/*
 Erik Santana
 9/4/23
 CPMR 131 - Professor Q

 Description:

 Part 1 works with a quadratic equation using classes.
 Part 2 creates a custom random seed generator that also uses classes.
 Part 3 does math calculations with rational numbers, also uses a class.

 Credit:
 Joe Bryant & Erik Santana - Part 1: Quadratic Expression
 Saul Merino & Oscar Gallardo - Part 2: Pseudorandom
 Otoniel Torres Bernal & John Kim  - Part 3: Rational Number
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

