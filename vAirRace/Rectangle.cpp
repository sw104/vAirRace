//Rectangle class implemenation.
#include "Rectangle.h"

Rectangle::Rectangle(double width, double length)
{
    this->width(width);
    this->length(length);
}

double Rectangle::area() const
{
    return m_width * m_length;
}

double Rectangle::perimeter() const
{
    return 2 * m_width + 2 * m_length;
}

void Rectangle::width(double width)
{
    m_width = width;
}

double Rectangle::width() const
{
    return m_width;
}

void Rectangle::length(double length)
{
    m_length = length;
}

double Rectangle::length() const
{
    return m_length;
}