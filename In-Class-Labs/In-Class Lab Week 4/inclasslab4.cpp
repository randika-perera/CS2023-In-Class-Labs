#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;



void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}



void recursive_mergesort(int arr[], int left,int right)
{
    if (left>=right)
    {
        return;
    }
    int mid=(left+right)/2;
    recursive_mergesort(arr,left,mid);
    recursive_mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
    
}



void iterative_mergesort(int arr[], int n)
{
   int curr_size;               
   int left_start; 
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           int mid = min(left_start + curr_size - 1, n-1);
           int right_end = min(left_start + 2*curr_size - 1, n-1);
           merge(arr, left_start, mid, right_end);
       }
   }
}



int main()
{

    cout <<endl;

    for (int sz=500;sz<=10000;sz=sz+500)   //Create random arrays of size 500,1000,1500,2000,......9500,10000
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
    for (int i ;i<sz ;i++)    //Make a copy of random array to do recursive merge sort
    {
        myarray1[i]=randArray[i];
    }
    for (int i ;i<sz ;i++)    //Make a copu of random array to do iterative merge sort
    {
        myarray2[i]=randArray[i];
    }
    
    
    //Do recurive merge sort and measure time taken
    auto start1 = chrono::high_resolution_clock::now();
    recursive_mergesort(myarray1, 0, sz - 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout <<endl;
    cout << "~ Time taken by Recursive Merge Sort : "<< duration1.count() << " microseconds";


    //Do iterative merge sort and measure time taken
    auto start2 = chrono::high_resolution_clock::now();
    iterative_mergesort(myarray2, sz );
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout <<endl;
    cout << "~ Time taken by Iterative Merge Sort : "<< duration2.count() << " microseconds";

    }

    cout <<endl <<endl;

    return 0;
}