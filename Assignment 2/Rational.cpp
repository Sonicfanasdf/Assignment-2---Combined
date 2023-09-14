#include "Rational.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

// Credit: Thanh Tran & Otoniel Torres Bernal - Rational

// Pre-Condition: no parameters.
// Post-Condition: no return. A no argument initializer constructor that sets the numerator to 0 and the denominator to 1.
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

// Pre-Condition: parameters int newN, int newD are assigned to numerator and denominator respictively.
// Post-Condition: no return. An exception is thrown if the denominator is zero.
Rational::Rational(int newN, int newD)
{
	numerator = newN;
	denominator = newD;
	if (denominator == 0)
		throw ZeroDenominator(*this); // throw exception

	normalize();
}

//PreCondition: integer a and b parameter
//PostCondition: return the greatest common divisor between a and b.
int Rational::gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else return gcd(a, b - a);
}

// Pre-Condition: no parameters. 
// Post-Condition: no return. If the denominator is negative, then the negative sign is moved to the numerator and reduce if there is a GCD (greatest common divisor).
void Rational::normalize()
{
	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
	}

	int temp = gcd(abs(numerator), abs(denominator));

	if (temp != 0)
	{
		numerator /= temp;
		denominator /= temp;
	}
}


//PreCondition: NA
//PostCondition: returns a string expression of the numerator/denominator.  
std::string Rational::toString()
{
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

//******************************* Acesssor *********************************//

//PreCondition: NA
//PostCondition: return the numerator private member
int Rational::getNumerator() const
{
	return numerator;
}

//PreCondition: NA
//PostCondition: return the denominator private member
int Rational::getDenominator() const
{
	return denominator;
}

//******************************* Mutator *********************************//

//PreCondition: an interger value
//PostCondition: set the values of the numerator private member
void Rational::setNumerator(int newN)
{
	numerator = newN;
	normalize();
}

//PreCondition: an interger value
//PostCondition: set the values of the denominator private member
void Rational::setDenominator(int newD)
{
	denominator = newD;
	if (denominator == 0)
		throw ZeroDenominator(*this); // throw exception

	normalize();
}

//******************************* Overloading Operator **************************//

//PreCondition: 2 Rational objects
//PostCondition:  return a the object that is the result of the multiplication of the 2 rational objects
Rational operator *(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.numerator = obj1.numerator * obj2.numerator;
	temp.denominator = obj1.denominator * obj2.denominator;

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition:  return a the object that is the result of the division of the 2 rational objects
Rational operator /(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.numerator = obj1.numerator * obj2.denominator;
	temp.denominator = obj1.denominator * obj2.numerator;

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition:  return a the object that is the result of sum of the 2 rational objects
Rational operator +(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.denominator = obj1.denominator * obj2.denominator;

	temp.numerator = (obj1.numerator * obj2.denominator) + (obj2.numerator * obj1.denominator);

	temp.normalize();

	return temp;
}

//PreCondition: 2 Rational objects
//PostCondition: return a the object that is the difference of the 2 rational objects
Rational operator -(const Rational& obj1, const Rational& obj2)
{
	Rational temp;

	temp.denominator = obj1.denominator * obj2.denominator;

	temp.numerator = (obj1.numerator * obj2.denominator) - (obj2.numerator * obj1.denominator);

	temp.normalize();

	return temp;
}


//PreCondition: 2 Rational objects
//PostCondition:  return a flag that compares two Rational numbers are equal
bool operator ==(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
}

//PreCondition: 2 Rational objects
//PostCondition: return a flag which indicate one is lesser than another.
bool operator <(const Rational& obj1, const Rational& obj2)
{
	return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
}

//PreCondition: a ostream object and a Rational object
//PostCondition: return the object that used for display 
std::ostream& operator << (std::ostream& out, Rational obj)
{
	out << obj.toString();
	return out;
}

//PreCondition: NA
//PostCondition: no return. Menu for Rational(Part 3)
void Rational::rational_Menu()
{
	Rational rational1;
	Rational rational2;

	do
	{
		system("cls");
		std::cout << "\n\t3> Rational Number menu";
		std::cout << "\n\t" + std::string(68, char(205));
		std::cout << "\n\t\tA. enter values of rational number R1";
		std::cout << "\n\t\tB. display R1";
		std::cout << "\n\t\tC. enter values for  rational number R2";
		std::cout << "\n\t\tD. display R2";
		std::cout << "\n\t\tE. multiplication of 2 rational numbers (R1 * R2)";
		std::cout << "\n\t\tF. division of 2 rational numbers (R1 / R2)";
		std::cout << "\n\t\tG. addition of 2 rational numbers (R1 + R2)";
		std::cout << "\n\t\tH. subtraction 2 rational numbers (R1 - R2)";
		std::cout << "\n\t\tI. (R1 == R2)";
		std::cout << "\n\t\tJ. (R1 < R2)";

		std::cout << "\n\t" + std::string(68, char(196));
		std::cout << "\n\t\t0> return";
		std::cout << "\n\t" + std::string(68, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<std::string>("ABCDEFGHIJ0"))))
		{
		case 'A':

			try
			{
				rational1.setNumerator(inputInteger("\n\tEnter the value for the numerator: "));
				rational1.setDenominator(inputInteger("\n\tEnter the value for the denominator: "));
			}
			catch (Rational::ZeroDenominator)
			{
				std::cout << "\n\t\tEXCEPTIONAL ERROR: Cannot remove a Rational number, " + rational1.toString() + ", that contains a zero denominator value.\n";
			}

			break;

		case 'B':

			std::cout << "\n\tRational number R1: " << rational1 << "\n";

			break;

		case 'C':

			try
			{
				rational2.setNumerator(inputInteger("\n\tEnter the value for the numerator: "));
				rational2.setDenominator(inputInteger("\n\tEnter the value for the denominator: "));
			}
			catch (Rational::ZeroDenominator)
			{
				std::cout << "\n\t\tEXCEPTIONAL ERROR: Cannot remove a Rational number, " + rational2.toString() + ", that contains a zero denominator value.\n";
			}

			break;

		case 'D':

			std::cout << "\n\tRational number R2: " << rational2 << "\n";
			break;

		case 'E':

			std::cout << "\n\tR1 * R2: " << rational1 * rational2 << "\n";

			break;

		case 'F':

			std::cout << "\n\tR1 / R2: " << rational1 / rational2 << "\n";

			break;

		case 'G':

			std::cout << "\n\tR1 + R2: " << rational1 + rational2 << "\n";

			break;

		case 'H':

			std::cout << "\n\tR1 - R2: " << rational1 - rational2 << "\n";

			break;

		case 'I':

			std::cout << "\n\tR1 == R2: ";
			rational1 == rational2 ? std::cout << "true\n" : std::cout << "false\n";

			break;

		case 'J':

			std::cout << "\n\tR1 < R2: ";
			rational1 < rational2 ? std::cout << "true\n" : std::cout << "false\n";

			break;

		case '0': system("cls"); mainMenu(); return;
		}
		std::cout << "\n";
		system("pause");
	} while (true);
}