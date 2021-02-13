//This program takes a string input from the user
//No validation is required here as our only task is to reverse it

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t\t :: Reversing A String :: \n";
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

string reverse_string(string user_input){
    int string_size = string_length(user_input);
    string reversed_string = user_input; //having a string of same length to changes it later
    for(int i = 1; i <= string_size ; i++){
        reversed_string[string_size - i] = user_input[i-1];
    }
    return reversed_string;
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

        string reversed_string = reverse_string(user_input);
        cout << "Reversed String: " << reversed_string << endl;

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
