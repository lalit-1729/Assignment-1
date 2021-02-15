//This program takes input from the user
//Validates the input
//And using the Recursion technique it prints the factorial of the given number

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Factorial Using Recursion :: \n";
    cout << "\t\t :: Valid output for 0-12 only ::\n\n"; //Due to four byte limit of the int data type
    //It can be increased by using long long int, but it won't be of use after a certain limit
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

bool compare_strings(string string1, string string2){ //Similar to that of 'strcmp' function of string.h
    if(string_length(string1) != string_length(string2))
        return false;
    else{
        for(int i = 0; i<string_length(string1) ; i++){
            if(string1[i] != string2[i])
                return false;
        }
    }
    return true;
}

//factorial function with recursion
//In the recursion technique the function itself is called
//in its own declaration till a specific result is obtained
int compute_factorial(int number){
    if(number != 1){
        return number*compute_factorial(number-1);
    }
    //factorial of 0 ,i.e 0! is 1
    else if(number == 0){
        return 1;
    }
    else{
        return 1;
    }
}

void take_input(string *user_input){
    cout << "Enter a number: ";
    cin >> *user_input;
}

bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}

bool is_input_in_range(string user_input){
    int number = stoi(user_input);
    if(number <= 12)
        return true;
    else
        return false;
}

//asks user to rerun the program
void want_to_run_again(string *user_input){
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> *user_input;

    //input validation, only y, n, Y, N are allowed
    while( !( compare_strings(*user_input, "y") || compare_strings(*user_input, "n") ||
             compare_strings(*user_input, "Y") || compare_strings(*user_input, "N")) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> *user_input;
    }
}


int main(void){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_input_valid(user_input) || !is_input_in_range(user_input)){
            cout << "Invalid input, please try again with a valid one, ";
            take_input(&user_input);
        }

        int number = stoi(user_input);// converting a valid input string to integer
        cout << "Factorial is " << compute_factorial(number) << endl;
        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
