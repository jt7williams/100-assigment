#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main (int argv, char* argc[]){
	pid_t children = fork();
	int status;
		
	char* arg[2];

	std::string command_1("ps");
	arg[0] = (char*)command_1.c_str();
	arg[1] = NULL;


	if(children > 0){
		
		printf("We are in the  Pararent. Parent_ID: %d, The child is. child_ID: %d\n", getpid(), children);
	if(waitpid(children, &status , WNOHANG|WUNTRACED ) == 0){
		wait(NULL);
		
		if (WIFEXITED(status))
              	 printf("Child ended normally!\n");
              	else if (WIFSIGNALED(status))
                 	printf("Child ended because of an uncaught signal!\n");
              	else if (WIFSTOPPED(status))
                	 printf("Child process has stoped!\n");
              exit(EXIT_SUCCESS);
	}
	if(waitpid(children, &status , WNOHANG|WUNTRACED ) < 0)
		exit(EXIT_FAILURE);
	
	}


	if(children == 0){
		printf("We are in the Child. Child_ID: %d, The parent is. Parent_ID: %d\n",getpid(), getppid());
	printf("Calling execvp with command  <ps>\n");
	execvp(arg[0], arg);	}

	
	if(children < 0){
		perror("fork() error");
		exit(-1);
	}

	return 0;



}
