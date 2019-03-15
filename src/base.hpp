#ifndef __base_hpp__
#define __base_hpp__
#include <string>
#include <iostream>
#include <string.h>
#include <cstring>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <fcntl.h>
class base {
	protected:
        	char* argu[5];
		
        	char* one;
       		char* two;
	public:
		base(){ for(int i = 0; i < 5; i++) argu[i] = NULL;}
		virtual bool compute(bool* flag) {return 0;}
		virtual int type() {return 0;}
		virtual void setLeft(base* b) {return;}
		virtual void setRight(base* b) {return;}
		virtual std::string getName() {return "";}
		void set_command(std::string n){       
        		std::string d = " ";
        		std::string t_sub = n.substr(0, n.find(d));

        		argu[0] = new char [t_sub.length()+1];
        		std::strcpy(argu[0],t_sub.c_str());

        		n.erase(0,t_sub.size()+1);
        	
			if(n.size() > 0){
				t_sub = n.substr(0, n.find(d));
				argu[1] = new char [t_sub.length()+1];
				std::strcpy(argu[1],t_sub.c_str());
			n.erase(0,t_sub.size()+1);
			}	
			if(n.size() > 0){
               			argu[2] = new char[n.length()+1];
                		std::strcpy(argu[2],n.c_str());
				n.erase(0,t_sub.size()+1);			
			}
			if(n.size() > 0){
                                argu[3] = new char[n.length()+1];
                                std::strcpy(argu[3],n.c_str()); 
        		}
		
		//	printf("command: %s\n",argu[0]);
		//	printf("argument one: %s\n",argu[1]);
		//	printf("argument two: %s\n",argu[2]);
		//	printf("argument three: %s\n",argu[3]);  
		}
};
#endif
