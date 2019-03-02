#ifndef __base_hpp__
#define __base_hpp__
#include <string>
#include <iostream>
#include <string.h>
#include <cstring>
class base {
	protected:
        	char* argu[3];
        	char* one;
       		char* two;
	public:
		base(){};
		virtual bool compute(bool* flag) {return 0;}
		virtual int type() {return 0;}
		virtual void setLeft(base* b) {return;}
		virtual void setRight(base* b) {return;}

		void set_command(std::string n){       
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
		}
};
#endif
