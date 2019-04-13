/*
*  Rational.cpp
*/
#include "Rational.h"

#include <iostream>

using namespace std;

// ����������� �� ������������
Rational::Rational() {
	numer = 0;
	denom = 1;
}


// ����������� � 2 ����������
Rational::Rational(int n, int d) {
	if (n == 0 || d == 0) {
		numer = 0;
		denom = 1;
	}
	else {
		int g = gcd(abs(n), abs(d));
		if (n > 0 && d > 0 || n < 0 && d < 0) {
			numer = abs(n) / g;
			denom = abs(d) / g;
		}
		else {
			numer = -abs(n) / g;
			denom = abs(d) / g;
		}
	}
}


// �������� �� ��������
int Rational::getNumerator() const {
	return numer;
}

// �������� �� ����������
int Rational::getDenominator() const {
	return denom;
}

// ������� �� ���������
void Rational::print() const {
	cout << getNumerator() << '/' << getDenominator();
}

// ������� (������� �� �������) ���� ���������
void Rational::read() {
	// ������: 2/5
	cin >> numer;
	cin.ignore();
	cin >> denom;
}


// ���-����� ��� �������
int Rational::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


// �������� �� 2 ���������� �����
Rational add(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator()
		+ p.getDenominator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// ��������� �� 2 ���������� �����
Rational subtract(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator()
		- p.getDenominator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// ��������� �� 2 ���������� �����
Rational multiply(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getNumerator(),
		p.getDenominator() * q.getDenominator());
}

// ������� �� 2 ���������� �����
Rational divide(Rational p, Rational q) {
	return Rational(p.getNumerator() * q.getDenominator(),
		p.getDenominator() * q.getNumerator());
}

