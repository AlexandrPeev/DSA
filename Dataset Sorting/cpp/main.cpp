#include <iostream>
#include <fstream>
#include "Record.h"
#include "Dataset.h"

// My reasoning behind using date as an int is that it is a lot cheaper to compare it as an int and
// pay a heavier price while printing, than using strcmp on every iteration of comparison

int main(int argc , char* argv[])
{
	const char* location = argv[1];
	const char* dir = argv[2];
	const char* arg = argv[3];

	std::ifstream data(location);
	if (!data.is_open()) {
		std::cout << "The file cannot be opened / created ! ";
		return -1;
	}
	char buffname[2048];
	char buffsubject[2048];
	char buffdate[2048];
	unsigned int age;
	int grade;
	Dataset DateiMenge;
	data.ignore(4096, '\n');
	int count = 0;
	while (data.good())
	{
		data.getline(buffname, 2047, ',');
		data >> age;
		data.ignore();
		data.getline(buffsubject, 2047, ',');
		data >> grade;
		data.ignore();
		data.getline(buffdate, 2047, '\n');
		count += 1;
		Record holder(buffname, age, buffsubject, grade, buffdate);
		DateiMenge.Add(holder);
	}
	DateiMenge.Print();
	//DateiMenge.HeapSort('-', "subject");
	//DateiMenge.MergeSortLaunch('+', "date");
	char dirr;
	if (dir = "asc")
	{
		dirr = '+';
	}
	else if (dir == "desc")
	{
		dirr = '-';
	}

	if(arg == "name")
		DateiMenge.HeapSort(dirr, "name");
	if (arg == "age")
		DateiMenge.MergeSortLaunch(dirr, "age");
	if (arg == "subject")
		DateiMenge.HeapSort(dirr, "subject");
	if (arg == "grade")
		DateiMenge.GradeSort(dirr);
	if (arg == "date")
		DateiMenge.MergeSortLaunch(dirr, "date");

	DateiMenge.Print();
	data.close();
	return 0;
}