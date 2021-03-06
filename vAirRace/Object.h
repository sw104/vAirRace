//Object abstract base class declaration.
#ifndef OBJECT_H
#define OBJECT_H

#include <stdexcept>

class Object  //Object position class.
{

private:
    long double m_x, m_y;   //Object co-ordinates.
    double m_altitude;  //Object altitude.
    double m_bank;   //Object bank angle - negative for left positive for right (in degrees).
    double m_heading;//Object heading.
    double m_pitch;  //Object pitch - positive for up, negaitive for down (in degrees).

public:
    //Abstract methods:
    virtual double area() const = 0;  //Area/Surface area of object.
    virtual bool isTouching(Object*) = 0;   //Is the current object touching the given object.

    //Implemented methods:
    virtual bool isBetween(Object* object1, Object* object2);   //Is current object between the two given objects - no buffer tolarence is built in.

    //Accessors and setters:
    void altitude(double altitude);
    double altitude() const;
    void bank(double bank);
    double bank() const;
    void heading(double heading);
    double heading() const;
    void pitch(double pitch);
    double pitch() const;
    virtual void position(long double x, long double y);
    void x(long double x);
    long double x() const;
    void y(long double y);
    long double y() const;

};

#endif
