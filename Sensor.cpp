/* 
 * File:   Sensor.cpp
 * Author: vitaliy
 *
 * Created on July 15, 2017, 8:21 PM
 */

#include "Sensor.hpp"
#include <iostream>

using namespace std;


Sensor::Sensor()
{
    this->id = 0;
    this->name = "";   
}
Sensor::Sensor(int value, string s): id(value), name(s){}
Sensor::Sensor(int value, string s, Area *_area): id(value), name(s), area(_area){}
    
void Sensor::setType(const sensor_type& v)
{
    this->type = v;
}
void Sensor::setId(const int& value)
{
    this->id = value;
}
void Sensor::setName(const string& s)
{
    this->name = s;
}
    
const sensor_type& Sensor::getType(void)
{
    return this->type;
}
const int& Sensor::getId(void)
{
    return this->id;
}
const string& Sensor::getName(void)
{
    return this->name;
}

void Sensor::setArea(Area *a)
{
    area = a;
}
Area* Sensor::getArea()
{
    return area;
}
  
bool Sensor::operator< (const Sensor& other) const  
{  
    return this->id < other.id;  
} 
    
Sensor::~Sensor()
{
        
}


Temperature_sensor::Temperature_sensor(sensor_type t, int value, string s): Sensor(value, s)
{
    this->type = t;
}


Humidity_sensor::Humidity_sensor(sensor_type t, int value, string s): Sensor(value, s)
{
    this->type = t;
}





Area::Area(int _id, string _name) : id(_id), name(_name)
{
    sensors = new set<Sensor*, by_id>();
}

Area::Area() : id(0), name("")
{
    sensors = new set<Sensor*, by_id>();
}

void Area::setName(string newName)
{
    name = newName;
}

string Area::getName()
{
    return name;
}

void Area::addSensor(Sensor *newSensor)
{
    sensors->insert(newSensor);
    
    newSensor->setArea(this);
}

set<Sensor*, by_id>* Area::getSensors()
{
    return sensors;
}

void Area::removeSensor(Sensor *s)
{
    sensors->erase(s);
}

void Area::showSensors(void)
{
    cout << this->name << ": " << "количество датчиков = " << (*(sensors)).size() << endl;  
    
    for(set<Sensor*, by_id>::iterator it = (*(sensors)).begin(); it != (*(sensors)).end(); ++it)
    {
        cout << (*it)->getId() << " " << (*it)->getType() << " " << (*it)->getName() << endl;
    }
    cout << endl;
}

Area::~Area()
{
    delete sensors;
}