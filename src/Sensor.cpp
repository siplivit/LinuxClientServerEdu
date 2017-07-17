/* 
 * File:   Sensor.cpp
 * Author: vitaliy
 *
 * Created on July 15, 2017, 8:21 PM
 */

#include "Area.hpp"
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

void Temperature_sensor::setData(double t)
{
    data = t;
}
double Temperature_sensor::getData(void)
{
    return data;
}


Humidity_sensor::Humidity_sensor(sensor_type t, int value, string s): Sensor(value, s)
{
    this->type = t;
}

void Humidity_sensor::setData(double h)
{
    data = h;
}
double Humidity_sensor::getData(void)
{
    return data;
}
