//*********i was only able to implement this algorithm after having some youtube gyan, i.e. i have watch the implementation and then applied here....*********

// Here, we are using the quick sort method
// it is the method, that uses the divide and rule strategy
// we will implement it by defining the two function
// partition function, to divide the array across the pivot point in two array , one containing elements smaller than pivot point and other containing the elements greater than pivot point
// quick_sort, uses to recursion to perform partition on the sub-arrays

#include <iostream>
#include <stdlib.h>
using namespace std;

// partition function
int partition(int arr[], int lower_bound , int upper_bound){
    int start = lower_bound, end = upper_bound, pivot = arr[lower_bound];
    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }

        while(arr[end] > pivot ){
            end--;
        }

        if(start < end){
            swap(arr[end], arr[start]);
        }
    }

    swap(arr[lower_bound] , arr[end]);
    /*for(int i = 0; i <= upper_bound ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;*/
    return end;

}


// quick_sort function
void quick_sort(int arr[], int lower_bound, int upper_bound){
    int location;
    if(lower_bound < upper_bound){
        location = partition(arr, lower_bound, upper_bound);

        quick_sort(arr, lower_bound, location - 1);
        quick_sort(arr, location + 1, upper_bound);
    }
}


int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int array_size;
        cout << "Enter the size of the array: ";
        cin >> array_size;

        // array input
        cout << "Enter the array elements: \n";
        int input_array[array_size];
        for(int i = 0; i<array_size ; i++){
            cin >> input_array[i];
        }

        cout << endl;

        quick_sort(input_array, 0, array_size-1);

        // array output
        cout << "The sorted array is: \n";
        for(int i = 0; i < array_size ; i++){
            cout << input_array[i] << " ";
        }

        //asking to run again
        cout << "\n\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
