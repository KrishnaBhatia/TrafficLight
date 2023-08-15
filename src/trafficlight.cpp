/**
 * @file trafficlight.cpp
 * @author Krishna Bhatia
 * @brief Class implementation for TrafficLight
*/

#include "trafficlight.hpp"

#include <chrono>

TrafficLight::TrafficLight() {}
  
TrafficLight::TrafficLight(Direction direction, bool isTurning, int minTime, int maxTime)
   : direction_(direction),
     isTurning_(isTurning),
     minTime_(minTime),
     maxTime_(maxTime) {
}

void TrafficLight::Activate() {

    isActive_ = true;

   // Record start time
   start_ = std::chrono::system_clock::now();
}

void TrafficLight:: Deactivate() {

   isActive_ = false;
}

bool TrafficLight::IsActive() const {

   return isActive_;
}

int TrafficLight::GetDuration() const {

   std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

   return std::chrono::duration_cast<std::chrono::seconds>(end - start_).count();
}

Direction TrafficLight::GetDirection() const {

   return direction_;
}

bool TrafficLight::IsTurning() const {

   return isTurning_;
}

int TrafficLight::GetMinTime() const {

   return minTime_;
}

int TrafficLight::GetMaxTime() const {

 return maxTime_;
}
