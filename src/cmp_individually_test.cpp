#include <iostream>
#include <string.h>
#include <cstring>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <fcntl.h>

using namespace std;

int main(){

	cout<<"hello"<<endl;
	string one = "echo";
	string two = "hola";
	string three = "como";
	char* argu[4];
		argu[0] = new char(4);
		std::strcpy(argu[0],one.c_str());
		argu[1] = new char(4);
		std::strcpy(argu[1],two.c_str());
		argu[2] = new char(4);
		std::strcpy(argu[2],three.c_str());
		argu[3] = NULL;

		execvp(argu[0], argu);

return 0;
}
