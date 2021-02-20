//this program takes the input form the user and validates it
//And returns the average of the seven input marks

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t:: Average of your seven subjects marks ::\n";
    cout << "\t\t  :: Range of marks is from 0 to 100 :: \n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

/* Similar to that of 'strcmp' function of string.h, here we are comparing every single character of both string
   this function will will used later in the program run-again loop for input validation */
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

void take_input(string *user_input, int i){
    cout << "Enter the marks of subject: " << i+1 << ": ";
    cin >> *user_input;
}

/* since the marks can't be negative, and fractional marks are allowed here,
  we will validate the user input by referring to each character of the user input's
  ASCII code and validating it.*/
bool is_input_numeric(string user_input){
    int dot_count = 0;
    for(int i = 0 ; user_input[i] != '\0' ; i++){
        //using ASCII code to look for numeric characters only
        if(user_input[i] < 48 || user_input[i] > 57){
            if(user_input[i] == '.'){ // For fractional number
                dot_count++;
                //a fractional number can have only one dot to separate the integer and fractional part
                if(dot_count > 1)
                    return false;
                else
                    continue;
            }
            return false;
        }
    }
    return true;
}

//Validating the range of the marks provided by the programmer
bool is_range_valid(string user_input, int upper_limit, int lower_limit){
    float marks = stof(user_input); //string to float conversion
    if(marks >= lower_limit && marks <= upper_limit)
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


//Main Method
int main(void){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        float sum_of_marks = 0;

        for(int i = 0 ; i<7 ; i++){
            take_input(&user_input, i);

            //Input validation
            while( !is_input_numeric(user_input) || !is_range_valid(user_input, 100, 0)){
                cout << "Invalid input, please try again : ";
                cin >> user_input;
            }
            sum_of_marks += stof(user_input); //Converting valid input string to float
        }

        cout << "\nThe average of the marks is: " <<  sum_of_marks/7 << "\n\n"; //Results
        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
