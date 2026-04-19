#include "Triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(int a, int b, int c) : a(a), b(b), c(c) {}

// Private helper: true when the three positive sides satisfy the triangle inequality.
bool Triangle::sidesFormTriangle(int sideA, int sideB, int sideC) {
    return (sideA > 0 && sideB > 0 && sideC > 0) &&
           (sideA + sideB > sideC) &&
           (sideA + sideC > sideB) &&
           (sideB + sideC > sideA);
}

int Triangle::getA() const { return a; }
int Triangle::getB() const { return b; }
int Triangle::getC() const { return c; }

// Setters validate the new side and return true on success, false otherwise.
// The stored value is unchanged when validation fails.
bool Triangle::setA(int newA) {
    if (sidesFormTriangle(newA, b, c)) {
        a = newA;
        return true;
    }
    return false;
}

bool Triangle::setB(int newB) {
    if (sidesFormTriangle(a, newB, c)) {
        b = newB;
        return true;
    }
    return false;
}

bool Triangle::setC(int newC) {
    if (sidesFormTriangle(a, b, newC)) {
        c = newC;
        return true;
    }
    return false;
}

// Returns true if the three sides satisfy the triangle inequality.
bool Triangle::isTriangle() const {
    return sidesFormTriangle(a, b, c);
}

// Uses Heron's formula.
double Triangle::area() const {
    double s = perimeter() / 2.0;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

int Triangle::perimeter() const {
    return a + b + c;
}

// A triangle has a 90-degree angle when the Pythagorean theorem holds
// for one of its side combinations.
void Triangle::checkRightAngle() const {
    int aa = a * a, bb = b * b, cc = c * c;
    if (aa + bb == cc || aa + cc == bb || bb + cc == aa) {
        std::cout << "The triangle is a right triangle (contains a 90-degree angle).\n";
    } else {
        std::cout << "The triangle is NOT a right triangle.\n";
    }
}
