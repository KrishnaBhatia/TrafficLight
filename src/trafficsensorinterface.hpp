/**
 * @file trafficsensorinterface.hpp
 * @author Krishna Bhatia
 * @brief Class declaration for Traffic Sensor Interface
 */

#ifndef TRAFFICSENSORINTERFACE_HPP_
#define TRAFFICSENSORINTERFACE_HPP_

#include "trafficlight.hpp"

class TrafficSensorInterface {

   public:

      /**
       * @brief  Get direction of the sensor
       * @return Direction
       */
      virtual Direction GetDirection() const = 0;

      /**
       * @brief  Check if sensor detects vehicles waiting
       * @return True if sensor detects vehicles queued, False otherwise
       */
      virtual bool HasWaitingVehicles() const = 0;

      /**
       * @brief  Check if sensor is valid
       * @return True if sensor is valid, False otherwise
       */
      virtual bool IsValid() const = 0;
};
#endif // trafficsensorinterface.hpp
