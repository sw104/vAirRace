//GeoPosition template class.
#ifndef GEOPOSITION_H
#define GEOPOSITION_H

template<typename t_coordinate>
class GeoPosition
{
protected:
    t_coordinate m_lat, m_lon;
public:
    GeoPosition();
    GeoPosition(t_coordinate lat, t_coordinate lon);

    //Accessors and setters.
    void lat(t_coordinate lat);
    t_coordinate lat() const;
    void lon(t_coordinate lon);
    t_coordinate lon() const;
};

//GeoPosition class implementation.

template<typename t_coordinate>
GeoPosition<t_coordinate>::GeoPosition()
{}

template<typename t_coordinate>
GeoPosition<t_coordinate>::GeoPosition(t_coordinate lat, t_coordinate lon)
{
    lat(lat);
    lon(lon);
}

template<typename t_coordinate>
void GeoPosition<t_coordinate>::lat(t_coordinate lat)
{
    m_lat = lat;
}

template<typename t_coordinate>
t_coordinate GeoPosition<t_coordinate>::lat() const
{
    return m_lat;
}

template<typename t_coordinate>
void GeoPosition<t_coordinate>::lon(t_coordinate lon)
{
    m_lon = lon;
}

template<typename t_coordinate>
t_coordinate GeoPosition<t_coordinate>::lon() const
{
    return m_lon;
}

#endif