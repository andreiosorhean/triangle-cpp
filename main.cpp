#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <limits>

// Read 3 positive int values that form a valid triangle from the keyboard.
// Re-prompts until the input is valid.
static void readSides(int &a, int &b, int &c) {
    while (true) {
        std::cout << "Enter three integer sides for the triangle: ";
        if (!(std::cin >> a >> b >> c)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter three integers.\n";
            continue;
        }
        // Validate before instantiation
        if (a <= 0 || b <= 0 || c <= 0) {
            std::cout << "All sides must be positive integers. Try again.\n";
            continue;
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            std::cout << "The values " << a << ", " << b << ", " << c
                      << " do not form a valid triangle. Try again.\n";
            continue;
        }
        break;
    }
}

int main() {
    int a, b, c;

    // Read and validate sides before instantiating the object
    readSides(a, b, c);

    Triangle t(a, b, c);

    std::cout << "\nTriangle sides: a=" << t.getA()
              << ", b=" << t.getB()
              << ", c=" << t.getC() << "\n";

    if (t.isTriangle())
        std::cout << "The sides form a valid triangle.\n";
    else
        std::cout << "The sides do NOT form a valid triangle.\n";

    std::cout << "Perimeter: " << t.perimeter() << "\n";
    std::cout << std::fixed << std::setprecision(4)
              << "Area: " << t.area() << "\n";
    t.checkRightAngle();

    // Demonstrate setter with a valid new value (a stays between 1 and b+c-1)
    int newA = t.getA() + 1;
    std::cout << "\nAttempting to change side a from " << t.getA()
              << " to " << newA << "...\n";
    t.setA(newA);
    std::cout << "Side a is now: " << t.getA() << "\n";

    // Demonstrate setter with an invalid new value (setter should keep old value)
    std::cout << "Attempting to change side b to 0 (invalid)...\n";
    t.setB(0);
    std::cout << "Side b is still: " << t.getB() << "\n";

    return 0;
}
