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

/* Similar to that of 'strcmp' function of string.h, here we are comparing every single character of both string
   this function will will used later in the program run-again loop for input validation */
bool compare_strings(string string1, string string2){
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

/*for 8-bit signed representation the range of the number that can be represented is
  -128 to 127 therefore validating this range in the function declared below*/
bool is_range_valid(string user_input){
    if(stoi(user_input) < -128 || stoi(user_input) > 127)
        return false;
    else
        return true;
}


bool is_input_valid(string user_input){
    int i = 0;
    if(user_input[0] == '-') //for the negative integers
        i++;
    for(i; user_input[i] != '\0' ; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

/*this function will compute the 2's complement for the negative number,
  2's complement is a mathematical operation on binary numbers and it is used in
  computing as a method for the representation of the signed number representation,
  here we are doing it by the short trick for 2's complement , i.e. after the appearance of the
  first '1' , say index, from the LSB side & rest all are inverted */
string compute_2s_complement(string magnitude_form){
    int index;
    for(index = 7; magnitude_form[index] != '1' ; index--); //finding the index of the first '1' in the string
    index--;

    //inverting each bit after the first '1' appearance
    for( ; index >= 0 ; index--){
        if(magnitude_form[index] == '0')
            magnitude_form[index] = '1';
        else
            magnitude_form[index] = '0';
    }
    magnitude_form[0] = '1';
    return magnitude_form;
}

/*function for the conversion of a decimal number to binary number,
  double dabble method is used here.
  refer : https://circuitglobe.com/decimal-to-binary-conversion-methods.html for more details*/
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

        /*if the number is positive then no 2's complement is required as its magnitude form
          and signed form are same*/
        if(input_num >= 0)
            cout << binary_converter(input_num) << ".\n\n";
        /*but i case of the negative number 2's complement is required fro signed representation*/
        else{
            string magnitude_form = binary_converter(input_num*(-1));
            cout  << compute_2s_complement(magnitude_form) << ".\n\n";
        }

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n"; //
}
