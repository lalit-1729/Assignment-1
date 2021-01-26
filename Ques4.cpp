//This program takes the input form the user
//And check whether the given string is palindrome or not
//No input validation required

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes the input from the user
void take_input(string *input_string){
    cout << "Enter a string a without space: ";
    cin >> *input_string;
}

//Computes the length of the string
int string_length(string input_string){
    int string_size = 0;
    while(input_string[string_size] != '\0'){ // a string is always terminated by '\0' character
        string_size++;
    }
    return string_size;
}

//Checks for the palindorme string and return the results
void check_for_palindrome(string input_string, int string_size){
    int is_palindrome = false;

    for(int index = 0; index < string_size/2 ; index++){
        if(input_string[index] != input_string[string_size - 1 - index]){
            is_palindrome = true;
            break;
        }
    }

    if(is_palindrome == true){
        cout << endl << "It is not a palindrome."<< endl;
    }
    else{
        cout << endl << "It is a Palindrome."<< endl;
    }
    return;
}

//asks user to rerun the program and returns a bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> continue_program;

    //input validation, validates only lowercase 'y' & 'n'
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        cout << "\n\nYOU JUST QUIT THE PROGRAM...!!!\n\n";
        return false;
    }
}

int main(){
    do{
        system("cls"); //clears the console after every successful run
        cout << "\n\n\t\t :: Checks For Palindrome :: \n\n";

        string input_string;
        take_input(&input_string);

        int input_string_size = string_length(input_string);
        check_for_palindrome(input_string, input_string_size);

    }while(want_to_run_again() == true);

    return 0;
}
