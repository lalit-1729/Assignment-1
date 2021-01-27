//This program takes the input form the user
//Validates the input
//And prints the first n terms of the Fibonacci sequence

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes the input from the user
void take_input(string *user_input){
    cout << "Enter a Number: ";
    cin >> *user_input;
}

//Checking for only non-negative integer
bool is_number_valid(string user_input){
    for(int i = 0; user_input[i] != '\0'; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Asks the user to rerun the program and returns bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\n\nWould you like to run the program again? (y for yes) / (n for no)" << endl;
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
        cout << "\n\n\t\tYOU JUST QUIT THE PROGRAM...!!!" << endl;
        return false;
    }
}

//prints the first n terms of the Fibonacci Sequence
void print_fibonacci_pattern(int number){
    int next_term = 0, temp_term = 1, previous_term = 0;

    for(int term = 0; term<number ; term++){
        next_term +=  previous_term;
        previous_term = temp_term;
        temp_term = next_term;

        cout << next_term << ' ';
    }
    return;
}

int main(){
    do{
        system("cls"); //clearing the console window after every successful run
        cout << "\n\n\t\t :: FIBONACCI PATTERN :: \n\n";

        string user_input;
        take_input(&user_input);

        //input validation
        while(is_number_valid(user_input) == false){
            cout << "Invalid input, please try again with a valid one,\n";
            take_input(&user_input);
        }

        int n = stoi(user_input); //converting a valid user string to integer
        cout << "The required patterns is: \n";
        print_fibonacci_pattern(n);

    }while(want_to_run_again() == true);

    return 0;
}
