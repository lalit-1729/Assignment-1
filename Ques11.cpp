// this implementation didn't needed any youtube gyan, it just using the same concept from the previous question
#include <iostream>
#include <stdlib.h>
using namespace std;

// partition function
int partition(char function_string[], int lower_bound, int upper_bound){
    int start = lower_bound, end = upper_bound;
    char pivot = function_string[lower_bound];
    while(start <  end){
        while(function_string[start] <= pivot){
            start++;
        }

        while(function_string[end] > pivot){
            end--;
        }

        if(start < end){ // swaping the terms
            char temp = function_string[start];
            function_string[start] = function_string[end];
            function_string[end] = temp;
        }
    }

    if(start > end){ // swaping the terms
        char temp = function_string[lower_bound];
        function_string[lower_bound] = function_string[end];
        function_string[end] = temp;
    }
    return end;
}


// quick sort function
void quick_sort(char function_string[], int lower_bound, int upper_bound){
    int location;
    if(lower_bound < upper_bound){
        location = partition(function_string, lower_bound, upper_bound);

        quick_sort(function_string, lower_bound, location-1);
        quick_sort(function_string, location+1, upper_bound);
    }
}

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int string_size;
        cout << "Enter the size of the string: ";
        cin >> string_size;
        char input_string[string_size];
        cout << "Enter a string having only lower case letters: " << endl << "==> ";
        cin >> input_string;

        // finding the string length
        int string_length = 0;
        while(input_string[string_length] != '\0'){
            string_length++;
        }

        cout << "\nSorted string in alphabetical order is: \n";
        quick_sort(input_string, 0, string_length-1);
        // printing output
        cout << "==> " << input_string;

        // asking to run_again
        cout << "\n\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
