// this implementation is just using the same concept from the previous question
//It takes the input from the user
// Validates the input
//And performs the Quick sort on the provided string

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes input from the user
void take_input(string *user_input){
    cout << "\nEnter a string of lower case only:\n";
    cin >> *user_input;
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
        string_size++;
    }
    return string_size;
}

//Validates only alphabetic string
bool is_input_valid(string user_input){
    for(int i = 0;user_input[i] != '\0'; i++){ // running the loop till the terminating value
        //using the ASCII table to verify, ACSII code for 'a'= 97 and 'z'= 122
        if(user_input[i] < 97 || user_input[i] > 122){
            return false;
        }
    }
    return true;
}


// partition function
int partition(char *function_string, int lower_bound, int upper_bound){
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
string quick_sort(char *function_string, int lower_bound, int upper_bound){
    int location;
    if(lower_bound < upper_bound){
        location = partition(function_string, lower_bound, upper_bound);

        quick_sort(function_string, lower_bound, location-1);
        quick_sort(function_string, location+1, upper_bound);
    }
    return function_string;
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
        cout << "\n\n\t\t YOU JUST QUIT THE PROGRAM....!!!!\n\n";
        return false;
    }
}


int main(){
    do{
        system("cls");//Clears the console window after every successful run
        cout << "\n\n\t\t :: QUICK SORT OVER ALPHABETIC STRING :: \n\n";
        string user_input;
        take_input(&user_input);

        //Input Validation
        while(is_input_valid(user_input) == false){
            cout << "Invalid Input, please try again with a valid one:\n";
            take_input(&user_input);
        }

        int string_size = string_length(user_input);
        user_input = quick_sort(&user_input[0], 0, string_size-1);
        cout << "\nSorted string in alphabetical order is: \n" << "==> " << user_input;

    }while(want_to_run_again() == true);
    return 0;
}
