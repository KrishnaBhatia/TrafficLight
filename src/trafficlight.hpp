/**
 * @file trafficlight.hpp
 * @author Krishna Bhatia
 * @brief Class declaration for TrafficLight
*/

#ifndef TRAFFICLIGHT_HPP_
#define TRAFFICLIGHT_HPP_

#include <chrono>

/**
 * @breief Traffic direction enum
 */
enum Direction {
   kNorth,
   kSouth,
   kEast,
   kWest
};

/**
 * @class TrafficLight
 * @brief Models a single traffic light
 */
class TrafficLight {

   public:

      /**
       * @brief Construct a new Traffic Light
       */
      TrafficLight();

      /**
       * @brief Construct a new Traffic Light
       * @parem direction Direction controlled by this light
       * @parem isTurning Is this light for a turning lane?
       * @parem minTime Minimum active time in seconds
       * @parem maxTime Maximum active time in seconds
       */
      TrafficLight(Direction direction, bool isTurning, int minTime, int maxTime);

      /**
       * @brief Activate traffic light
       */
      void Activate();

      /**
       * @brief Deactivate traffic light
       */
      void Deactivate();

      /**
       * @brief Check if light is currently active
       * @return True if traffic light is active, False otherwise
       */
      bool IsActive() const;

      /**
       * @brief Get total elapsed active time
       * @return Duration for which traffic light was active
       */
      int GetDuration() const;

      /**
       * @brief Get direction of light
       * @return Direction of the traffic light
       */
      Direction GetDirection() const;

      /**
       * @brief Check if light is for turning lane
       * @return True if traffic light is for a turning lane, False otherwise
       */
      bool IsTurning() const;

      /**
       * @brief Get configured minimum active time
       * @return Minimum active time of traffic light
       */
      int GetMinTime() const;

      /**
       * @breif  Get configured maximum active time
       * @return Maximum active time of traffic light
       */
      int GetMaxTime() const;

   private:

      /**
       * @brief Direction of the traffic light
       */
      Direction direction_;
      
      /**
       * @brief Boolean for turning traffic light
       */
      bool isTurning_;
      
      /**
       * @brief Boolean for active traffic light
       */
      bool isActive_;
      
      /**
       * @brief Minimum active time of traffic light
       */
      int minTime_;
      
      /**
       * @brief Maximum active time of traffic light
       */
      int maxTime_;

      
      /**
       * @brief Start time for active traffic light
       */
      std::chrono::time_point<std::chrono::system_clock> start_;

};

#endif // TRAFFICLIGHT_HPP_
