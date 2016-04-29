//Rectangle class declaration - inherit from Object class.
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Object.h"

class Rectangle : Object
{
private:
    double m_width, m_length;

public:
    Rectangle(double width = 0, double length = 0);
    double area() const;
    double perimeter() const;

    //Accessors and setters.
    void width(double width);
    double width() const;
    void length(double length);
    double length() const;
};

#endif