//This program takes the input form the user
//Validates the input
//And prints the first n terms of the Fibonacci sequence

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: FIBONACCI Sequence :: \n";
    cout << "\t\t :: Range of input is 0 to 48 ::\n\n"; //Due to 4-byte limit of the unsigned int
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

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

void take_input(string *user_input){
    cout << "Enter a Number: ";
    cin >> *user_input;
}

//Checking for only non-negative integer
bool is_number_valid(string user_input){
    for(int i = 0; user_input[i] != '\0'; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

bool is_input_in_range(string user_input){
    int number = stoi(user_input);
    if(number <= 48)
        return true;
    else
        return false;
}

//prints the first n terms of the Fibonacci Sequence
//In the Fibonacci Sequence the next term is given as a sum of previous two terms
void print_fibonacci_pattern(short int number){
    cout << "\nThe Fibonacci sequence of n terms is: \n\n";
    unsigned int next_term = 0, temp_term = 1, previous_term = 0;

    for(int term = 0; term<number ; term++){
        next_term +=  previous_term;
        previous_term = temp_term;
        temp_term = next_term;

        cout << next_term << ' ';
    }
    return;
}

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


int main(void){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_number_valid(user_input) || !is_input_in_range(user_input)){
            cout << "Invalid input, please try again with a valid one,\n";
            take_input(&user_input);
        }

        short int n = stoi(user_input); //converting a valid user string to integer
        print_fibonacci_pattern(n);
        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
