//This program checks whether the provide number is a Armstrong number or not

#include <iostream>
#include <stdlib.h>
using namespace std;

//defining the power function
int power(int base, int exponent){

    if(exponent == 0){
        return 1;
    }
    else{
        return base*power(base, exponent-1);
    }
}

//takes the input from user
void take_input(string *user_input){
    cout << "Enter a number: ";
    cin >> *user_input;
}

//validates only non-negative integer
bool is_number_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//counts the no of digits
int count_digits(int number){
    int no_of_digits = 0;
    while(number != 0){
            no_of_digits++;
            number /= 10;
    }
    return no_of_digits;
}

//sums the digits of the input number with the power as no. of digits of input number
int sum_for_armstrong_number(int number, int no_of_digits){
    int sum = 0;
    for(int i = 0; i<no_of_digits; i++){
        int digit = number%10;
        sum += power(digit, no_of_digits);
        number /= 10;
    }
    return sum;
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

//checks for amrstrong number and displays the result
void check_for_armstrong_number(int sum, int number){
    if(sum == number){
        cout << "The given number is a Armstrong Number\n";
    }
    else{
        cout << "The given number is not a Armstrong Number\n";
    }
    return;
}


int main(){
    do{
        system("cls");//clears the console after every successful run
        cout << "\n\n\t\t :: Armstrong Number ::\n\n";
        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_number_valid(user_input)){
            cout << "Invalid input, please try with a valid one: ";
            take_input(&user_input);
        }

        int valid_input_number = stoi(user_input); // converting a valid string to integer
        int no_of_digits = count_digits(valid_input_number);
        int sum = sum_for_armstrong_number(valid_input_number, no_of_digits);

        check_for_armstrong_number(sum, valid_input_number);//results
    }while(want_to_run_again() == true);

    return 0;
}
