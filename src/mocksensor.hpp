/**
 * @file mocksensor.hpp
 * @author Krishna Bhatia
 * @brief Class declaration for mock sensor
*/

#ifndef MOCKSENSOR_HPP_
#define MOCKSENSOR_HPP_

#include "trafficsensorinterface.hpp"

#include <random>

class MockSensor : public TrafficSensorInterface {

   public:

      /**
       * @brief Construct a mock sensor
       * @parem Direction of the sensor
       */
      explicit  MockSensor(Direction dir);

      /**
       * @brief Get the direction of the sensor
       * @return Direction of the sensor
       */
      Direction GetDirection() const override;

      /**
       * @brief Check if sensor detects queued vehicles
       * @return True if sensor detects queued vehicle, False otherwise
       */
      bool HasWaitingVehicles() const override;

      /**
       * @brief Check if sensor is valid
       * @return True if sensor is valid, False otherwise
       */
      bool IsValid() const override;

   private:

      /**
       * @brief Direction of sensor
       */
      Direction direction_;

      /**
       * @brief Boolean for queued vehicles
       */
      bool has_waiting_vehicles_;

      /**
       * @brief Boolean for sensor status
       */
      bool sensor_status_;
};
#endif // mocksensor.hpp
