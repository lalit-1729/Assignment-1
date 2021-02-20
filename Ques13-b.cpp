//This program takes the input from the user
//Validates the input
//And returns the factorial of it

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Factorial Without Using Recursion :: \n";
    cout << "\t\t :: Valid output for 0-12 only ::\n\n"; //Due to four byte limit of the int data type
    //It can be increased by using long long int, but it also won't be of use after a certain limit
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
bool compare_strings(string string1, string string2){
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



//factorial function without recursion
//Simple for loop is used for this purpose
int compute_factorial(int number){
    int factorial = 1;
    if(number == 0){ //factorial of 0 is 1 ,i.e 0! = 1
        return 1;
    }
    else{
        for(int i = 2; i<=number; i++){
            factorial *= i;
        }
        return factorial;
    }
}

//Takes the input from the user
void take_input(string *user_input){
    cout << "Enter a number to calculate Factorial: ";
    cin >> *user_input;
}

/*since in mathematics the factorial function is not defined for the negative number
  and also not for fractional number, therefore validation is required to prevent the malfunctioning
  of the program and this function does that for us.*/
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}

/*Since a normal integer is of 32 bits only therefore it maximum value is limited to 2^(31)-1
  and therefore the validation is of the input is required so that the output is correct,
  and this function helps us with the same. */
bool is_input_in_range(string user_input){
    int number = stoi(user_input);
    if(number <= 12)
        return true;
    else
        return false;
}

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

        //input validation
        while(!is_input_valid(user_input) || !is_input_in_range(user_input)){
            cout << "Invalid input, please try again with a valid one.\n";
            take_input(&user_input);
        }

        int number = stoi(user_input); //converting the valid input string to integer
        cout << endl << "Factorial of " << number << " is " << compute_factorial(number) << endl;

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
