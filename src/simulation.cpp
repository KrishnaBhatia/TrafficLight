/**
 * @file simulation.cpp
 * @author Krishna Bhatia
 * @brief Main for traffic controller simulation
*/

#include "trafficcontroller.hpp"

#include <iostream>
#include <chrono>
#include <thread>

int main() {

   // Create traffic controller
   TrafficController controller;

   // register mock sensors
   controller.RegisterSensor(new MockSensor(kNorth));
   controller.RegisterSensor(new MockSensor(kSouth));
   controller.RegisterSensor(new MockSensor(kEast));
   controller.RegisterSensor(new MockSensor(kWest));

   // Start control operation
   controller.Operate();

   std::cout << "Starting Traffic Controller Simulation.." << std::endl;

   return 0;
}
