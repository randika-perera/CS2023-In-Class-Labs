#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std::chrono;
using namespace std;

/*------------------Set of Functions for Recursive Quick Sort-------------------------*/

//Defining Swap Function
void swap_r(int arr[] , int pos1, int pos2)
{
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

//Defining Partition Function
int partition_r(int arr[], int low, int high, int pivot)
{
	int i = low;
	int j = low;
	while( i <= high)
    {
		if(arr[i] > pivot)
        {
			i++;
		}
		else
        {
			swap_r(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

//Defining Recursive Quick Sort Function
void quickSortRecursive(int arr[], int low, int high)
{
	if(low < high){
	int pivot = arr[high];
	int pos = partition_r(arr, low, high, pivot);
	
	quickSortRecursive(arr, low, pos-1);
	quickSortRecursive(arr, pos+1, high);
	}
}


/*-------------------Set of Functions for Non-Recursive Quick Sort-----------------*/

//Defining swap function
void swap_i(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
//Defining partition function
int partition_i(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap_i(&arr[i], &arr[j]);
        }
    }
    swap_i(&arr[i + 1], &arr[h]);
    return (i + 1);
}
  
//Defining Non-Recursive Quick Sort Function
void quickSortIterative(int arr[], int l, int h)
{
    int stack[h - l + 1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;
    while (top >= 0) 
    {
        h = stack[top--];
        l = stack[top--];
        int p = partition_i(arr, l, h);
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < h) 
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}





int main()
{
    // First we will create random arrays of size 500,1000,1500,2000,......9500,10000
    cout <<endl;
    for (int sz=500;sz<=10000;sz=sz+500)   
    {
    int randArray[sz];
    cout <<endl <<endl;
    cout <<"When size of the random array is " <<sz <<",";
    for (int j=0; j<sz; j++)
    {
        randArray[j]=rand()%100;
    }
    int myarray1[sz];
    int myarray2[sz];
    // Make a copy of the random array to do recursive quick sort
    for (int i ;i<sz ;i++)    
    {
        myarray1[i]=randArray[i];
    }
    // Make a copy of the random array to do iterative quick sort
    for (int i ;i<sz ;i++)    
    {
        myarray2[i]=randArray[i];
    }
    // Do recurive quick sort and measure time taken
    auto start1 = chrono::high_resolution_clock::now();
    quickSortRecursive(myarray1, 0, sz - 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout <<endl;
    cout << "~ Time taken by Recursive Quick Sort : "<< duration1.count() << " microseconds";
    // Do non-recursive(iterative) quick sort and measure time taken
    auto start2 = chrono::high_resolution_clock::now();
    quickSortIterative(myarray2, 0, sz - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout <<endl;
    cout << "~ Time taken by Iterative Quick Sort : "<< duration2.count() << " microseconds";
    }
    cout <<endl <<endl;
    return 0;
}