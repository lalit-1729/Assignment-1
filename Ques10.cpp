// Here, we are using the quick sort method
// it is the method, that uses the divide and rule strategy
// we will implement it by defining the two function
// partition function, to divide the array across the pivot point in two array , one containing elements smaller than pivot point and other containing the elements greater than pivot point
// quick sort, uses recursion to perform partition on the sub-arrays

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes input form the user
void take_input(string *user_input){
    cout << "Enter the size of the array: ";
    cin >> *user_input;
}

//Takes the array input from the user
void take_array_input(int *arr, int array_size){
    cout << "Enter the array elements: \n";
    for(int i = 0;i<array_size ; i++){
        cin >> *(arr+i);
    }
}

//Validates only the positive values
bool is_input_valid(string user_input){
    for(int i = 0;user_input[i] != '\0'; i++){ // running the loop till the terminating value
        //using the ASCII table to verify, ACSII code for '0'=48 and '9'=57
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Prints the sorted array
void show_sorted_array(int *arr, int array_size){
    cout << "\nThe sorted Array is: \n";
    for(int i = 0; i<array_size ; i++){
        cout << *(arr+i)<< " ";
    }
    cout << endl;
}

//Partition function
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

//Asks user to run again & takes action accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes) / (n for no)" << endl;
    cin >> continue_program;

    //input validation
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, please enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    do{
        system("cls");//clears the console window after every successful run
        cout << "\n\n\t\t :: Quick Sort :: \n\n\n";
        string user_input;
        take_input(&user_input);

        //input validation
        while(is_input_valid(user_input) == false){
            cout << "Invalid Input:\n";
            take_input(&user_input);
        }

        //converting the valid input to integer
        int array_size = stoi(user_input);
        int user_array_input[array_size];

        take_array_input(user_array_input, array_size);

        quick_sort(user_array_input, 0, array_size-1);
        //Results
        show_sorted_array(user_array_input, array_size);

    }while(want_to_run_again() == true);

    return 0;
}
