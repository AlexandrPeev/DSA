#include <iostream>
#include "Tab.h"
#include "Browser.h"
#include <ctime>
int main()
{
	/*Tab example;
	std::cout << example.GetURL() <<std::endl;
	char* arr = new char[6];
	arr = "hello";
	example.SetURL(arr);
	std::cout << example.GetURL() <<std::endl;
	std::cout << time(nullptr);
	return 0;
	*/
	char* example1 = new char[11];
	example1 = "www.pornhub.com/1";
	char* example2 = new char[11];
	example2 = "www.pornhub.com/2";
	char* example3 = new char[11];
	example3 = "www.pornhub.com/3";
	char* example4 = new char[11];
	example4 = "www.pornhub.com/4";
	char* example5 = new char[11];
	example5 = "www.pornhub.com/5";
	char* example6 = new char[11];
	example6 = "www.pornhub.com/6";
	Browser firefox;
	firefox.INSERT(example1);
	firefox.INSERT(example2);
	firefox.INSERT(example3);
	firefox.INSERT(example4);
	firefox.INSERT(example5);
	firefox.INSERT(example6);
	firefox.PRINT();
	
}