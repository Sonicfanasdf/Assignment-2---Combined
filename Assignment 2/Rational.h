#pragma once
#include <iostream>
#include <algorithm>
#include <string>

// Credit: Thanh Tran & Otoniel Torres Bernal - Rational

char inputChar(std::string prompt, std::string options);
int inputInteger(std::string prompt);
void mainMenu();

// A rational number is a number that is expressed as the ratio of two integers, where the denominator should not be equal to zero.
// Rational class is designed to expressed the rational number in the form of (numerator) / (denominator) 
class Rational
{
private:
	int numerator;
	int denominator;

	//PreCondition: integer a and b parameter
	//PostCondition: return the greatest common divisor between a and b
	int gcd(int a, int b);

	// Pre-Condition: no parameters. 
	// Post-Condition: no return. If the denominator is negative, then the negative sign is moved to the numerator and reduce if there is a GCD (greatest common divisor). 
	void normalize();

public:

	// ZeroDenominator is used to throw an exception if the denominator is zero.
	class ZeroDenominator
	{
	private:
		std::string rational;
	public:
		ZeroDenominator()
		{}

		ZeroDenominator(Rational r)
		{
			rational = r.toString();
		}

		std::string toString()
		{
			return rational;
		}
	};

	// Pre-Condition: no parameters.
	// Post-Condition: no return. A no argument initializer constructor that sets the numerator to 0 and the denominator to 1.
	Rational();

	// Pre-Condition: parameters int newN, int newD are assigned to numerator and denominator respictively.
	// Post-Condition: no return. An exception is thrown if the denominator is zero.
	Rational(int, int);

	// PreCondition: NA
	// PostCondition: returns a string expression of the numerator/denominator.  
	std::string toString();

	// PreCondition: NA
	// PostCondition: return the numerator private member
	int getNumerator() const;

	// PreCondition: NA
	// PostCondition: return the denominator private member
	int getDenominator() const;

	// PreCondition: an interger value
	// PostCondition: set the values of the numerator private member
	void setNumerator(int);

	// PreCondition: an interger value
	// PostCondition: set the values of the denominator private member
	void setDenominator(int);

	// PreCondition: 2 Rational objects
	// PostCondition:  return a the object that is the result of the multiplication of the 2 rational objects
	friend Rational operator * (const Rational& obj1, const Rational& obj2);

	// PreCondition: 2 Rational objects
	// PostCondition:  return a the object that is the result of the division of the 2 rational objects
	friend Rational operator /(const Rational& obj1, const Rational& obj2);

	// PreCondition: 2 Rational objects
	// PostCondition:  return a the object that is the result of sum of the 2 rational objects
	friend Rational operator +(const Rational& obj1, const Rational& obj2);

	// PreCondition: 2 Rational objects
	// PostCondition: return a the object that is the difference of the 2 rational objects
	friend Rational operator -(const Rational& obj1, const Rational& obj2);

	// PreCondition: 2 Rational objects
	// PostCondition:  return a flag that compares two Rational numbers are equal
	friend bool operator ==(const Rational& obj1, const Rational& obj2);

	// PreCondition: 2 Rational objects
	// PostCondition: return a flag which indicate one is lesser than another.
	friend bool operator <(const Rational& obj1, const Rational& obj2);

	// PreCondition: a ostream object and a Rational object
	// PostCondition: return the object that used for display 
	friend std::ostream& operator << (std::ostream& out, Rational obj);

	//PreCondition: NA
	//PostCondition: no return. Menu for Rational(Part 3)
	void rational_Menu();

};
