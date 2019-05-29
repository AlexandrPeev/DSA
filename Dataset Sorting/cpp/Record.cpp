#include "Record.h"
#include <iostream>

// MISC

void Record::Print()
{
	std::cout << name << " " << age << " " << subject << " " << grade << " ";
	char tmp[9];
	//ToChar(date, tmp);
	itoa(date, tmp, 10);
	for (int i = 0; i < 4; i++)
	{
		std::cout << tmp[i];
	}
	std::cout << "-";
	for (int i = 4; i < 6; i++)
	{
		std::cout << tmp[i];
	}
	std::cout << "-";
	for (int i = 6; i < 8; i++)
	{
		std::cout << tmp[i];
	}
}

void Record::CopyMembers(Record const&obj)
{

	SetName(obj.GetName());
	SetAge(obj.GetAge());
	SetSubject(obj.GetSubject());
	SetDateint(obj.GetDate());
	SetGrade(obj.GetGrade());
}

void Record::Clean()
{
	delete[] name;
	delete[] subject;
	name = nullptr;
	subject = nullptr;
}

// BIG FOUR

Record::Record()
{
	name = nullptr;
	age = 0;
	subject = nullptr;
	grade = 0;
	date = 0;
}

Record& Record::operator=(Record const &obj)
{
	Clean();
	if (this != &obj) 
	{
		CopyMembers(obj);
	}
	return *this;
}

Record::Record(const Record&other)
{
	CopyMembers(other);
}
Record::Record(const char* name, unsigned int age, const char* subject, int grade, char* date)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	SetAge(age);
	this->subject = new char[strlen(subject) + 1];
	strcpy(this->subject, subject);
	SetDate(date);
	SetGrade(grade);
}

Record::~Record()
{
	Clean();
}

// SETTERS
void Record::SetName(const char* arr)
{
 	name = new char[strlen(arr) + 1];
	strcpy(name, arr);
}

void Record::SetSubject(const char* arr)
{
	subject = new char[strlen(arr) + 1];
	strcpy(subject, arr);
}

void Record::SetAge(const int val)
{
	age = val;
}

void Record::SetGrade(const int val)
{
	grade = val;
}

void Record::SetDate( char* input)
{
	char* tmp = input;
	int len = strlen(tmp);
	for (int i = 4; i < len - 1; i++)
	{
		tmp[i] = tmp[i + 1];
	}
	len = strlen(tmp);
	for (int i = 6; i < len - 1; i++)
	{
		tmp[i] = tmp[i + 1];
	}
	this->date = atoi(tmp) / 100;
}

void Record::SetDateint(int const&number)
{
	date = number;
}

// GETTERS

int Record::GetDate() const
{
	return date;
}

char* Record::GetName() const
{
	return name;
}
char* Record::GetSubject() const
{
	return subject;
}
unsigned int Record::GetAge() const
{
	return age;
}
unsigned int Record::GetGrade() const
{
	return grade;
}
