//This program takes the input from the user
//Verifies the input
//And converts the decimal input to binary form

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t:: Decimal to Binary Converter ::\n\n"; // Program introduction
}

int string_length(string function_string){
    int string_len;
    for(string_len = 0 ;function_string[string_len] != '\0'; string_len++);
    return string_len;
}

bool compare_strings(string string1, string string2){ //Similar to that of 'strcmp' function of string.h
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
    cout <<  "Enter a number between -128 to 127: ";
    cin >> *user_input;
}

bool is_range_valid(string user_input){
    if(stoi(user_input) < -128 || stoi(user_input) > 127)
        return false;
    else
        return true;
}

bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        //Using the ASCII code for validation
        if(i == 0 && user_input[i] == '-')
            continue;
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Computes the 2's complement
string compute_2s_complement(string magnitude_form){
    int index;
    for(index = 7; magnitude_form[index] != '1' ; index--); //finding the index of the first '1' in the string
    index--;

    //inverting each bit after the first '1'
    for( ; index >= 0 ; index--){
        if(magnitude_form[index] == '0')
            magnitude_form[index] = '1';
        else
            magnitude_form[index] = '0';
    }
    magnitude_form[0] = '1';
    return magnitude_form;
}

// function to convert into binary form
string binary_converter(int input_number){
    string output_string = "00000000";

    for(int bit = 0; bit<8 ; bit++ ){
        if(input_number == 0)
            break;
        if(input_number%2 != 0)
            output_string[7-bit] = '1';
        input_number /= 2;
    }
    return output_string;
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

int main(void){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //Input Validation
        while(!is_input_valid(user_input) || !is_range_valid(user_input)){
            cout << "\nInvalid input, please try again with a valid one:\n";
            take_input(&user_input);
        }

        int input_num = stoi(user_input); //Converting the Valid input string to integer
        cout <<"Binary representation of " << input_num << " is ";

        if(input_num >= 0)
            cout << binary_converter(input_num) << ".\n\n";
        else{
            string magnitude_form = binary_converter(input_num*(-1));
            cout  << compute_2s_complement(magnitude_form) << ".\n\n";
        }

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n"; //
}
