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
    //Sanity check input.
    if (width > 0)
        m_width = width;
    else
        throw std::invalid_argument("Rectangle width cannot be negative");
}

double Rectangle::width() const
{
    return m_width;
}

void Rectangle::length(double length)
{
    //Sanity check input.
    if (length > 0)
        m_length = length;
    else
        throw std::invalid_argument("Rectangle length cannot be negative");
}

double Rectangle::length() const
{
    return m_length;
}
