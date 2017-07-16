/* 
 * File:   Area.cpp
 * Author: vitaliy
 *
 * Created on July 15, 2017, 8:21 PM
 */

#include "Sensor.hpp"
#include "Area.hpp"
#include <iostream>



bool by_id::operator ()(Sensor *a, Sensor *b) const
{
    return a->getId() < b->getId();
}


Area::Area(int _id, std::string _name) : id(_id), name(_name)
{

}

Area::Area() : id(0), name("")
{

}

void Area::setName(std::string newName)
{
    name = newName;
}

std::string Area::getName()
{
    return name;
}

void Area::addSensor(Sensor *newSensor)
{
    sensors.insert(newSensor);
    
    newSensor->setArea(this);
}

const std::set<Sensor*, by_id> & Area::getSensors(void)
{
    return sensors;
}

void Area::removeSensor(Sensor *s)
{
    sensors.erase(s);
}

void Area::showSensors(void)
{
    std::cout << this->name << ": " << "количество датчиков = " << sensors.size() << std::endl;  
    
    for(std::set<Sensor*, by_id>::iterator it = sensors.begin(); it != sensors.end(); ++it)
    {
        std::cout << (*it)->getId() << " " << (*it)->getType() << " " << (*it)->getName() << std::endl;
    }
    std::cout << std::endl;
}

Area::~Area()
{

}
