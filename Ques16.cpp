//This program takes the input from the user
//Validates it and checks whether the input is
// Armstrong number or not

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Armstrong Number ::\n\n";
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

/*using the recursion to compute the power,
  the function will return base^exponent.*/
int power(int base, int exponent){

    if(exponent == 0)
        //Returning 1 and stopping the recursion
        return 1;
    else
        //Calling the function again
        return base*power(base, exponent-1);
}

void take_input(string *user_input){
    cout << "Enter a number: ";
    cin >> *user_input;
}

bool is_number_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

int count_no_of_digits(int number){
    int no_of_digits;
    //Reducing the number of lines for the code using
    //for loop in which two condition are given at a time
    for(no_of_digits = 0; number != 0;no_of_digits++, number /= 10);
    return no_of_digits;
}

//Sum for n-digits Armstrong number is evaluated as the
//sum of each digit with the power of n
int sum_for_armstrong_number(int number){
    int no_of_digits = count_no_of_digits(number);
    int sum = 0;
    for(int i = 0; i<no_of_digits; i++){
        int digit = number%10; //Separating the digits from the units place
        sum += power(digit, no_of_digits);
        number /= 10;          //Removing the separated digit from the number
    }
    return sum;
}

//A number is a Armstrong number if the above
//evaluated sum is equal to the number itself
void check_for_armstrong_number(int sum, int number){
    if(sum == number)
        cout << "The number is a Armstrong Number\n";
    else
        cout << "The number is NOT a Armstrong Number\n";
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


//Main Method
int main(){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_number_valid(user_input)){
            cout << "Invalid input, please try with a valid one: ";
            take_input(&user_input);
        }

        int valid_input_number = stoi(user_input); // converting a valid string to integer
        int sum = sum_for_armstrong_number(valid_input_number);
        check_for_armstrong_number(sum, valid_input_number);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
