#pragma once
#include "Tab.h"
class Browser
{
	private:
		Tab* Head;
		Tab* Current;
		Tab* Tail;
		int size;
public:
	Browser();
	~Browser();
	//FUNCTIONALITIES
	void GO(char* adress);
	void INSERT(char* adress);
	void REMOVE();
	void BACK();
	void FORWARD();
	void PRINT();
};

