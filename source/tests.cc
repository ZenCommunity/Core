#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include "about.h"

TEST(EnvironmentTest, BasicVarsShouldBeAssigned) {
    char * MODE = std::getenv("APP_MODE");
    EXPECT_TRUE(MODE != nullptr);
}

TEST(CopyrightTest, AuthorRecognition) {
    About about;
    EXPECT_EQ("Ian Torres", about.getAuthor());
    EXPECT_EQ("iantorres@outlook.com", about.getContact());
}
