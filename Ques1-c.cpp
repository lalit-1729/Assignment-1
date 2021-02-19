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
using namespace std;-9-9--

void refresh_screen(){
    system("cls");
    cout << "\n\n\t\t :: Pattern Printing ::\n\t\tSample pattern, for m = 4:\n\t\t      :    *\n\t\t\t  ***\n\t\t\t *****\n\t\t\t******* :\n\n"; // Program introduction
}

int string_length(string function_string){
    int string_len = 0;
    for(string_len = 0 ;function_string[string_len] != '\0'; string_len++);  //Running till the null character i.e. till '\0' , the terminating character
    return string_len;
}

/* Similar to that of 'strcmp' function of string.h, here we are comparing every single character of both string
   this function will will used later in the program run-again loop for input validation */
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

/* The no of rows can't be negative or fractional,
   therefore for the validation of the of the input this function is used,
   this function will take string as a argument check each characters ASCII code is in range or not
   and will return the bool value accordingly */
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII to look for only numeric character
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}

/*This function will print the pattern as shown in the intro of the this code,
  according to the no of rows entered by the user*/
void print_pattern(int no_of_rows){
    for(int row = 1; row <= no_of_rows ; row++){
        //Printing the spaces to keep the pattern symmetric
        for(int space = 1; space <= no_of_rows - row ; space++ ){
            cout << " ";
        }
        //Printing 2*n-1 characters in each row of the pattern, where n is the number of present row
        for(int character = 0; character < (2*row - 1) ; character++){
            cout << "$";
        }
        cout << endl; //New line for each new row
    }
    return;
}

//asks user to rerun the program
void want_to_run_again(string *user_input){
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> *user_input;

    //input validation, only y, Y, N, n are allowed as a valid input
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
