#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;


void insertion_sort(int *arr, int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int currentvalue=arr[i]
        int pos=i
        while ((pos>0) and (currentvalue<arr[pos-])):
            arr[pos]=arr[pos-]
            pos=pos-1
        arr[pos]=currentvalue
    return arr
    }
}


void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void optimized_bubble_sort(int *arr, int n) {
    bool swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}


void selection_sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}


int main() {
    srand(time(nullptr)); // Seed the random number generator with the current time
    
    // Generate five random arrays with lengths in the range of [3, 20]
    for (int i = 0; i < 5; i++) {
        int length = rand() % 18 + 3; // Randomly choose a length between 3 and 20
        int* arr = new int[length]; // Allocate memory for the array
        
        // Fill the array with random numbers between 0 and 99
        for (int j = 0; j < length; j++) {
            arr[j] = rand() % 100;
        }
        
        int bubbleArr[length];
        int optimized_bubbleArr[length];
        int insertionArr[length];
        int selectiontionArr[length];
    
        // Copy the source array to the destination array
        for (int i = 0; i < length; i++) {
            bubbleArr[i] = arr[i];
        }
        for (int i = 0; i < length; i++) {
            optimized_bubbleArr[i] = arr[i];
        }
        for (int i = 0; i < length; i++) {
            insertionArr[i] = arr[i];
        }
        for (int i = 0; i < length; i++) {
            selectiontionArr[i] = arr[i];
        }


        // Print the array
        // cout << "Array " << i+1 << ": [";
        // for (int j = 0; j < length-1; j++) {
        //     cout << bubbleArr[j] << ", ";
        // }
        // cout << bubbleArr[length-1] << "]" << endl;
        
        delete[] arr; // Free the memory used by the array
        
        auto start_timei = high_resolution_clock::now();
        insertion_sort(insertionArr,length);
        auto end_timei = high_resolution_clock::now();
        auto durationi = duration_cast<nanoseconds>(end_timei - start_timei);
        cout<<"Total elements in insertino sort array: "<<length<<endl;
        cout << "Time taken to insertion sort the array: " << durationi.count() << " nanoseconds" << endl;

        auto start_timeb = high_resolution_clock::now();
        bubble_sort(bubbleArr,length);
        auto end_timeb = high_resolution_clock::now();
        auto durationb = duration_cast<nanoseconds>(end_timeb - start_timeb);
        cout<<"Total elements in bubble sort array: "<<length<<endl;
        cout << "Time taken to bubble sort the array: " << durationb.count() << " nanoseconds" << endl;

        auto start_timeob = high_resolution_clock::now();
        optimized_bubble_sort(optimized_bubbleArr,length);
        auto end_timeob = high_resolution_clock::now();
        auto durationob = duration_cast<nanoseconds>(end_timeob - start_timeob);
        cout<<"Total elements in optimized bubble sort array: "<<length<<endl;
        cout << "Time taken to optimized bubble sort the array: " << durationob.count() << " nanoseconds" << endl;
        
        auto start_times = high_resolution_clock::now();
        selection_sort(selectiontionArr,length);
        auto end_times = high_resolution_clock::now();
        auto durations = duration_cast<nanoseconds>(end_times - start_times);
        cout<<"Total elements in selection sort array: "<<length<<endl;
        cout << "Time taken to selection sort the array: " << durations.count() << " nanoseconds" << endl;
        cout<<"\n"<<endl;
        
    }
    
    return 0;
}