#pragma once
#include "Record.h"
class Dataset
{
private:
	Record* records;
	int size;
	int capacity;
public:
	Dataset();
	void Resize();
	void Add(Record const &);
	void Print();
	~Dataset();

	//Sorts
	void GradeSort(char dir);
	void Sift(int position, int pseudosize, char dir, const char* arg);
	void HeapSort(char dir, const char* arg);

	// MERGE SORT
	void MergeSortLaunch(char dir, const char* arg);
	void MergeSort(Record* array, int size, Record* buffer, char dir, const char* arg);
	void Merge(Record* A, int sA, Record* B, int sB, Record* output, char dir, const char* arg);
};

