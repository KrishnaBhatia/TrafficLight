#include <gtest/gtest.h>
#include "trafficcontroller.cpp"

TEST_F (TrafficController, TestCycleOrder) {

   TrafficController controller = new TrafficController();
   for (int i = 0; i<4; i++) {

      controller.UpdateLights();
      EXPECT_TRUE(lights_[0].active);
      EXPECT_TRUE(lights)[2].active);

      controller.IncrementStep();
      controller.UpdateLights();
      EXPECT_TRUE(lights_[1].active);
      EXPECT_TRUE(lights)[3].active);

      controller.IncrementStep();
      controller.UpdateLights();
      EXPECT_TRUE(lights_[4].active);
      EXPECT_TRUE(lights)[6].active);

      controller.IncrementStep();
      controller.UpdateLights();
      EXPECT_TRUE(lights_[5].active);
      EXPECT_TRUE(lights)[7].active);
   }

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
