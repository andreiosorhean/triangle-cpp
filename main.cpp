#include <iostream>
#include "Triangle.h"

// Returns true when a, b, c can form a valid triangle.
static bool sidesAreValid(int a, int b, int c) {
    return (a > 0 && b > 0 && c > 0) &&
           (a + b > c) &&
           (a + c > b) &&
           (b + c > a);
}

int main() {
    int a, b, c;

    // --- Pre-instantiation validation ---
    // Read sides from the keyboard and re-prompt until a valid triangle is entered.
    std::cout << "=== Triangle Application ===\n\n";
    std::cout << "Enter three integer sides for the triangle.\n";

    do {
        std::cout << "Side a: ";
        std::cin >> a;
        std::cout << "Side b: ";
        std::cin >> b;
        std::cout << "Side c: ";
        std::cin >> c;

        if (!sidesAreValid(a, b, c)) {
            std::cout << "Invalid sides: they do not form a valid triangle. "
                         "Please try again.\n\n";
        }
    } while (!sidesAreValid(a, b, c));

    // --- Instantiate the Triangle object ---
    Triangle t(a, b, c);

    std::cout << "\nTriangle created with sides: a=" << t.getA()
              << ", b=" << t.getB() << ", c=" << t.getC() << "\n";

    // --- Test isTriangle() after instantiation ---
    if (t.isTriangle()) {
        std::cout << "isTriangle() confirms: the sides form a valid triangle.\n";
    } else {
        std::cout << "isTriangle() says: NOT a valid triangle.\n";
    }

    // --- Display properties ---
    std::cout << "\nPerimeter : " << t.perimeter() << "\n";
    std::cout << "Area      : " << t.area()      << "\n";

    // --- Check for right angle ---
    t.checkRightAngle();

    // --- Demonstrate setters (with built-in validation) ---
    std::cout << "\n--- Setter demonstration ---\n";

    // Attempt an invalid change (side = -5)
    std::cout << "Attempting to set side a = -5 (invalid):\n";
    if (!t.setA(-5)) {
        std::cout << "setA(-5) rejected: keeping old value " << t.getA() << ".\n";
    }

    // Attempt a valid change
    int newA = t.getA();
    std::cout << "Attempting to set side a = " << newA << " (same value, valid):\n";
    if (t.setA(newA)) {
        std::cout << "setA(" << newA << ") accepted. Side a is now: " << t.getA() << "\n";
    }

    return 0;
}
