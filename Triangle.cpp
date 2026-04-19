#include "Triangle.h"
#include <cmath>
#include <iostream>

// A side is valid if it is positive
static bool positiveSide(int x) {
    return x > 0;
}

// Three sides form a triangle if all are positive and each side is less than
// the sum of the other two
bool Triangle::validSides(int a, int b, int c) {
    return positiveSide(a) && positiveSide(b) && positiveSide(c) &&
           (a + b > c) && (a + c > b) && (b + c > a);
}

Triangle::Triangle(int a, int b, int c) : a(a), b(b), c(c) {}

int Triangle::getA() const { return a; }
int Triangle::getB() const { return b; }
int Triangle::getC() const { return c; }

void Triangle::setA(int newA) {
    if (validSides(newA, b, c))
        a = newA;
}

void Triangle::setB(int newB) {
    if (validSides(a, newB, c))
        b = newB;
}

void Triangle::setC(int newC) {
    if (validSides(a, b, newC))
        c = newC;
}

bool Triangle::isTriangle() const {
    return validSides(a, b, c);
}

int Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::area() const {
    double s = perimeter() / 2.0;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::checkRightAngle() const {
    long long aa = static_cast<long long>(a) * a;
    long long bb = static_cast<long long>(b) * b;
    long long cc = static_cast<long long>(c) * c;
    if (aa + bb == cc || aa + cc == bb || bb + cc == aa)
        std::cout << "The triangle has a 90-degree angle (right triangle).\n";
    else
        std::cout << "The triangle does not have a 90-degree angle.\n";
}
