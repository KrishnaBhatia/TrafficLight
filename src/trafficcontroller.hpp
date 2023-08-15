/**
 * @file trafficcontroller.hpp
 * @author Krishna Bhatia
 * @brief Class declaration for TrafficController
*/

#ifndef TRAFFICCONTROLLER_HPP_
#define TRAFFICCONTROLLER_HPP_

#include "trafficlight.hpp"
#include "mocksensor.hpp"

#include <array>
#include <chrono>
#include <map>

// forward declaration
class TrafficSensorInterface;

class TrafficController {

   public:

      /**
       * @brief Construct traffic controller
       */
      TrafficController();

      /**
       * @brief Operate traffic controller
       */
      void Operate();

      /**
       * @brief Register sensor to controller
       * @parem TrafficSensorInterface* pointer to sensor
       */
      void RegisterSensor(TrafficSensorInterface* sensor);

   private:

      /**
       * @brief Array of traffic lights
       */
      std::array<TrafficLight, 8> lights_;

      /**
       * @brief Map of sensors
       */
      std::map<Direction, TrafficSensorInterface*> sensors_;

      /**
       * @brief Store current step in the cycle
       */
      int current_step_;

      /**
       * @brief Activate lights at the start of the simulation
       */
      void InitializeLights();

      /**
       * @brief Get current Active traffic light
       * @return current active traffic light
       */
      TrafficLight* GetCurrentActiveLight();

      /**
       * @brief Icrement to next step in cycle
       */
      void IncrementStep();

      /**
       * @brief Detect waiting vehicles
       * @parem direction of the sensor
       * @return True if sensor detects waiting vehicles, False otherwise
       */
      bool SensorDetectWaitingCars(Direction direction);

      /**
       * @brief Calculate duration of traffic light
       * @parem light for which the duration needs to be calculated
       * @return Duration fow which traffic light needs to be activated
       */
      int CalculateDuration(const TrafficLight& light);

      /**
       * @brief Update traffic lights according to the current step in cycle
       */
      void UpdateLights();

      /**
       * @brief Print status of each traffic light
       */
      void PrintLightStatus();
};

#endif // trafficcontroller.hpp
