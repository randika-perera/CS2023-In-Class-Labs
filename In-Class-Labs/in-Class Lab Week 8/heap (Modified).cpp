#include <iostream>
using namespace std;




// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify


    // Find what is the largest among root, left child, and right child
    int largest = root;     // initialize largest as root
    int l = 2 * root + 1;   // left child index
    int r = 2 * root + 2;   // right child index

    if (l < n && arr[l] > arr[largest]) // if left child is larger than the root
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) // if right child is larger than the largest so far
    {
        largest = r;
    }

    // If largest is NOT root, swap root with the largest element and heapify the affected sub-tree
    if (largest != root) 
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }


}




// implementing heap sort
void heapSort(int arr[], int n)
{


   // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);   
    }


   // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--) 
    {
        swap(arr[0], arr[i]);   // Move the root (largest element) to the end of the array
        heapify(arr, i, 0);     // Heapify the reduced heap (from 0 to i-1)
    }
    

}




/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
    cout << arr[i] << " ";
    cout << "\n";
}




// main program
int main()
{
    int heap_arr[] = {4,17,3,12,9,6};
    //int heap_arr[] = {67,5,32,49,90,37,12,86,1,25,48}; //A different input from the given sample
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}



