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
//  $$$$$$$$$   |
//   $$$$$$$    |
//    $$$$$     |
//     $$$      |
//      $       |
//--------------+

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the screen
    cout << "\n\n\t\t :: Pattern Printing ::\n\t\tSample pattern, for m = 3:\n\t\t      :   *\n\t\t\t ***\n\t\t\t*****\n\t\t\t ***\n\t\t\t  * :\n\n"; // Program introduction
}

int string_length(string function_string){
    int string_len = 0;
    for(string_len = 0 ;function_string[string_len] != '\0'; string_len++);  //Running till the null character ('\0', the terminating charcater)
    return string_len;
}

/* Similar to that of 'strcmp' function of string.h, here we are comparing every single character of both string
   this function will will used later in the program run-again loop for input validation to fix the bug*/
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
        // using the ACSII code to look for only numeric characters
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}

/*This function will print the pattern as shown in the intro of the this code,
  according to the no of rows entered by the user*/
void print_pattern(int no_of_rows){
    // the upper pattern including the largest row
    for(int row = 1; row<=no_of_rows ; row++){
        //Printing the spaces to keep the pattern symmetric vertically
        for(int space = 1; space <= no_of_rows-row ; space++ ) {// printing the spaces
            cout << " ";
        }
        for(int j = 0; j < (2*row - 1) ; j++){
            cout << "$";
        }
        cout << endl;
    }

    // the lower pattern
    for(int row = 0; row<no_of_rows ; row++){
        //Printing the spaces to keep the pattern symmetric vertically
        for(int space = row; space >= 0  ; space--){ // printing the spaces
            cout << " ";
        }
        for(int j = 1; j < 2*(no_of_rows-row) - 2 ; j++ ){
            cout << "$";
        }
        cout << endl;
    }
}

//This function will ask the user to run the program again. with a valid input
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


int main(){
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

        int input_num = stoi(user_input); //Converting the valid user input to an integer
        print_pattern(input_num);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
