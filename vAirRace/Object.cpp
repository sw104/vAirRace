//Object class implementation.
#include "Object.h"

void Object::altitude(double altitude)
{
    m_altitude = altitude;
}

double Object::altitude() const
{
    return m_altitude;
}

void Object::bank(double bank)
{
    m_bank = bank;
}

double Object::bank() const
{
    return m_bank;
}

void Object::heading(double heading)
{
    m_heading = heading;
}

double Object::heading() const
{
    return m_heading;
}

void Object::pitch(double pitch)
{
    m_pitch = pitch;
}

double Object::pitch() const
{
    return m_pitch;
}

void Object::position(long double x, long double y)
{
    this->x(x);
    this->y(y);
}

void Object::x(long double x)
{
    m_x = x;
}

long double Object::x() const
{
     return m_x;
}

void Object::y(long double y)
{
    m_y = y;
}

long double Object::y() const
{
    return m_y;
}