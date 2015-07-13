# include <iostream>
# include <windows.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# define K 10000 // Max_range

void quickSort(int x[], int start, int end); // function for quicksort algorithm
int pivotEle(int x[], int start, int end); // function to select the pivot value
void swap(int& x, int& y); // function to swap the values
void print(int array[], const int& N); // prints the values before sorting and after sorting

using namespace std;

int main()

{

	LARGE_INTEGER freq;
	LARGE_INTEGER a1, a2; // start timer and end timer
	double elapTime; // value which displays the total time taken
	time_t nn;
	time(&nn);
	srand((unsigned int)nn); // to create random values
	int N, i,value;
	cout << "Pass the value of N to generate values  " << endl;
	cin >> N;
	int Arr[N]; // allocates memory for the entered value of N
	cout <<"To generate constant value enter 1 else enter 0 --  " <<endl;
	cin >> value;
	if(value == 1)
	{
		int cnst= rand() % K; //constant random value generates once
		for (i = 0; i < N; i++) {

			Arr[i] = cnst;

	    }
	}
	else if(value == 0) //Generates Random values for N
	{

	for (i = 0; i < N; i++) {
		Arr[i] = rand() % K; // random value generation

	}
}

	cout << "Before sorting : " << endl;
	print(Arr, N);
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&a1);

	quickSort(Arr, 0, N - 1); // passing the values to quick sort
	QueryPerformanceCounter(&a2);
	elapTime = (a2.QuadPart - a1.QuadPart) * 1000.0 / freq.QuadPart; //time elapsed for quicksort

	cout << "Sorting the values "<< endl;
	print(Arr, N); // prints sorted elements
	cout << "After sorting : " << elapTime << "ms" <<endl; // prints elapsed time

	return 0;
}

// values for quick sort
void quickSort(int x[], int start, int end) {
	int pivotVlaue;

	if (start < end) {
		pivotVlaue = pivotEle(x, start, end); //pivot element will be received for pivotEle function
		quickSort(x, start, pivotVlaue - 1);
		quickSort(x, pivotVlaue + 1, end);
	}
}

//pivot element will be selected from this function
int pivotEle(int x[], int start, int end) {
	int p = start;
	int pivotElement = x[start];

	for (int i = start + 1; i <= end; i++) {

		if (x[i] <= pivotElement) {
			p++;
			swap(x[i], x[p]);
		}
	}

	swap(x[p], x[start]);

	return p;
}

// sorting the elements
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}


// prints the elements before sorting and after sorting
void print(int a[], const int& N) {
	for (int i = 0; i < N; i++)
		cout << "array[" << i << "] = " << a[i] << endl;
}
