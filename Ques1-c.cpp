//This program takes the input from the user and validates it
//And then prints pattern similar to shown below
//--------------+
// for n = 6    |
//              |
//      $       |
//     $$$      |
//    $$$$$     |
//   $$$$$$$    |
//  $$$$$$$$$   |
// $$$$$$$$$$$  |
//--------------+

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls");
    cout << "\n\n\t\tSample pattern, for m = 4:\n\t\t      :    *\n\t\t\t  ***\n\t\t\t *****\n\t\t\t******* :\n\n"; // Program introduction
}

int string_length(string function_string){
    int string_len = 0;
    for(string_len = 0 ;function_string[string_len] != '\0'; string_len++);  //Running till the null character
    return string_len;
}

bool compare_strings(string string1, string string2){
    if(string_length(string1) != string_length(string2))
        return false;
    else{
        for(int i = 0; i<string_length(string1) ; i++){
            if(string1[i] != string2[i]){
                return false;
            }
        }
    }
    return true;
}

void take_input(string *user_input){
    cout << "Enter the number of rows of patterns: "<< endl;
    cin >> *user_input;
}

bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII to look for only numeric character
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}

// function to print the pattern
void print_pattern(int no_of_rows){
    for(int row = 0; row < no_of_rows ; row++){
        for(int space = 1; space < no_of_rows - row ; space++ )
            cout << " ";
        for(int character = 0; character < (2*row + 1) ; character++)
            cout << "$";
        cout << endl;
    }
    return;
}

//asks user to rerun the program
void want_to_run_again(string *user_input){
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> *user_input;

    //input validation, only y, Y, N, n are allowed
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
        while(!is_input_valid(user_input)){
            cout << "Invalid Input, please try again with a valid one:\n";
            take_input(&user_input);
        }

        int no_of_rows = stoi(user_input);//Converting the valid string to integer
        print_pattern(no_of_rows);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
