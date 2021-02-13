//This program takes the input form the user
//And check whether the given string is palindrome or not
//No input validation required

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t\t:: Checks For Palindrome :: \n";
    cout << "\t\t:: You can enter alphanumeric character ::\n\n";
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

void take_input(string *user_input){
    cout << "Enter a string a without space: ";
    cin >> *user_input;
}

//Checks for the Palindorme string
void check_for_palindrome(string user_input){
    bool is_palindrome = true;
    int string_size = string_length(user_input);

    for(int index = 0; index < string_size/2 ; index++){
        if(user_input[index] != user_input[string_size - 1 - index]){
            is_palindrome = false;
            break;
        }
    }

    if(!is_palindrome)
        cout << endl << "It is not a palindrome."<< endl;
    else
        cout << endl << "It is a Palindrome."<< endl;

    return;
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

        check_for_palindrome(user_input); //Results are printed by this function

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
