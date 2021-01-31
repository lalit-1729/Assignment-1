//This program takes the input from the user
//Verifies the input
//And converts the decimal input to binary form

#include <iostream>
#include <stdlib.h>
using namespace std;

// to take user input
void take_input(string *user_input){
    cout <<  "Enter a number between -128 to 127: ";
    cin >> *user_input;
}

bool is_range_valid(string user_input){
    if(stoi(user_input) < -128 || stoi(user_input) > 127){
        return false;
    }
    else{
        return true;
    }

}

//Validates the only non-alphabetic charcaters
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            if(user_input[i] == '-'){
                continue;
            }
            return false;
        }
    }
    return true;
}

//Computes the 2's complement
string compute_twos_complement(string magnitude_form){
    int index = 7;
    //finding the index of the first '1' in the string
    while(magnitude_form[index] != '1'){
        index--;
    }
    index--;

    //inverting each bit after the first '1'
    while(index >= 0 ){
        if(magnitude_form[index] == '0'){
            magnitude_form[index] = '1';
        }
        else{
            magnitude_form[index] = '0';
        }
        index--;
    }
    magnitude_form[0] = '1';
    return magnitude_form;
}

// function to convert into binary form
string binary_converter(int input_number){
    string output_string = "00000000";

    for(int bit = 0; bit<8 ; bit++ ){
        if(input_number == 0){
            break;
        }
        if(input_number%2 != 0){
            output_string[7-bit] = '1';
        }
        input_number /= 2;
    }
    return output_string;
}

//Asks the user to rerun and returns the bool value accordingly
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
        cout << "\n\t\tYou just Quit the program...!!\n\n";
        return false;
    }
}

int main(){
    do{
        system("cls");//Clears the console window after every successful run
        cout << "\n\n\t\t :: Decimal to Binary Converter :: \n\n";

        string user_input;
        take_input(&user_input);

        //Validating the non-alphabetic characters
        while(is_input_valid(user_input) == false || is_range_valid(user_input) == false){
            cout << "\nInvalid input, please try again with a valid one:\n";
            take_input(&user_input);
        }

        int input_num = stoi(user_input);
        cout <<"Binary representation of " << input_num << " is ";

        if(input_num >= 0){
        cout << binary_converter(input_num) << '.' << endl << endl;
        }
        else{
            string magnitude_form = binary_converter(input_num*(-1));
            cout  << compute_twos_complement(magnitude_form);
        }

    }while(want_to_run_again() == true);
    return 0;
}
