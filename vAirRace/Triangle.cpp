//Triangle class implemenation.
#include "Triangle.h"

Triangle::Triangle(double width, double height)
{
    this->width(width);
    this->height(height);
}

double Triangle::area() const
{
    return 0.5 * m_width * m_height;
}

double Triangle::perimeter() const
{
    //Calulate sloped height using Pythagoras's therum. 
    double slope = sqrt(pow(m_height, 2) + pow(m_width / 2, 2));
    return 2 * slope + m_width;
}

void Triangle::width(double width)
{
    //Sanity check input:
    if (width > 0)
        m_width = width;
    else
        throw std::invalid_argument("Triangle width cannot be negative");
}

double Triangle::width() const
{
    return m_width;
}

void Triangle::height(double height)
{
    //Sanity check input:
    if (height > 0)
        m_height = height;
    else
        throw std::invalid_argument("Triangle height cannot be negative");
}

double Triangle::height() const
{
    return m_height;
}
