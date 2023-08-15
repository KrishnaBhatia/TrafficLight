/**
 * @file mocksensor.cpp
 * @author Krishna Bhatia
 * @brief implentation  for Mock Sensor
*/

#include "mocksensor.hpp"

#include <cstdlib>

MockSensor::MockSensor(Direction direction) : direction_{direction} {

}

Direction MockSensor::GetDirection() const {

   return direction_;
}

bool MockSensor::HasWaitingVehicles() const {

   // retur a default false value
   return false;
}

bool MockSensor::IsValid() const {

   return true;
}
