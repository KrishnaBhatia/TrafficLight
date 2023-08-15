/**
 * @file trafficcontroller.cpp
 * @author Krishna Bhatia
 * @brief Implementation for TrafficController
*/

#include "trafficcontroller.hpp"
#include <stdexcept>
#include <iostream>
#include <thread>

TrafficController::TrafficController() {

   InitializeLights();
   current_step_ = 0;
}

void TrafficController::Operate() {

   while (true) {
      UpdateLights();

     std::cout << "Cuurent Step " << current_step_ << std::endl;

     TrafficLight* current = GetCurrentActiveLight();
     
     if (current != NULL) {
         int duration = CalculateDuration(*current);

         std::cout << "Total Duration of Lights " << duration << " seconds" << std::endl;

         current->Activate();
         PrintLightStatus();

         std::this_thread::sleep_for(std::chrono::seconds(duration));
      }
 
      IncrementStep();
   }
}

void TrafficController::RegisterSensor(TrafficSensorInterface* sensor) {

   // Validate sensor is not NULL
   if (sensor == nullptr) {
      throw std::invalid_argument("Sensor is nullptr");
   }

   // Validate reported status
   if (sensor->IsValid() == false) {
      throw std::invalid_argument("Sensor report invalid");
   }

   // Get sensor direction
   const Direction direction = sensor->GetDirection();

   // Check direction not already registered
   if (sensors_.count(direction) != 0) {
      throw std::invalid_argument("Sensor already registered for direction");
   }

   // Insert sensor into map
   sensors_[direction] = sensor;
}

void TrafficController::InitializeLights() {

   lights_[0] = TrafficLight(kNorth, true, 10, 60);
   lights_[1] = TrafficLight(kNorth, false, 30, 120);
   lights_[2] = TrafficLight(kSouth, true, 10, 60);
   lights_[3] = TrafficLight(kSouth, false, 30, 120);
   lights_[4] = TrafficLight(kEast, true, 10, 30);
   lights_[5] = TrafficLight(kEast, false, 30, 60);
   lights_[6] = TrafficLight(kWest, true, 10, 30);
   lights_[7] = TrafficLight(kWest, false, 30, 60);
}

TrafficLight* TrafficController::GetCurrentActiveLight() {


   for (auto& light : lights_) {
      if (light.IsActive() == true) {
         return &light;
      }
   }

   return nullptr;
}

void TrafficController::IncrementStep() {

   current_step_ = (current_step_ + 1) % 4;
}

bool TrafficController::SensorDetectWaitingCars(Direction direction) {

   auto it = sensors_.find(direction);
   if (it != sensors_.end()) {
      return it->second->HasWaitingVehicles();
   }

   return false;
}

int TrafficController::CalculateDuration(const TrafficLight& light) {

   // Get default duration
   int duration = light.GetMinTime();

   // Check for waiting cars
   if (SensorDetectWaitingCars(light.GetDirection())) {
      duration = std::min(light.GetMaxTime(), duration * 2);
   }

   return duration;
}

void TrafficController::UpdateLights() {

   // Turn off all lights
   for (auto& light : lights_) {
      light.Deactivate();
   }

   // Activate light for current step
   switch (current_step_) {

   case 0: // N/S turn
   lights_[0].Activate();
   lights_[2].Activate();
   break;

   case 1: // N/S thru
   lights_[1].Activate();
   lights_[3].Activate();
   break;

   case 2: // E/W turn
   lights_[4].Activate();
   lights_[6].Activate();
   break;

   case 3: // E/W thru
   lights_[5].Activate();
   lights_[7].Activate();
   }

}

void TrafficController::PrintLightStatus() {

   for (auto& light : lights_) {

      std::string status = light.IsActive() ? "Active" : "Inactive";

      std::string isTurning = light.IsTurning() ? "Turning" : "Thru";

      std::cout << "Light facing " << light.GetDirection() << " is " << status << " " << isTurning << "\n";
   }
}
