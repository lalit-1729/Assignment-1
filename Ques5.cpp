//THIS PROGRAM TAKES THE MAKRS OF SEVEN SUBJECT FROM THE USER
//AND RETRUN THE AVERAGE OF THE MARKS OF ALL THE SEVEN SUBJECTS

#include <iostream>
#include <stdlib.h>
using namespace std;


//Checking for any value other than numeric and '.'
bool is_input_valid(string user_input){
    int i = 0;
    while(user_input[i] != '\0'){
        //using assic code to validate
        if(user_input[i] < 48 || user_input[i] > 57){
            if(user_input[i] == '.'){
                i++;
                continue;
            }
            return false;
        }
        i++;
    }
    return true;
}


//Validates the range of the input
bool is_range_valid(string user_input){
    //string to float conversion
    float user_marks = stof(user_input);
    if(user_marks > -1 && user_marks < 101){
        return true;
    }
    else{
        return false;
    }
}


//Takes the input form the user
void take_input(string *user_input, int i){
    cout << "Enter the marks of subject: " << i+1 << ": ";
    cin >> *user_input;
}


//Ask user to rerun and validates the input
void ask_to_run_again(char *continue_program){

    cout << "Would you like to run the program again? (y for yes) / (n for no)" << endl;
    cin >> *continue_program;
    while( !( *continue_program == 'y' || *continue_program == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> *continue_program;
    }
}



int main(){
    char continue_program = 'y';
    do{

        system("cls"); // Clears the console window after every successful run
        cout << "\n\n\t\t:: Average of your seven subjects marks ::\n";
        cout << "\t\t  :: Range of marks is from 0 to 100 :: \n\n";

        string user_marks;
        float sum_of_marks = 0;
        int i = 0;

        while(i<7){
            take_input(&user_marks, i);

            //Input validation
            while( !is_input_valid(user_marks) || !is_range_valid(user_marks)){
                cout << "invalid input, please try again : ";
                cin >> user_marks;
            }
            sum_of_marks += stof(user_marks);
            i++;
        }

        cout << "\nThe average of the marks is: " <<  sum_of_marks/7 << "\n\n";
        ask_to_run_again(&continue_program);
    }while(continue_program == 'y');

    cout << "\n\n\t\t YOU JUST QUIT THE PROGRAMN....!!!\n\n";

    return 0;
}
