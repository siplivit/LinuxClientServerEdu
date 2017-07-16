/* 
 * File:   Sensor.hpp
 * Author: vitaliy
 *
 * Created on July 15, 2017, 8:21 PM
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>

class Area;

enum sensor_type
{
    NOTDEFINED = 0,
    TEMPERATURE,
    HUMIDITY,
    ALTITUDE,
    PRESSURE         
};

class Sensor
{
private:
protected:
    int id;
    sensor_type type;
    std::string name;
    Area *area;
public:
    Sensor();
    Sensor(int value, std::string s);
    Sensor(int value, std::string s, Area *_area);
    
    void setType(const sensor_type& v);
    void setId(const int& value);
    void setName(const std::string& s);
    
    const sensor_type& getType(void);
    const int& getId(void);
    const std::string& getName(void);
    void setArea(Area *a);
    Area* getArea();
    
    bool operator< (const Sensor& other) const;
    
    virtual ~Sensor();
};

class Temperature_sensor: public Sensor
{
private:
protected:
public:
    Temperature_sensor(sensor_type t, int value, std::string s);
};

class Humidity_sensor: public Sensor
{
private:
protected:
public:
    Humidity_sensor(sensor_type t, int value, std::string s);
};

#endif /* SENSOR_HPP */

