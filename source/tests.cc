#include <gtest/gtest.h>

TEST(EnvironmentTest, BasicVarsShouldBeAssigned) {
    char * MODE = std::getenv("CORE_MODE");
    EXPECT_TRUE(MODE != NULL);
}
