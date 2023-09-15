#include "QuadraticExpression.h"

// Credit: Joe Bryant & Erik Santana - Quadratic Expression

// Pre-Condition: no parameters
// Post-Condition: no return. No argument constructor. Initializer constructor
QuadraticExpression::QuadraticExpression()
{
    coefficientA = 0;
    coefficientB = 0;
    coefficientC = 0;
    coefficientX = 0;
}

// Pre-Condition: parameters - int newCoefficientA, int newCoefficientB, int newCoefficientC, int newCoefficientX. These parameters are assigned to the private member variables.
// Post-Condition: no return. Argument constructor
QuadraticExpression::QuadraticExpression(int newCoefficientA, int newCoefficientB, int newCoefficientC, int newCoefficientX)
{
    coefficientA = newCoefficientA;
    coefficientB = newCoefficientB;
    coefficientC = newCoefficientC;
    coefficientX = newCoefficientX;
}

//                                              Mutators

// Pre-Condition: parameter int newCoefficientA is assigned to the private member variable coefficientA.
// Post-Condition: no return. This mutator member function sets/changes the private variable coefficientA. 
void QuadraticExpression::setA(int newCoefficientA)
{
    coefficientA = newCoefficientA;
}

// Pre-Condition: parameter int newCoefficientB is assigned to the private member variable coefficientB.
// Post-Condition: no return. This mutator member function sets/changes the private variable coefficientB. 
void QuadraticExpression::setB(int newCoefficientB)
{
    coefficientB = newCoefficientB;
}

// Pre-Condition: parameter int newCoefficientC is assigned to the private member variable coefficientC.
// Post-Condition: no return. This mutator member function sets/changes the private variable coefficientC. 
void QuadraticExpression::setC(int newCoefficientC)
{
    coefficientC = newCoefficientC;
}

// Pre-Condition: parameter int newCoefficientX is assigned to the private member variable coefficientX.
// Post-Condition: no return. This mutator member function sets/changes the private variable coefficientX. 
void QuadraticExpression::setX(int newCoefficientX)
{
    coefficientX = newCoefficientX;
}

//                                              Accessors

// Pre-Condition: no parameters.
// Post-Condition: returns coefficientA. Accessors function to get(view) the value of coefficientA
int QuadraticExpression::getA() const
{
    return coefficientA;
}

// Pre-Condition: no parameters.
// Post-Condition: returns coefficientB. Accessors function to get(view) the value of coefficientB
int QuadraticExpression::getB() const
{
    return coefficientB;
}

// Pre-Condition: no parameters.
// Post-Condition: returns coefficientC. Accessors function to get(view) the value of coefficientC
int QuadraticExpression::getC() const
{
    return coefficientC;
}

// Pre-Condition: no parameters.
// Post-Condition: returns coefficientX. Accessors function to get(view) the value of coefficientX
int QuadraticExpression::getX() const
{
    return coefficientX;
}
//Precondition: NA
//Postcondition: prints out number of roots Quadratic equation has
void QuadraticExpression::numRoots() const
{
    double discriminant = 0;
    double denominator = 0;

    discriminant = (pow(coefficientB, 2)) - (4 * coefficientA * coefficientC);
    denominator = 2 * coefficientA;

    if (discriminant < 0 || denominator == 0)
    {
        std::cout << "\n\tnumber of real roots: 0\n";
    }
    else if (discriminant == 0)
    {
        std::cout << "\n\tnumber of real roots: 1\n";
    }
    else if (discriminant > 0)
    {
        std::cout << "\n\tnumber of real roots: 2\n";
    }
}

//Precondition: NA
//Postcondition: prints out result of solved quadratic eqaution with the given x
void QuadraticExpression::getEvaluation() const
{
    std::cout << std::endl << "X = " << coefficientX << std::endl;

    double result = 0;

    result = coefficientA * (pow(coefficientX, 2)) + (coefficientB * coefficientX) + coefficientC;

    std::cout << "\t\n" << coefficientA << "(" << coefficientX << "^2) + " << "(" << coefficientB << ")" << "(" << coefficientX << ")" << " + " << coefficientC << " = " << result << std::endl;
}

//Precondition: NA
//Postcondition: calculates the roots of quadratic equation and prints
void QuadraticExpression::getRoots() const
{
    double discriminant = 0;
    double denominator = 0;
    double root1 = 0;
    double root2 = 0;

    discriminant = (pow(coefficientB, 2)) - (4 * coefficientA * coefficientC);
    denominator = 2 * coefficientA;

    if (discriminant < 0 || denominator == 0)
    {
        std::cout << "\n\tno real roots\n";
    }
    else if (discriminant == 0)
    {
        root1 = (-coefficientB + (sqrt((pow(coefficientB, 2)) - (4 * coefficientA * coefficientC)))) / (2 * coefficientA);

        std::cout << "\n\tonly real root: " << root1 << std::endl;
    }
    else if (discriminant > 0)
    {
        root1 = (-coefficientB + (sqrt((pow(coefficientB, 2)) - (4 * coefficientA * coefficientC)))) / (2 * coefficientA);
        root2 = (-coefficientB - (sqrt((pow(coefficientB, 2)) - (4 * coefficientA * coefficientC)))) / (2 * coefficientA);

        std::cout << "\n\ttwo real roots are: " << root2 << " and " << root1 << std::endl;
    }
}

// Pre-Condition: no parameters
// Post-Condition: no return. Sub menu, user picks an option.
void QuadraticExpression::quadraticExpressionMenu()
{

    // loop through sub menu until user exits
    do
    {
        system("cls");
        std::cout << "\t\n1 > Quadratic Menu\n";
        std::cout << "===========================================================\n";
        std::cout << "D. Display the expression\n";
        std::cout << "A. Set coefficient (A)\n";
        std::cout << "B. Set coefficient (B)\n";
        std::cout << "C. Set coefficient (C)\n";
        std::cout << "E. Get evaluation (X)\n";
        std::cout << "N. Get the number of real roots\n";
        std::cout << "R. Get real root(s)\n";
        std::cout << "------------------------------------------------------------\n";
        std::cout << "0. Return to Main Menu\n";
        std::cout << "===========================================================\n";

        // get user input/option of main menu
        int option = toupper(inputChar("\n\tOption: ", "ABCDENR0"));

        switch (option)
        {
        case '0':
        {
            system("cls");
            mainMenu();
            break;
        }
        case 'D':
        {
            std::cout << "\t\n" << coefficientA << "x^2 + " << coefficientB << "x + " << coefficientC << std::endl;
            break;
        }
        case 'A':
        {
            // Set coefficient (coefficientA)
            coefficientA = inputInteger("\nEnter coefficient (A): ");

            std::cout << std::endl << "A = " << coefficientA << std::endl;
            break;
        }
        case 'B':
        {
            // Set coefficient (coefficientB)
            coefficientB = inputInteger("\nEnter coefficient (B): ");

            std::cout << std::endl << "B = " << coefficientB << std::endl;
            break;
        }
        case 'C':
        {
            // Set coefficient (coefficientC)
            coefficientC = inputInteger("\nEnter coefficient (C): ");

            std::cout << std::endl << "C = " << coefficientC << std::endl;
            break;
        }
        case 'E':
        {
            // Set coefficient (coefficientX)
            coefficientX = inputInteger("\nEnter Variable (X): ");

            getEvaluation();

            break;
        }
        case 'N':
        {
            numRoots();

            break;
        }
        case 'R':
        {
            getRoots();

            break;
        }
        default:
        {
            std::cout << "\t\tERROR - Invalid option. Please re-enter.";
            break;
        }
        }

        // new line
        std::cout << "\n";
        system("pause");

    } while (true);

}

// Pre-Condition: no parameters
// Post-Condition: no return. Destructor
QuadraticExpression::~QuadraticExpression()
{}

