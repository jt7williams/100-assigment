#include "command.hpp"


command::command() {
}
command::command(std::string n){
	set_command(n);		
}
std::string command::cutComments(std::string input) {
        size_t c = input.find("#");
        if(c != std::string::npos) {
                input = input.substr(0,c-1);

        }
        //std::cout<<input<<std::endl;
        return input;
}
                
int command::type() {
	//std::cout<<"inside type"<<std::endl;
	return 1;
}
bool command::compute(bool* f){
	//std::cout<<"inside compute"<<std::endl;
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
		return !WEXITSTATUS(status);
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
	//return true;
}
