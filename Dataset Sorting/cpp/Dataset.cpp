#include "Dataset.h"
#include <iostream>


Dataset::Dataset()
{
	size = 0;
	capacity = 0;
	records = nullptr;		// Meaning Set from german, since "Set" can be quite ambigious
}

void Dataset::Resize()
{
	capacity == 0 ? capacity = 2 : capacity *= 2;
	Record* tmp = new Record[capacity];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = records[i];
	}
	delete[] records;
	records = tmp;
}

void Dataset::Add(Record const &obj)
{
	if (size >= capacity)
	{
		Resize();
	}
	records[size] = obj;
	size += 1;
}

void Dataset::Print()
{
	for (size_t i = 0; i < size; i++)
	{
		records[i].Print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Dataset::~Dataset()
{
	delete[] records;
	records = nullptr;
}


// SORTS


void Dataset::GradeSort(char dir)
{
	Record* tmp = new Record[size];
	int count = 0;
	if (dir == '+')
	{
		for (int i = 2; i <= 6; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (records[j].GetGrade() == i)
				{
					tmp[count] = records[j];
					count += 1;
				}
			}
		}
	}
	else if (dir == '-')
	{
		for (int i = 6; i >=2; i--)
		{
			for (int j = 0; j < size; j++)
			{
				if (records[j].GetGrade() == i)
				{
					tmp[count] = records[j];
					count += 1;
				}
			}
		}
	}
	delete[] records;
	records = tmp;
}


// HEAP SORT FOR NAME AND SUBJECT

void Dataset::Sift(int position, int pseudosize, char dir, const char* arg)
{
	Record Element = records[position];
	int iElement = position;
	int Child = position * 2 + 1;

	while (Child < pseudosize)
	{
		if (dir == '+')
		{
			if (arg == "name")
			{
				if (Child < pseudosize - 1 && (strcmp(records[Child].GetName(), records[Child + 1].GetName()) == -1))
				{
					Child += 1;
				}
				if (strcmp(Element.GetName(), records[Child].GetName()) == 1)
				{
					break;
				}
			}
			else if (arg == "subject")
			{
				if (Child < pseudosize - 1 && (strcmp(records[Child].GetSubject(), records[Child + 1].GetSubject()) == -1))
				{
					Child += 1;
				}
				if (strcmp(Element.GetSubject(), records[Child].GetSubject()) == 1)
				{
					break;
				}
			}
		}
		else if (dir == '-')
		{
			if (arg == "name")
			{
				if (Child < pseudosize - 1 && (strcmp(records[Child].GetName(), records[Child + 1].GetName()) == 1))
				{
					Child += 1;
				}
				if (strcmp(Element.GetName(), records[Child].GetName()) == -1)
				{
					break;
				}
			}
			else if (arg == "subject")
			{
				if (Child < pseudosize - 1 && (strcmp(records[Child].GetSubject(), records[Child + 1].GetSubject()) == 1))
				{
					Child += 1;
				}
				if (strcmp(Element.GetSubject(), records[Child].GetSubject()) == -1)
				{
					break;
				}
			}
		}
		records[iElement] = records[Child];
		iElement = Child;
		Child = Child * 2 + 1;

	}
	records[iElement] = Element;
}

void Dataset::HeapSort(char dir, const char* arg)
{
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		Sift(i, size, dir, arg);
	}
	Record tmp;
	for (int i = size - 1; i > 0; --i)
	{
		tmp = records[0];
		records[0] = records[i];
		records[i] = tmp;
		Sift(0, i, dir, arg);
	}
}




// MERGE SORT FOR AGE AND DATE
void Dataset::MergeSortLaunch(char dir, const char* arg)
	{
		if (!records || size == 0)
		{
			return;
		}
		Record* buffer = new Record[size];
		if (arg == "age")
		{
			MergeSort(records, size, buffer, dir, arg);
		}
		if (arg == "date")
		{
			MergeSort(records, size, buffer, dir, arg);
		}
		delete[] buffer;
	}

void Dataset::MergeSort(Record* array, int sizze, Record* buffer, char dir, const char* arg)
	{
		if (sizze <= 1)
		{
			return;
		}
		int mid = sizze / 2;
		MergeSort(array, mid, buffer, dir, arg);
		MergeSort(array + mid, sizze - mid, buffer + mid, dir, arg);
		Merge(array, mid, array + mid, sizze - mid, buffer, dir, arg);
		for (int i = 0; i < sizze; i++)
		{
			array[i] = buffer[i];
		}
	}

void Dataset::Merge(Record* A, int sA, Record* B, int sB, Record* output, char dir, const char* arg)
	{
		int i = 0;
		int iA = 0;
		int iB = 0;
		if (dir == '+')
		{
			if (arg == "age")
			{
				while (iA < sA && iB < sB)
				{
					output[i] = (A[iA].GetAge() < B[iB].GetAge() ? A[iA++] : B[iB++]);
					i += 1;
				}
			}
			else if (arg == "date")
			{
				while (iA < sA && iB < sB)
				{
					output[i] = (A[iA].GetDate() < B[iB].GetDate() ? A[iA++] : B[iB++]);
					i += 1;
				}
			}
		}
		if (dir == '-')
		{
			if (arg == "age")
			{
				while (iA < sA && iB < sB)
				{
					output[i] = (A[iA].GetAge() > B[iB].GetAge() ? A[iA++] : B[iB++]);
					i += 1;
				}
			}
			if (arg == "date")
			{
				while (iA < sA && iB < sB)
				{
					output[i] = (A[iA].GetDate() > B[iB].GetDate() ? A[iA++] : B[iB++]);
					i += 1;
				}
			}
		}
		while (iA < sA)
		{
			output[i] = A[iA];
			i += 1;
			iA += 1;
		}
		while (iB < sB)
		{
			output[i] = B[iB];
			i += 1;
			iB += 1;
		}
	}