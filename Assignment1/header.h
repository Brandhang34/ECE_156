#pragma once
#ifndef MODARITH_H
#define calc_mod

#include <iostream>
#include <math.h>
using namespace std;

//template<class Type>
class Zm {
public:
	Zm();
	Zm(int mod, int val);
	void operator= (const Zm& b);
	Zm operator+(const Zm& b);
    Zm operator-(const Zm& b);
    Zm operator*(const Zm& b);
	friend ostream& operator<<(ostream& output, const Zm& c);
	friend istream& operator>>(istream& input, Zm& c);
	int getValue();
	int getValue() const;
	void setValue(int val);

private:
	int m, value;
	int reduce(int val);
};

//template<class Type>
Zm::Zm() {
	this->m = 8;	// assume default modulus is 8
	this->value = 0;
}

int Zm::reduce(int val) {
	return (val - floor(val / m) * m);
}

int Zm::getValue() {
	return this->value;
}

int Zm::getValue() const {
	return this->value;
}

void Zm::setValue(int val) {
	this->value = reduce(val);
}

Zm::Zm(int mod, int val) {
	this->m = mod;
	this->value = reduce(val);
}

void Zm::operator=(const Zm& b)
{
	this->value = b.getValue();
}

Zm Zm::operator+(const Zm& b)
{
	Zm c(this->m, reduce(this->value + b.getValue()));
	return c;
}

Zm Zm::operator-(const Zm& b)
{
	Zm c(this->m, reduce(this->value - b.getValue()));
	return c;
}

Zm Zm::operator*(const Zm& b)
{
	Zm c(this->m, reduce(this->value * b.getValue()));
	return c;
}

ostream& operator<<(ostream& output, const Zm& c) {
	output << c.getValue();
	return output;
}

istream& operator>>(istream& input, Zm& c) {
	int val(0);
	input >> val;
	c.setValue(val);
	return input;
}

#endif // !MODARITH_H
