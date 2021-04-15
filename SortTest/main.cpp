#include <iostream>
#include <random>
#include <time.h>
#include <ctime>
#include <stdio.h>

using namespace std;

int compare_count = 0;
int swaping_count = 0;
int copying_count = 0;


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
		copying_count++;

        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
			copying_count++;
			compare_count++;
        }
        arr[j + 1] = key;
		copying_count++;
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
	swaping_count++;
}
 
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
	copying_count++;
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
			compare_count++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays	
	int *L = new int[n1];
	int *R = new int[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
		copying_count++;
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
		copying_count++;
	}

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
			copying_count++;
			compare_count++;
		}
		else {
			arr[k] = R[j];
			j++;
			copying_count++;
			compare_count++;
		}
		k++;		
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;		
		copying_count++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
		copying_count++;
	}

	delete L;
	delete R;
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;//returns recursively
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if( i > 0 )
			cout << " ";
		cout << A[i];
	}

	cout << endl;
}
 

int main() 
{
	srand( (unsigned)time(NULL) );

	int n1 = 100;
	int n2 = 1000;
	int n3 = 5000;
	int n4 = 10000;

	int *arr1 = new int[n1];
	int *arr2 = new int[n2];
	int *arr3 = new int[n3];
	int *arr4 = new int[n4];
	int *temp = new int[n4];

	for(int i = 0; i < n1; i++)
		arr1[i] = rand() % 100000;
	for(int i = 0; i < n2; i++)
		arr2[i] = rand() % 100000;
	for(int i = 0; i < n3; i++)
		arr3[i] = rand() % 100000;
	for(int i = 0; i < n4; i++)
		arr4[i] = rand() % 100000;

	clock_t st = 0, et = 0;
	double gap = 0;

	memcpy(temp, arr1, n1 * sizeof(int));

	// 100
	// insert sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	cout << "Insert Sorting Result(100): " << endl;	
	st = clock();
	insertionSort(arr1, n1);
	et = clock();

	printArray(arr1, n1);

	int insert_sort_compare_count100 = compare_count;
	int insert_sort_swaping_count100 = swaping_count;
	int insert_sort_copying_count100 = copying_count;
	int insert_sort_gap100 = et - st;
		 
	// quick sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	memcpy(arr1, temp, n1 * sizeof(int));
	cout << "Quick Sorting Result(100): " << endl;	
	st = clock();
	quickSort(arr1, 0, n1 - 1);
	et = clock();
	printArray(arr1, n1);

	int quick_sort_compare_count100 = compare_count;
	int quick_sort_swaping_count100 = swaping_count;
	int quick_sort_copying_count100 = copying_count;
	int quick_sort_gap100 = et - st;



	// merge sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	memcpy(arr1, temp, n1 * sizeof(int));
	cout << "Merge Sorting Result(100): " << endl;	
	st = clock();
	mergeSort(arr1, 0, n1 - 1);
	et = clock();
	printArray(arr1, n1);

	int merge_sort_compare_count100 = compare_count;
	int merge_sort_swaping_count100 = swaping_count;
	int merge_sort_copying_count100 = copying_count;
	int merge_sort_gap100 = et - st;

	// 1000
	memcpy(temp, arr2, n2 * sizeof(int));

	// insert sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	cout << "Insert Sorting Result(1000): " << endl;	
	st = clock();
	insertionSort(arr2, n2);
	et = clock();
	printArray(arr2, n2);

	int insert_sort_compare_count1000 = compare_count;
	int insert_sort_swaping_count1000 = swaping_count;
	int insert_sort_copying_count1000 = copying_count;
	int insert_sort_gap1000 = et - st;


	// quick sort
	memcpy(arr2, temp, n2 * sizeof(int));
	compare_count = 0, copying_count = 0, swaping_count = 0;
	cout << "Quick Sorting Result(1000): " << endl;	
	st = clock();
	quickSort(arr2, 0, n2 - 1);
	et = clock();
	printArray(arr2, n2);

	int quick_sort_compare_count1000 = compare_count;
	int quick_sort_swaping_count1000 = swaping_count;
	int quick_sort_copying_count1000 = copying_count;
	int quick_sort_gap1000 = et - st;


	// merge sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	memcpy(arr2, temp, n2 * sizeof(int));
	cout << "Merge Sorting Result(1000): " << endl;	
	st = clock();
	mergeSort(arr2, 0, n2 - 1);
	et = clock();
	printArray(arr2, n2);

	int merge_sort_compare_count1000 = compare_count;
	int merge_sort_swaping_count1000 = swaping_count;
	int merge_sort_copying_count1000 = copying_count;
	int merge_sort_gap1000 = et - st;


	// 5000
	memcpy(temp, arr3, n3 * sizeof(int));

	// insert sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	st = clock();
	insertionSort(arr3, n3);
	et = clock();
	
	int insert_sort_compare_count5000 = compare_count;
	int insert_sort_swaping_count5000 = swaping_count;
	int insert_sort_copying_count5000 = copying_count;
	int insert_sort_gap5000 = et - st;

	// quick sort
	memcpy(arr3, temp, n3 * sizeof(int));
	compare_count = 0, copying_count = 0, swaping_count = 0;	
	st = clock();
	quickSort(arr3, 0, n3 - 1);
	et = clock();
	
	int quick_sort_compare_count5000 = compare_count;
	int quick_sort_swaping_count5000 = swaping_count;
	int quick_sort_copying_count5000 = copying_count;
	int quick_sort_gap5000 = et - st;


	// merge sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	memcpy(arr3, temp, n3 * sizeof(int));	
	st = clock();
	mergeSort(arr3, 0, n3 - 1);
	et = clock();	

	int merge_sort_compare_count5000 = compare_count;
	int merge_sort_swaping_count5000 = swaping_count;
	int merge_sort_copying_count5000 = copying_count;
	int merge_sort_gap5000 = et - st;

	// 10000
	memcpy(temp, arr4, n4 * sizeof(int));

	// insert sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	st = clock();
	insertionSort(arr4, n4);
	et = clock();

	int insert_sort_compare_count10000 = compare_count;
	int insert_sort_swaping_count10000 = swaping_count;
	int insert_sort_copying_count10000 = copying_count;
	int insert_sort_gap10000 = et - st;

	// quick sort
	memcpy(arr4, temp, n4 * sizeof(int));
	compare_count = 0, copying_count = 0, swaping_count = 0;	
	st = clock();
	quickSort(arr4, 0, n4 - 1);
	et = clock();

	int quick_sort_compare_count10000 = compare_count;
	int quick_sort_swaping_count10000 = swaping_count;
	int quick_sort_copying_count10000 = copying_count;
	int quick_sort_gap10000 = et - st;


	// merge sort
	compare_count = 0, copying_count = 0, swaping_count = 0;
	memcpy(arr4, temp, n4 * sizeof(int));	
	st = clock();
	mergeSort(arr4, 0, n4 - 1);
	et = clock();	

	int merge_sort_compare_count10000 = compare_count;
	int merge_sort_swaping_count10000 = swaping_count;
	int merge_sort_copying_count10000 = copying_count;
	int merge_sort_gap10000 = et - st;

	// Print the counted steps for sorting 100, 1,000, 5,000 and 10,000 numbers.
	printf("Insert Sorting 100, Compare = %d, Swapping = %d, Copying = %d\n", insert_sort_compare_count100, insert_sort_swaping_count100, insert_sort_copying_count100);
	printf("Quick Sorting 100, Compare = %d, Swapping = %d, Copying = %d\n", quick_sort_compare_count100, quick_sort_swaping_count100, quick_sort_copying_count100);
	printf("Merge Sorting 100, Compare = %d, Swapping = %d, Copying = %d\n", merge_sort_compare_count100, merge_sort_swaping_count100, merge_sort_copying_count100);

	printf("Insert Sorting 1000, Compare = %d, Swapping = %d, Copying = %d\n", insert_sort_compare_count1000, insert_sort_swaping_count1000, insert_sort_copying_count1000);
	printf("Quick Sorting 1000, Compare = %d, Swapping = %d, Copying = %d\n", quick_sort_compare_count1000, quick_sort_swaping_count1000, quick_sort_copying_count1000);
	printf("Merge Sorting 1000, Compare = %d, Swapping = %d, Copying = %d\n", merge_sort_compare_count1000, merge_sort_swaping_count1000, merge_sort_copying_count1000);


	printf("Insert Sorting 5000, Compare = %d, Swapping = %d, Copying = %d\n", insert_sort_compare_count5000, insert_sort_swaping_count5000, insert_sort_copying_count5000);
	printf("Quick Sorting 5000, Compare = %d, Swapping = %d, Copying = %d\n", quick_sort_compare_count5000, quick_sort_swaping_count5000, quick_sort_copying_count5000);
	printf("Merge Sorting 5000, Compare = %d, Swapping = %d, Copying = %d\n", merge_sort_compare_count5000, merge_sort_swaping_count5000, merge_sort_copying_count5000);


	printf("Insert Sorting 10000, Compare = %d, Swapping = %d, Copying = %d\n", insert_sort_compare_count10000, insert_sort_swaping_count10000, insert_sort_copying_count10000);
	printf("Quick Sorting 10000, Compare = %d, Swapping = %d, Copying = %d\n", quick_sort_compare_count10000, quick_sort_swaping_count10000, quick_sort_copying_count10000);
	printf("Merge Sorting 10000, Compare = %d, Swapping = %d, Copying = %d\n", merge_sort_compare_count10000, merge_sort_swaping_count10000, merge_sort_copying_count10000);


	// Record the computer times and print them for above running as well.
	printf("Insert Sorting 100, Time = %d ms\n", insert_sort_gap100);
	printf("Quick Sorting 100, Time = %d ms\n", quick_sort_gap100);
	printf("Merge Sorting 100, Time = %d ms\n", merge_sort_gap100);
	
	printf("Insert Sorting 1000, Time = %d ms\n", insert_sort_gap1000);
	printf("Quick Sorting 1000, Time = %d ms\n", quick_sort_gap1000);
	printf("Merge Sorting 1000, Time = %d ms\n", merge_sort_gap1000);

	printf("Insert Sorting 5000, Time = %d ms\n", insert_sort_gap5000);
	printf("Quick Sorting 5000, Time = %d ms\n", quick_sort_gap5000);
	printf("Merge Sorting 5000, Time = %d ms\n", merge_sort_gap5000);

	printf("Insert Sorting 10000, Time = %d ms\n", insert_sort_gap10000);
	printf("Quick Sorting 10000, Time = %d ms\n", quick_sort_gap10000);
	printf("Merge Sorting 10000, Time = %d ms\n", merge_sort_gap10000);



	delete arr1;
	delete arr2;
	delete arr3;
	delete arr4;
	delete temp;

	return 0;
}