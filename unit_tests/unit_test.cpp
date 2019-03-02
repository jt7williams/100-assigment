#include "gtest/gtest.h"
#include "../src/base.hpp"
#include "../src/connector.hpp"
#include "../src/command.hpp"
#include "../src/or.hpp"
#include "../src/and.hpp"
#include "../src/semiColon.hpp"
#include "../src/test.cpp"
bool f = true;




TEST(EchoTest, Testing_test_option_e){
	
	//TESTING WITH  EXISTING DIRECTORY
	std::string t = "-e src/";
	command* one = new test(t);
	EXPECT_EQ(1, one->compute(&f));
	
	//TESTING WITH  EXISTING FILE
	t = "-e main.cpp";
		one = new test(t);
	EXPECT_EQ(1, one->compute(&f));
	
	//TESTING WITH INVALID PATH
	t = "-e this is not a path!";
		one = new test(t);
	EXPECT_EQ(0, one->compute(&f));
	
}  

TEST(EchoTest, Testing_test_no_option_default_e){

	//TESTING FOR EXISTING DIRECTORY
	std::string t = "src/";
	command* one = new test(t);
	EXPECT_EQ(1, one->compute(&f));
	
	//TESTING FOR EXISTING FILE
	t = "main.cpp";
		one = new test(t);
	EXPECT_EQ(1, one->compute(&f));
	

	//TESTING WITH INVALID PATH
	t = "This is not a path!";
		one = new test(t);
	EXPECT_EQ(0, one->compute(&f));
}
TEST(EchotEST, Testing_test_option_f){
	
	//TESTING WITH EXISTING DIRECTORY
	std::string t = "-f src/";
	command* one = new test(t);
	EXPECT_EQ(0, one->compute(&f));

	//TESTING WITH EXISTING FILE
	t = "-f main.cpp";
		one = new test(t);
	EXPECT_EQ(1, one->compute(&f));

	//TESTING WITH INVALID PATH
	t = "-f This is not a path!";
		one = new test(t);
	EXPECT_EQ(0, one->compute(&f));
}	
TEST(EchoTest, Tesing_test_option_d){
	
	//TESTING WITH EXISTING DIRECTORY
	std::string t = "-d src/";
	command* one = new test(t);
	EXPECT_EQ(1, one->compute(&f));

	//TESTING WITH EXISTING FILE
	t = "-d main.cpp";
		one = new test(t);
	EXPECT_EQ(0, one->compute(&f));	

	//TESTING WITH INVALID PATH
	t = "-d This is not a path!";
		one = new test(t);
	EXPECT_EQ(0, one->compute(&f));

	
}

TEST(EchoTest, Testing_echo_hello) {
	std::string t = "echo hello";
	command* one = new command(t);
	EXPECT_EQ(1,one->compute(&f));
}
TEST(EchoTest, Testing_ls ){
	
	command* one = new command("ls");
	EXPECT_EQ(1,one->compute(&f));
}
TEST(EchoTest, Invalid_cmd_prr4){
	command* one = new command();
	one->set_command("pr4490");
	EXPECT_EQ(0, one->compute(&f));

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
