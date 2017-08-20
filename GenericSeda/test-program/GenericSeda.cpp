// GenericSeda.cpp : Defines the entry point for the console application.
//

#include "seda\EntryPoint.h"

#include <iostream>

struct Handler {
	void execute(int i) {
		std::cout << "Value is:" << i <<std::endl;
	}
};
int main()
{
	EntryPoint<int, Handler> entrypoint(new Handler);
	int i =100;
	entrypoint.process(i);
	
    return 0;
}
