/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vitaliy
 *
 * Created on July 15, 2017, 12:05 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

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
    string name;
public:
    Sensor()
    {
        this->id = 0;
        this->name = "";
    }
    Sensor(int value, string s): id(value), name(s)
    {

    }
    
    void setType(const sensor_type& v)
    {
        this->type = v;
    }
    void setId(const int& value)
    {
        this->id = value;
    }
    void setName(const string& s)
    {
        this->name = s;
    }
    
    const sensor_type& getType(void)
    {
        return this->type;
    }
    const int& getId(void)
    {
        return this->id;
    }
    const string& getName(void)
    {
        return this->name;
    }
    
    virtual ~Sensor()
    {
        
    }
};

class Temperature_sensor: public Sensor
{
private:
protected:
public:
    Temperature_sensor(sensor_type t, int value, string s): Sensor(value, s)
    {
        this->type = t;
    }
};

class Humidity_sensor: public Sensor
{
private:
protected:
public:
    Humidity_sensor(sensor_type t, int value, string s): Sensor(value, s)
    {
        this->type = t;
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    Sensor *temp_sens_kitchen = new Temperature_sensor(TEMPERATURE, 73967465, "Temperature kitchen");
    Sensor *temp_sens_bedroom = new Temperature_sensor(TEMPERATURE, 96873564, "Temperature bedroom");
    Sensor *temp_sens_hall    = new Temperature_sensor(TEMPERATURE, 68736453, "Temperature hall");
    
    Sensor *humid_sens_kitchen = new Humidity_sensor(HUMIDITY, 65839807, "Humidity kitchen");
    Sensor *humid_sens_bedroom = new Humidity_sensor(HUMIDITY, 63547586, "Humidity bedroom");
    Sensor *humid_sens_hall    = new Humidity_sensor(HUMIDITY, 23768463, "Humidity hall");
    
    vector<Sensor*> v;
    
    v.push_back(temp_sens_kitchen);
    v.push_back(temp_sens_bedroom);
    v.push_back(temp_sens_hall);
    
    v.push_back(humid_sens_kitchen);
    v.push_back(humid_sens_bedroom);
    v.push_back(humid_sens_hall);
    
    vector<Sensor*>::iterator it;
    
    for(it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it)->getName() << " " << (*it)->getId() << (*it)->getType()  << endl;
    }

    return 0;
}

