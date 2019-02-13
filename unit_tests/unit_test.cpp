#include "gtest/gtest.h"
#include "../src/base.hpp"
#include "../src/connector.hpp"
#include "../src/command.hpp"
#include "../src/or.hpp"
#include "../src/and.hpp"
#include "../src/semiColon.hpp"

TEST(EchoTest, first_test) {



}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
