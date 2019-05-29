#include "Tab.h"
#include <ctime>
#include <iostream>

Tab::Tab()
{
	this->URL = new char[2];
	this->URL = "";
	this->Timestamp = time(&Timestamp);
	this->NextTab = nullptr;
	this->PreviousTab = nullptr;
}


Tab::~Tab()
{
	delete[] URL;
	this->NextTab = nullptr;
	this->PreviousTab = nullptr;
}

// GETTERS AND SETTERS

void Tab::SetURL(char* const& other)
{
	this->URL = new char[strlen(other) + 1];
	strcpy(this->URL, other);
}

void Tab::SetTimestamp(time_t const& other)
{
	this->Timestamp = other;
}
void Tab::SetPreviousTab(Tab* const& other)
{
	this->PreviousTab = other;
}
void Tab::SetNextTab(Tab* const& other)
{
	this->NextTab = other;
}

char* Tab::GetURL() const
{
	return this->URL;
}

time_t Tab::GetTimestamp() const
{
	return this->Timestamp;
}

Tab* Tab::GetPreviousTab() const
{
	return this->PreviousTab;
}

Tab* Tab::GetNextTab() const
{
	return this->NextTab;
}