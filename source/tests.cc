#include <gtest/gtest.h>
#include "headers.h"

TEST(EnvironmentTest, BasicVarsShouldBeAssigned) {
    char * APP_ENV = std::getenv("APP_ENV");
    EXPECT_TRUE(APP_ENV != nullptr);
}

TEST(CopyrightTest, AuthorRecognition) {
    About about;
    EXPECT_EQ("Ian Torres", about.getAuthor());
    EXPECT_EQ("iantorres@outlook.com", about.getContact());
}

TEST(AuthorizationTest, AccessTokenShouldBeAssigned) {
    Authorization authorization;
    EXPECT_TRUE(!authorization.getToken().empty());
}

TEST(NetworkTest, EnvironmentPortShouldBeAssigned) {
    Network network;
    std::string env_port = std::getenv("APP_PORT");
    EXPECT_EQ(network.getPort(), std::stoi(env_port));
}
