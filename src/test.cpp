#include "test.hpp"
#include <string>
test::test() {
}
test::test(std::string n){
	set_command(n);
}
bool test::compute(bool* flag){
	
	struct stat buf;

	stat(argu[1], &buf);

	if(std::string(argu[0]) == "-e"){
		return (S_ISDIR(buf.st_mode ) || S_ISREG(buf.st_mode));
		//std::cout<<"This is -e"<<std::endl;
	}
	else if(std::string(argu[0]) == "-f"){
		return (S_ISREG(buf.st_mode));
		//std::cout<<"This is -f"<<std::endl;
	}
	
	else if(std::string(argu[0]) == "-d"){
		return (S_ISDIR(buf.st_mode));
		//std::cout<<"This is -d"<<std::endl;
	}
	else{
		stat(argu[0], &buf);
		return (S_ISDIR(buf.st_mode ) || S_ISREG(buf.st_mode));		
	}
	
}
int test::type() {
	return 8;
}

