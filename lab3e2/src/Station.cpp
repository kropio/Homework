#include "Station.h"

Station::Station(std::vector<std::string>& data)
{
    std::vector<std::string> arr_of_streets;
    std::string street;

    for (unsigned int i = 0; i < data[1].size(); i++)
    {
        if (data[1][i] == ',')
        {
            i++;
            arr_of_streets.push_back(street);
            street = "";
        }
        else
        {
            street += data[1][i];
        }
    }
    if (street != "")
    {
        arr_of_streets.push_back(street);
    }

    std::vector<std::string> arr_of_routes;
    std::string route;
    for (unsigned int i = 0; i < data[2].size(); i++)
    {
        if (data[2][i] == ',' || data[2][i] == '.')
        {
            arr_of_routes.push_back(route);
            route = "";
        }
        else
        {
            route += data[2][i];
        }
    }
    if (route != "")
    {
        arr_of_routes.push_back(route);
    }

    std::string coordinate;
    double x, y;
    for (unsigned int i = 0; i < data[3].size(); i++)
    {
        if (data[3][i] == ',')
        {
            x = std::stod(coordinate);
            coordinate = "";
        }
        else
        {
            coordinate += data[3][i];
        }
    }
    y = std::stod(coordinate);
    Point p = Point(x , y);

    type_of_vehicle = data[0];
    streets = arr_of_streets;
    routes = arr_of_routes;
    coordinates = p;
}

int Station::getSizeStr() const
{
    return streets.size();
}

int Station::getSizeRte() const
{
    return routes.size();
}

std::string Station::getStreet(int number) const
{
    return streets[number];
}

std::string Station::getRoute(int number) const
{
    return routes[number];
}

std::string Station::getVehicle() const
{
    return type_of_vehicle;
}

Point Station::getCoord() const
{
    return coordinates;
}

double Station::distBetweenSt(const Station& other) const
{
    return sqrt(pow(coordinates.getX() - other.getCoord().getX(), 2) + pow(coordinates.getY() - other.getCoord().getY(), 2));
}
