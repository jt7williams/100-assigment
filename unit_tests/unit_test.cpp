#include "gtest/gtest.h"
#include "../src/base.hpp"
#include "../src/connector.hpp"
#include "../src/command.hpp"
#include "../src/or.hpp"
#include "../src/and.hpp"
#include "../src/semiColon.hpp"

TEST(EchoTest, Testing_echo_hello) {
	std::string t = "echo hello";
	command* one = new command(t);
	EXPECT_EQ(0,one->compute());
}
TEST(EchoTest, Testing_ls ){
	
	command* one = new command("ls");
	EXPECT_EQ(0,one->compute());
}
TEST(EchoTest, Invalid_cmd_prr4){
	command* one = new command();
	one->set_command("pr4490");
	EXPECT_EQ(1, one->compute());

}
TEST(EchoTest, command_type) {
	command* tester = new command();
	EXPECT_EQ(1, tester->type());
}
TEST(EchoTest, comment_test) {
	command* tester = new command();
	std::string t = tester->cutComments("ls #comment");
	EXPECT_EQ("ls", t);
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
