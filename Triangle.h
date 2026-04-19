#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
private:
    int a, b, c;

    static bool validSides(int a, int b, int c);

public:
    Triangle(int a, int b, int c);

    // Getters
    int getA() const;
    int getB() const;
    int getC() const;

    // Setters (keep old value if new one is not valid)
    void setA(int a);
    void setB(int b);
    void setC(int c);

    // Returns true if a, b, c form a valid triangle
    bool isTriangle() const;

    // Returns the perimeter
    int perimeter() const;

    // Returns the area using Heron's formula
    double area() const;

    // Prints a message if the triangle has a 90-degree angle
    void checkRightAngle() const;
};

#endif // TRIANGLE_H
