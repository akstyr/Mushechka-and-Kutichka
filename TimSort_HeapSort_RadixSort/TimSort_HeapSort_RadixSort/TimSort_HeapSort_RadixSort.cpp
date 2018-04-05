// TimSort_HeapSort_RadixSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ctime"
#include "TimSort.h"
#include "HeapSort.h"
#include "RadixSort.h"
#include "iostream"
using namespace std;

void printArray(int arr[], int *n)
{
	for (int i = 0; i < *n; i++)
	{
		if ((i % 10) == 0) cout << endl;
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array(int arr[], int *N)
{
	for (int i = 0; i < *N; i++)
		arr[i] = rand();
	//printArray(arr, N); cout << endl;
}

int main()
{
	srand(time(0));
	int Llist[] = { 1,2,3,4,5, 10, 15, 20, 25, 30, 50, 75, 100, 250, 500};
	int N, time = 0, L = sizeof(Llist) / sizeof(Llist[0]);
	int NumComp = 0, NumSwaps = 0;
	double StartTime, EndTime, WorkTime;
	for (int i = 0; i < L; i++)
	
	{
		N = Llist[i];
		int *arr = new int[N];
		Array(arr, &N);

		cout << "TimSort" << endl;
		{
			StartTime = 0;
			StartTime = clock();
		for (int k = 0; k < 100; k++) 
			{
				TimSort tim;
				time = time + tim.MetodSort(arr, &N);
				//printArray(arr, &N);
				NumComp = NumComp + tim.NumComp;
				NumSwaps = NumSwaps + tim.NumSwaps;
			}
		EndTime = clock();
		WorkTime = (EndTime - StartTime) / 1000.0;
			cout << "N = " << N << "    Time = " << WorkTime  << endl;
			cout << "NumComp = " << NumComp/100 << "    NumSwaps = " << NumSwaps/100 << endl << endl;

		}

		NumComp = 0; NumSwaps = 0; time = 0;

		cout << "HeapSort" << endl;
		for (int j = 0; j < 100; j++)
		{
			HeapSort heap;
			time = time + heap.MetodSort(arr, N);
			//printArray(arr, &N);
			NumComp = NumComp + heap.NumComp;
			NumSwaps = NumSwaps + heap.NumSwaps;
		}
		cout << "N = " << N << "    Time = " << time / 1000.0  << endl;
		cout << "NumComp = " << NumComp/100 << "    NumSwaps = " << NumSwaps/100  << endl << endl;

		NumComp = 0; NumSwaps = 0; time = 0;

		cout << "RadixSort" << endl;
		for (int j = 0; j < 100; j++)
		{
			RadixSort radix;
			time = time + radix.MetodSort(arr, &N);
			//printArray(arr, &N);
			NumComp = NumComp + radix.NumComp;
			NumSwaps = NumSwaps + radix.NumSwaps;
		}
		cout << "N = " << N << "    Time = " << time / 1000.0  << endl;
		cout << "NumComp = " << NumComp/100  << "    NumSwaps = " << NumSwaps/100  << endl << endl;

		NumComp = 0; NumSwaps = 0; time = 0;
		//cin.get();
		delete[] arr;
	}
	cin.get();
    return 0;
}

