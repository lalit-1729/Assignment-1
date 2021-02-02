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


//function to print the required pattern
void print_pattern(int no_of_rows){

    // the upper pattern including the largest row
    for(int row = 0; row<no_of_rows ; row++){
        for(int space = 1; space < no_of_rows-row ; space++ ){ // printing the spaces
            cout << " ";
        }
        for(int j = 0; j < (2*row + 1) ; j++){
            cout << "$";
        }
        cout << endl;
    }

    // the lower pattern
    for(int row = 0; row<no_of_rows ; row++){
        for(int space = row; space >= 0  ; space--){ // printing the spaces
            cout << " ";
        }
        for(int j = 1; j < (2*(no_of_rows-row)-1) - 1 ; j++ ){
            cout << "$";
        }
        cout << endl;
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
        cout << "\n\nExample pattern, for m = 4: \n\t\t ::   *  \n\t\t     ***\n\t\t    *****\n\t\t   *******\n\t\t    *****\n\t\t     ***\n\t\t      *   ::\n\n";
        string user_input;
        take_input(&user_input);

        //input validation
        while(is_input_valid(user_input) == false){
            cout << "Invalid Input, please try again with a valid one:\n";
            take_input(&user_input);
        }

        int input_num = stoi(user_input);
        print_pattern(input_num);

    }while(want_to_run_again() == true);

    return 0;
}
