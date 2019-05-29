#include "Browser.h"
#include <iostream>


Browser::Browser()
{
	Tab* tmp = new Tab;
	tmp->SetTimestamp(time(nullptr));
	tmp->SetURL("about:blank");
	this->Current = tmp;
	this->Head = tmp;
	this->Tail = tmp;
	this->Head->SetNextTab(this->Tail);
	this->Tail->SetNextTab(nullptr);
	tmp->SetNextTab(nullptr);
	tmp->SetPreviousTab(nullptr);
	//this->Current->SetNextTab(nullptr);
	size = 0;
}


Browser::~Browser()
{
}

//FUNCTIONALITIES
void Browser::GO(char* adress)
{
	Current->SetTimestamp(time(nullptr));
	//char* tmp = new char[strlen(adress) + 1];
	//strcpy(tmp, adress);
	this->Current->SetURL(adress);
	//delete[] tmp;
}

void Browser::INSERT(char* adress)
{
	if(this->size == 0)
	{
		/*delete this->Current;
		Tab* tmp = new Tab;
		this->Current = tmp;
		this->Head = tmp;
		this->Head->SetNextTab(this->Tail);
		this->Head->SetPreviousTab(nullptr);
		this->Tail = tmp;
		this->Tail->SetPreviousTab(this->Head);
		this->Tail->SetNextTab(nullptr);*/
	}
	if (this->size == 1)
	{
		Tab* tmp = new Tab;
		this->Tail = tmp;
		this->Head->SetNextTab(this->Tail);
		this->Tail->SetPreviousTab(this->Head); 
		this->Tail->SetNextTab(nullptr);
		this->Current = this->Tail;
	}
	if ((this->size != 0) && (this->size != 1))
	{
		if ((this->Current != this->Head) && (this->Current != this->Tail))
		{
			Tab* tmp = new Tab;
			tmp->SetPreviousTab(this->Current);
			this->Current->SetNextTab(tmp);
			tmp->SetNextTab(this->Current->GetNextTab());
			this->Current->GetNextTab()->SetPreviousTab(tmp);
			this->Current = tmp;
		}
		if (this->Current == this->Head) 
		{
			Tab* tmp = new Tab;
			this->Current->SetNextTab(tmp);
			tmp->SetPreviousTab(this->Current);
			this->Current = tmp;
		}
		if (this->Current == this->Tail)
		{
			Tab* tmp = new Tab;
			tmp->SetNextTab(nullptr);
			tmp->SetPreviousTab(this->Tail);
			this->Tail->SetNextTab(tmp);
			this->Tail = tmp;
			this->Tail->SetNextTab(nullptr);
		}
	}
		this->Current->SetTimestamp(time(nullptr));
		this->Current->SetURL(adress);
		this->size += 1;
}

void Browser::BACK()
{
	if(this->Current == this->Head)
	{}
	this->Current = this->Current->GetPreviousTab();
}

void Browser::FORWARD()
{
	if (this->Current == this->Tail)
	{}
	this->Current = this->Current->GetNextTab();
}

void Browser::REMOVE()
{
	if (size == 0)
	{
		this->Current->SetTimestamp(time(nullptr));
	}
	if (size == 1)
	{
		this->Current->SetURL("about:blank");
		this->Current->SetTimestamp(time(nullptr));
	}
	if (size != 0 && size != 1)
	{
		if (this->Current == this->Head)
		{
			this->Head = this->Head->GetNextTab();
			delete[] this->Current;
			this->Current = this->Head;
		}
		if (this->Current == this->Tail)
		{
			this->Tail = this->Tail->GetPreviousTab();
			delete[] this->Current;
			this->Current = this->Tail;
			this->Tail->SetNextTab(nullptr);
		}
		if ((this->Current != this->Head) && (this->Current != this->Tail))
		{
			this->Current->GetPreviousTab()->SetNextTab(this->Current->GetNextTab());
			this->Current->GetNextTab()->SetPreviousTab(this->Current->GetPreviousTab());
			delete this->Current;
			this->Current = Current->GetNextTab();
		}
	}
}

void Browser::PRINT()
{
	Tab* tmp;
	tmp = this->Head;
	while (tmp->GetNextTab() != nullptr)
	{
		if (tmp != this->Current)
		{
			std::cout << tmp->GetURL() << " " << tmp->GetTimestamp() << std::endl;
			tmp = tmp->GetNextTab();
		}
		else if (tmp == this->Current)
		{
			std::cout <<"> " << tmp->GetURL() << " " << tmp->GetTimestamp() << std::endl;
			tmp = tmp->GetNextTab();
		}
	}
}