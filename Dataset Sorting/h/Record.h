#pragma once
class Record
{
private:
	char* name;
	unsigned int age;
	char* subject;
	int grade;
	int date;

public:
	//BIG FOUR

	Record();
	Record& operator=(Record const&);
	Record(const Record&);
	Record(const char* name, unsigned int age, const char* subject, int grade, char* date);
	~Record();

	// SETTERS

	void SetName(const char* arr);
	void SetSubject(const char* arr);
	void SetAge(const int val);
	void SetGrade(const int val);
	void SetDate(char* input);
	void SetDateint(int const&number);

	//GETTERS

	int GetDate() const;
	char* GetName() const;
	char* GetSubject() const;
	unsigned int GetAge() const;
	unsigned int GetGrade() const;

	// MISC
	void Print();
	void CopyMembers(Record const&);
	void Clean();

};

