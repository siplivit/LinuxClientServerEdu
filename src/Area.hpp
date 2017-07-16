/* 
 * File:   Area.hpp
 * Author: vitaliy
 *
 * Created on July 16, 2017, 11:30 PM
 */

#ifndef AREA_HPP
#define AREA_HPP

#include <string>
#include <set>

class Sensor;

struct by_id
{
    bool operator ()(Sensor *a, Sensor *b) const;
};

class Area
{
private:
protected:
    int id;
    std::string name;
    std::set<Sensor*, by_id> sensors;
public:
    Area(int _id, std::string _name);
    Area();
    
    void setName(std::string newName);
    std::string getName();
    void addSensor(Sensor *newSensor);
    const std::set<Sensor*, by_id> & getSensors();
    void removeSensor(Sensor *s);
    
    void showSensors(void);
    
    virtual ~Area();
};

#endif /* AREA_HPP */

