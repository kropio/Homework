#ifndef STATION_H_
#define STATION_H_
#include <vector>
#include <string>
#include <cmath>
#include "Point.h"

class Station{
	private:
	    std::string type_of_vehicle;
	    std::vector<std::string> streets;
	    std::vector<std::string> routes;
	    Point coordinates;
	
	public:
	    Station(std::vector<std::string>&);
	    int getSizeStr() const;
	    int getSizeRte() const;
	    Point getCoord() const;
	    double distBetweenSt(const Station&) const;
	    std::string getStreet(int) const;
	    std::string getRoute(int) const;
	    std::string getVehicle() const;
};

#endif /* STATION_H_ */
