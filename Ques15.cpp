//This program take the input from the user
//Validates it as a year and prints whether its a leap year or not

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Check For A Leap Year ::\n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

/*This function is declared here to fixed the bug in the run-again loop
  As two strings can't be simply compared by str1 == str2, therefore this function is declared to compare the strings
  , by comparing the length first and then each character of the string.*/
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

//Takes the input from the user
void take_input(string *user_input){
    cout << "Enter a year: ";
    cin >> *user_input;
}

/*since a year can't be negative and fractional, therefore validation as to be done,
  to prevent the malfunctioning of the program , and this function helps us with the same.*/
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code to validate only numeric charcaters
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Leap year is a year in which has 366 days
//A leap year is always divisible by 4
//but if a year is a multiple of 100 then to be a leap year
//it should also be divisible by 400
void check_for_leap_year(int year){

    if( (year%100 == 0 && year%400 == 0) || (year%4 ==0 && year%100 != 0) )
        cout << "This is a Leap year." << endl;
    else
        cout << "This is not a leap year." << endl;
}

//Asking the user to run again
void want_to_run_again(string *user_input){
    cout << "\n\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
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
            cout << "Invalid input, please try again with a valid one, ";
            take_input(&user_input);
        }

        int year = stoi(user_input);// converting a valid input string to integer
        check_for_leap_year(year);
        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
