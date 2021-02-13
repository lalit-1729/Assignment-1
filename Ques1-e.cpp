//This program takes the input from the user
//Validates it
//And prints the Fibonacci sequence accordingly

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the screen
    cout << "\n\n\t\t:: Printing The Fibonacci Sequence Less Than m ::";
    cout << "\n\t\t   Sample pattern, for m = 6 ::: 0 1 1 2 3 5\n\n";
}

int string_length(string function_string){
    int string_len = 0;
    for(string_len = 0 ;function_string[string_len] != '\0'; string_len++);  //Running till the null character ('\0', the terminating character)
    return string_len;
}

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

void take_input(string *user_input){
    cout << "Enter the number of rows of patterns: "<< endl;
    cin >> *user_input;
}

bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code to look for only numeric character
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}

// function to print the Fibonacci pattern
void print_fibonacci_pattern(int no_of_terms){
    int next_term = 0, previous_term = 1, temp_term = 0;
    for(int term = 0;  ; term++){
        if(next_term > no_of_terms)
            break;

        cout << next_term << ' ';
        previous_term +=  temp_term;
        temp_term = next_term;
        next_term = previous_term;
    }
    return;
}

//asks user to rerun the program
void want_to_run_again(string *user_input){
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> *user_input;

    //input validation
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

        int n = stoi(user_input); //Converting the valid user input to integer
        print_fibonacci_pattern(n);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
