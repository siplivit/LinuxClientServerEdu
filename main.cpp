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
#include <set>

#include "src/Sensor.hpp"
#include "src/Area.hpp"

using namespace std;


int main(int argc, char** argv) {
    
    Area *kitchenArea = new Area(1,"Кухня");
    Area *bedroomArea = new Area(2,"Спальня");
    Area *bathroomArea = new Area(3,"Ванная");
    Area *hallArea = new Area(4,"Коридор");
    
    Temperature_sensor *temp_sens_1 = new Temperature_sensor(TEMPERATURE, 73967465, "Temperature");
    Temperature_sensor *temp_sens_2 = new Temperature_sensor(TEMPERATURE, 96873564, "Temperature");
    Temperature_sensor *temp_sens_3    = new Temperature_sensor(TEMPERATURE, 68736453, "Temperature");
    
    Humidity_sensor *humid_sens_1 = new Humidity_sensor(HUMIDITY, 65839807, "Humidity");
    Humidity_sensor *humid_sens_2 = new Humidity_sensor(HUMIDITY, 63547586, "Humidity");
    Humidity_sensor *humid_sens_3    = new Humidity_sensor(HUMIDITY, 23768463, "Humidity");
    
    temp_sens_3->setTemperature(25.3);
    
    kitchenArea->addSensor(temp_sens_1);
    kitchenArea->addSensor(humid_sens_1);
    bedroomArea->addSensor(temp_sens_2);
    bedroomArea->addSensor(humid_sens_2);
    bathroomArea->addSensor(temp_sens_3);
    hallArea->addSensor(humid_sens_3);
    
    for(std::set<Sensor*, by_id>::iterator it = bathroomArea->getSensors().begin(); it != bathroomArea->getSensors().end(); ++it)
    {
        Temperature_sensor * temp_tmp = dynamic_cast<Temperature_sensor*>(*it);
        if(temp_tmp)
        {
            std::cout << temp_tmp->getTemperature()<< endl;
        }
    }
    
    kitchenArea->showSensors();
    bedroomArea->showSensors();
    bathroomArea->showSensors();
    hallArea->showSensors();
    
    vector<Sensor*> v;
    
    v.push_back(temp_sens_1);
    v.push_back(temp_sens_2);
    v.push_back(temp_sens_3);
    
    v.push_back(humid_sens_1);
    v.push_back(humid_sens_2);
    v.push_back(humid_sens_3);
    
    for(vector<Sensor*>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it)->getId() << " " << (*it)->getType() << " " << (*it)->getName() << " " << (*it)->getArea()->getName()  << endl;
    }

    delete kitchenArea;
    delete bedroomArea;
    delete bathroomArea;
    delete hallArea;
    
    delete temp_sens_1;
    delete temp_sens_2;
    delete temp_sens_3;
    delete humid_sens_1;
    delete humid_sens_2;
    delete humid_sens_3;
    
    return 0;
}

