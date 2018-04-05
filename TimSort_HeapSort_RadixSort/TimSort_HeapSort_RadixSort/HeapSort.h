#pragma once
#include "Sort.h"
#include "ctime"
#include "iostream"
using namespace std;

class HeapSort : public Sort
{
public:
	unsigned int MetodSort(int* arr, int n)
	{
		NumComp = 0; NumSwaps = 0;
		unsigned int time = clock();
		heapSort(arr, n);
		//printArray(arr, n);
		return clock() - time;
	}
private:
	void heapify(int arr[], int n, int i)
	{
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		NumComp++;
		if (l < n && arr[l] > arr[largest])
			largest = l;
		NumComp++;
		if (r < n && arr[r] > arr[largest])
			largest = r;
		if (largest != i)
		{
			swap(arr[i], arr[largest]);
			NumSwaps++;
			heapify(arr, n, largest);
		}
	}

	void heapSort(int arr[], int n)
	{
		{
			for (int i = n / 2 - 1; i >= 0; i--)
				heapify(arr, n, i);
			for (int i = n - 1; i >= 0; i--)
			{
				swap(arr[0], arr[i]);
				NumSwaps++;
				heapify(arr, i, 0);
			}
		}
	}

	/*void printArray(int arr[], int n)
	{

		/*for (int i = 0; i < n; i++)
		{
		cout << arr[i] << " ";
		}
		cout << endl;
		cout << "HeapSort:";
		cout << "NumComp=" << NumComp << " " << "NumSwaps=" << NumSwaps << " ";
	}*/
};