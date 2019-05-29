#pragma once
#include <ctime>
class Tab
{
private:
	char* URL;
	time_t Timestamp;
	Tab* PreviousTab;
	Tab* NextTab;
public:
	Tab();
	~Tab();

	// SETTERS AND GETTERS
	void SetURL(char* const& other);
	void SetTimestamp(time_t const& other);
	void SetPreviousTab(Tab* const& other);
	void SetNextTab(Tab* const& other);
	char* GetURL() const;
	time_t GetTimestamp() const;
	Tab* GetPreviousTab() const;
	Tab* GetNextTab() const ;
};

