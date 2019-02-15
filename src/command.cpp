#include "command.hpp"
#include <sys/types.h>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

command::command() {
}
command::command(std::string n){
	set_command(n);		
}
int command::type() {
	return 1;
}
bool command::compute(){

	int status;
	pid_t children, w;
	
	children = fork();
	if(children > 0){

		       do {
            w = waitpid(children, &status,WUNTRACED | WCONTINUED);
            if (w == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
           } 

           if (WIFEXITED(status)) {
               // printf("Child Exited Succesfully| status =%d\n ", WEXITSTATUS(status));

            } else if (WIFSIGNALED(status)) {
               // printf("Child Terminated By Signal %d\n", WTERMSIG(status));

            } else if (WIFSTOPPED(status)) {
               // printf("Child Stopped By Signal %d\n", WSTOPSIG(status));
            } else if (WIFCONTINUED(status)) {
               // printf("continued\n");
               }

        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
		return WEXITSTATUS(status);
}

	if(children == 0){
		//note we are in the child
		if(execvp(argu[0],argu) < 1){
			printf("Error: command not found\n");
			exit(EXIT_FAILURE);
		}
	}
	
	if(children < 0){
		perror("fork() error");
		exit(-1);
	}

}
void command::set_command(std::string n){ 	
        std::string d = " ";
        std::string t_sub = n.substr(0, n.find(d));
	argu[0] = new char [t_sub.length()+1];
	std::strcpy(argu[0],t_sub.c_str());
	n.erase(0,t_sub.size()+1);
	if(n.size() > 0){
		argu[1] = new char[n.length()+1];
		std::strcpy(argu[1],n.c_str());}
	else
		argu[1] = NULL;

	argu[2] = NULL;
	//printf("%s:\n", argu[0]);
	//printf("%s:\n",argu[1]);
	//printf("%s:\n",argu[2]);
}

