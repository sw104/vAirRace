//Trangle class declaration - inherit from Object class.
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object.h"
#include <cmath>

class Triangle : Object
{
private:
    double m_width, m_height; //Width of traingle base and perpendicular height.

public:
    Triangle(double width = 0, double height = 0);

    double area() const;
    double perimeter() const;

    //Accessors and setters.
    void width(double width);
    double width() const;
    void height(double height);
    double height() const;

};

#endif
