//This program takes the input from the user
//Validates it
//And prints the Fibonacci sequence accordingly

#include <iostream>
#include <stdlib.h>
using namespace std;

//to take the user input
void take_input(string *user_input){
    cout << "Enter the number of rows of patterns: "<< endl;
    cin >> *user_input;
}

//Validates only non-negative integers only
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}


// function to print the fibonacci pattern
void print_fibonacci_pattern(int no_of_terms){
    int next_term = 0, previous_term = 1, temp_term = 0;
    for(int term = 0;  ; term++){
        if(next_term > no_of_terms){
            break;
        }

        cout << next_term << ' ';
        previous_term +=  temp_term;
        temp_term = next_term;
        next_term = previous_term;

    }
    return;
}

//asks user to rerun the program and returns bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> continue_program;

    //input validation
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        cout << "\n\nYOU JUST QUIT THE PROGRAM...!!!\n";
        return false;
    }
}

int main(){
    do{
        system("cls");
        cout << "\n\nExample pattern, for m = 5: \n\t\t :: 0 1 1 2 3 ::\n\n";
        string user_input;
        take_input(&user_input);

        //input validation
        while(is_input_valid(user_input) == false){
            cout << "Invalid Input, please try again with a valid one:\n";
            take_input(&user_input);
        }

        int n = stoi(user_input);
        print_fibonacci_pattern(n);

    }while(want_to_run_again() == true);
    return 0;
}
