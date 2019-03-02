#include "test.hpp"

test::test() {
}
test::test(std::string n){
	set_command(n);
}
bool test::compute(bool* flag){

	struct stat buf;
	
	stat(argu[1], &buf);

	if(std::string(argu[0]) == "-e"){
		if(S_ISDIR(buf.st_mode ) || S_ISREG(buf.st_mode)){
			printf("(True)\n");
			return true;
		}
			printf("(False)\n");
			return false;
	}
	else if(std::string(argu[0]) == "-f"){
		if(S_ISREG(buf.st_mode)){
			printf("(True)\n");
			return true;
		}
		printf("(False)\n");
                return false;
	}
	
	else if(std::string(argu[0]) == "-d"){
		if(S_ISDIR(buf.st_mode)){
		        printf("(True)\n");
                        return true;
                }
                printf("(False)\n");
                return false; 
		
	}
	else{
		stat(argu[0], &buf);

		if(S_ISDIR(buf.st_mode ) || S_ISREG(buf.st_mode)){
                        printf("(True)\n");
                        return true;
                }
                printf("(False)\n");
                return false;	
	}
	
}
int test::type() {
	return 8;
}

