// modArith.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    int modulus = 4;
    Zm a(modulus, 0), b(modulus, 0), c(modulus, 0);

    cout << "Enter two integers and the program will add them modulo " << modulus << ": ";
    cin >> a >> b;

	// Addition
    c = a + b;
    cout << a << " + " << b << " = " << c << " over Z" << modulus << endl;

	// Subtraction
	c = a - b;
	cout << a << " - " << b << " = " << c << " over Z" << modulus << endl;

	// Multiplication
	c = a * b;
	cout << a << " * " << b << " = " << c << " over Z" << modulus << endl;
}
