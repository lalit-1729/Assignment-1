//This program takes input from the user
//Validates the input
//And using the Recursion technique it prints the factorial

#include <iostream>
#include <stdlib.h>
using namespace std;

//factorial function with recursion
int factorial_of(int number){
    if(number != 1){
        return number*factorial_of(number-1);
    }
    //factorial of 0 ,i.e 0! is 1
    else if(number == 0){
        return 1;
    }
    else{
        return 1;
    }
}

//takes the user input
void take_input(string *user_input){
    cout << "Enter a number: ";
    cin >> *user_input;
}

//validates only non-negative integer
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//asks user to rerun the program and returns a bool value accordingly
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
        system("cls");//clears the screen after every successful run
        cout << "\n\n\t\t :: Factorial With Recursion :: \n\n";

        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_input_valid(user_input)){
            cout << "Invalid input, please try again with a valid one, ";
            take_input(&user_input);
        }

        int number = stoi(user_input);// converting a valid input string to integer
        cout << "Factorial is " << factorial_of(number) << endl;

    }while(want_to_run_again() == true);

    return 0;
}
