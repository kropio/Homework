#include "C:\Users\VI\Downloads\pugixml-1.11\src\pugixml.hpp"
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include "stop.h"
#include "stop.cpp"
//#include "street.cpp"
#include "street.h"
//#include "transport.h"
#include "transport.cpp"

void maxStations(const std::vector<Transport> &tran){
    int max = 0;
    std::string rout;
    for(Transport t : tran){
        if(max < t.countOfStops()){
            max = t.countOfStops();
            rout = t.name();
        }
    }
    std::cout << rout << ": " << max << std::endl;
}

std::vector<std::string> split(const std::string& str, const std::string& div)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(div, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + div.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

int main(){
    std::string type, name = "";
    std::vector<float> coord(2);
    std::vector<std::string> location, routes, coord_str;
    std::vector<Street> streets;
    std::vector<Transport> bus, tram, troll;
    pugi::xml_document doc;
    
    std::ifstream stream("data.xml");
    pugi::xml_parse_result result = doc.load(stream);
    
    pugi::xml_node trnsprt = doc.child("dataset");

    for (pugi::xml_node tool: trnsprt.children("transport_station")){

        for (pugi::xml_node child: tool.children()){
            std::string ch = child.name();
            if (ch == "number"){
                //std::cout << child.child_value() << " ";
            }
            if (ch == "type_of_vehicle"){
                type = child.child_value();
            }
            if (ch == "the_official_name"){
                name = child.child_value();
                
            }  
            if (ch == "location"){
                location = split(child.child_value(), ",");              
            } 
            if (ch == "routes"){
                routes = split(child.child_value(), ",");
                /*for(std::string a:routes){
                    std::cout << a << " ";
                }*/
            } 
            if (ch == "coordinates"){
                coord_str = split(child.child_value(), ",");
                coord[0] = std::stof(coord_str[0]);
                coord[1] = std::stof(coord_str[1]);
                /*for(float i : coord)
                    std::cout << i << " ";
                std::cout << std::endl;*/
            } 
                
            //std::cout << child.child_value() << " ";
        }

        if (type == "Трамвай"){
            for(std::string rout : routes){
                bool check = true;
                for(Transport T : tram){
                    if(T.name() == rout){
                        Stop stop(coord[0], coord[1], name);
                        T.addStop(stop);
                        check = false;
                        //std::cout << T.countOfStops() << " ";
                        //T.allStops();
                    }
                }
                if(check){
                    tram.push_back(Transport(rout, Stop(coord[0], coord[1], name)));
                    //(tram.end() - 1)->allStops();
                }
            }
        }
        else if(type == "Автобус"){
            for(std::string rout:routes){
                bool check = true;
                for(Transport T:bus){
                    if(T.name() == rout){
                        Stop stop(coord[0], coord[1], name);
                        T.addStop(stop);
                        check = false;
                    }
                }
                if(check){
                    bus.push_back(Transport(rout, Stop(coord[0], coord[1], name)));
                }
            }
        }
        else if(type == "Троллейбус"){
            for(std::string rout:routes){
                bool check = true;
                for(Transport T:troll){
                    if(T.name() == rout){
                        Stop stop(coord[0], coord[1], name);
                        T.addStop(stop);
                        check = false;
                    }
                }
                if(check){
                    troll.push_back(Transport(rout, Stop(coord[0], coord[1], name)));
                }
            }
        }

        //std::cout << std::endl;
    }

    maxStations(tram);
    maxStations(bus);
    maxStations(troll);
    

    return 0;
} 