#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
using namespace std::chrono;
using namespace std;




/*--------------------Defining a function to find the median and print it-------------------*/
void find_median(int arr[], int size)
{
    //Give median double data type
    double mid; 
    /* 
    If array has even number of elements, median = average of 2 middle elements
    If array has odd number of elements, median  = middle element
    */
    if (size % 2 == 0)
    {
        mid = (arr[(size/2)] + arr[size/2 - 1])*1.0/2.0;
    }
    else
    {
        mid = (arr[(size-1)/2])*1.0;
    }
    //Print median scaled to 1 decimal place
    cout <<endl <<"Running_Median = " <<mid <<setprecision(2) <<endl <<endl;
}




/*----------------Defining a function that can print elements of an array-----------*/
void print_array_elements(int arr[], int n)
{
	int i;
    cout<<"[ ";
	for (i = 0; i < n; ++i)
	{
         cout << arr[i] << " ";
    }
    cout<<"] ";
}




/*---------------We will use insertion sort the running list of integers-------------- */
/*Then we will call median function on the sorted sub-array to find the running median */
void insertion_sort_with_running_median(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        print_array_elements(arr,i);
        find_median(arr,i);
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}




int main()
{

    cout  <<endl;

    int size1 = 4;
    int array1[size1] = {7,3,5,2};
    cout <<"Input Array = [7,3,5,2]" <<endl <<endl;

    /* 
    Call insertion_sort_with_running_median function.
    This function will carry out insertion sort and print out the sorted 
    sub-arrays and will print out the median of the sorted sub-array.
    */
    insertion_sort_with_running_median(array1,size1);

    /*  
    After the array is fully sorted, manually call the print_array_elements function
    and find_median function to print the elements of the sorted array and to
    print the median of the final sorted array.
    */
    print_array_elements(array1,size1);
    find_median(array1,size1);


    /*
    Let's do the same as above for another array.
    */


    cout  <<endl <<endl;
    int size2 = 4;
    int array2[size2] = {1,11,4,7};   
    cout <<"Input array = [11,1,4,9]" <<endl <<endl;
    insertion_sort_with_running_median(array2,size2);
    print_array_elements(array2,size2);
    find_median(array2,size2);


    return 0;
}




