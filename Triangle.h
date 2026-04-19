#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
private:
    int a, b, c;

    static bool sidesFormTriangle(int sideA, int sideB, int sideC);

public:
    Triangle(int a, int b, int c);

    int getA() const;
    int getB() const;
    int getC() const;

    bool setA(int a);
    bool setB(int b);
    bool setC(int c);

    bool isTriangle() const;

    double area() const;
    int perimeter() const;

    void checkRightAngle() const;
};

#endif // TRIANGLE_H
