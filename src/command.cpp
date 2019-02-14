#include "command.hpp"
#include <sys/types.h>
#include <iostream>
#include <string>
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
bool command::compute(){
	int status;
	char *cmd = argu[0];
	
	pid_t children = fork();
	if(children > 0){
		//NOTE WE ARE IN PARENT
		if(waitpid(children,&status,WNOHANG|WUNTRACED) == 0){
			wait(NULL);
			if(WIFEXITED(status)){
				//printf("Child ended normally\n");
				return 1;	
			}
			else if(WIFSIGNALED(status)){			
				printf("Terminated By Uncaught Exception. Signal Generated: %d\n", WTERMSIG(status));
				return 0;
			}
			else if(WIFSTOPPED(status)){
				printf("Child process has stoped!\n");
				return 0;
			}
			exit(EXIT_SUCCESS);
		}
	
		if(waitpid(children, &status, WNOHANG|WUNTRACED) < 0)
			exit(EXIT_FAILURE);
	}
	
	if(children == 0){
		//note we are in the child
		execvp(cmd,argu);
	}
	
	if(children < 0){
		perror("fork() error");
		exit(-1);
	}

	return 0;

}
void command::set_command(std::string n){ 
	
	std::string t = n;
        std::string d = " ";	
        std::string t_sub = t.substr(0, t.find(d)); 
	argu[0] = (char*)t_sub.c_str();
	t.erase(0,t_sub.size());
	if(t.size() > 0)

		argu[1] = (char*)t.c_str();
	else
		argu[1] = NULL;

	argu[2] = NULL;
}

