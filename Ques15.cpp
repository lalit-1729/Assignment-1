//This program take the input from the user
//Validates it as a year and prints whether its a leap year or not

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes the input from the user
void take_input(string *user_input){
    cout << "Enter a year: ";
    cin >> *user_input;
}

//validating only non-negative integers
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//check for the leap year and displays the result
void check_for_leap_year(int year){

    if(year%100 == 0 && year%400 == 0){
        cout << "This is a Leap year." << endl;
        }
    else if( year%4 ==0 && year%100 != 0 ){
        cout << "This is a Leap year." << endl;
    }
    else{
        cout << "This is not a leap year." << endl;
    }
    return;
}

//asks user to rerun the program and takes action accordingly
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
        return false;
    }
}


int main(){

    do{
        system("cls"); //clear the console after every successful run
        cout << "\n\n\t\t :: Check For A Leap Year ::\n\n";
        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_input_valid(user_input)){
            cout << "Invalid input, please try again with a valid one, ";
            take_input(&user_input);
        }

        int year = stoi(user_input);// converting a valid input string to integer
        check_for_leap_year(year);

    }while(want_to_run_again() == true);

    return 0;
}
