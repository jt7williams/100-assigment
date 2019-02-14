#include "gtest/gtest.h"
#include "../src/base.hpp"
#include "../src/connector.hpp"
#include "../src/command.hpp"
#include "../src/or.hpp"
#include "../src/and.hpp"
#include "../src/semiColon.hpp"

TEST(EchoTest, Testing_echo_hello) {
	command* one = new command("echo hello");
	EXPECT_EQ(1,one->compute());
}
TEST(EchoTest, Testing_ls ){
	
	command* one = new command("ls");
	EXPECT_EQ(1,one->compute());
}
TEST(EchoTest, Invalid_cmd_prr4){
	command* one = new command();
	one->set_command("pr44");
	EXPECT_EQ(0, one->compute());

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}