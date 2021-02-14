//This program takes the input from the user
//Validates the input
//And by following the international system of numeration
//Prints the words of the number entered

#include <iostream>
#include <stdlib.h>
using namespace std;

//array of strings containing all the required words
string words_array[28] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven",
     "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety"};


void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Numeric to words conversion :: \n";
    cout << "\t\t :: Following the international system of numeration :: \n";
    cout << "\t\t :: Valid Range -1 billion to 1 billion, excluding the +1 & -1 billion ::\n\n";
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

string take_input(){
    string user_input;
    cout << "Enter a number that is to be written in words: " << endl;
    cin >> user_input;
    return user_input;
}

bool is_number_valid(string user_input){
    int i = 0;
    if(user_input[0] == '-')  //For negative number
        i++;

    for(i ;user_input[i] != '\0'; i++){
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}

void tens_and_units(int number){
    if(number == 0)
        return;

    //for number less then 20, words are directly fetched from the words_array
    else if(number <= 20 && number > 0)
        cout << words_array[number];

    //for number greater than 20, some manipulation is being done
    else{
        int unit = number%10;

        if(unit != 0){
            int ten = number - unit;
            cout << words_array[18+ten/10] + " " + words_array[unit];
        }
        else{
            int ten = number;
            cout << words_array[18+ten/10];
        }
    }
}

//This function uses the above declared function
//to print the hundredth part of the number if present
//and returns the remaining portion to be printed
int hundreds(int number){
    if(number/100 == 0)
        return number%100;

    else{
    cout << words_array[number/100] + " hundred ";
    return number%100;
    }
}

//This function uses the above declared function
//to print the thousandth part of the number if present
//and returns the remaining portion to be printed
int thousands(int number){
    int thous = 10e2;

    if(number/thous == 0)
        return number%thous;

    else if((number/thous)<=20 && (number/thous) > 0){
        cout << words_array[number/thous] + " thousand ";
        return number%thous;
    }

    else if(number/thous<99 && number/thous>20){
        tens_and_units(number/thous);
        cout << " thousand ";
        return number%thous;
    }

    else if(number/thous > 100 && number/thous < thous){
        int var = hundreds(number/thous);
        tens_and_units(var);
        cout << " thousand ";
        return number%thous;
    }
}

//This function uses the above declared function
//to print the millionth part of the number if present
//and returns the remaining portion to be printed
int millions(int number){
    int one_million = 10e5;

    if(number/one_million == 0)
        return number%one_million;

    else if((number/one_million)<=20 && (number/one_million)>0){
        cout << words_array[number/one_million] + " million ";
        return number%one_million;
    }
    else if(number/one_million<99 && number/one_million>20){
        tens_and_units(number/one_million);
        cout << " million ";
        return number%one_million;
    }
    else{
        int hundred = hundreds(number/one_million);
        tens_and_units(hundred);
        cout << " million ";
        return number%one_million;
    }
}

//This function asks user to rerun the program
//And only treats y,Y,n,N as a valid input
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


//Main Method
int main(){
    string continue_program;

    do{
        refresh_screen();
        string user_input = take_input();

        //input validation
        while(!is_number_valid(user_input)){
            cout << "\nInvalid input, please try again with a valid one, \n";
            user_input = take_input();
        }

        int number = stoi(user_input); // converting a valid string to integer
        cout << "\nThe number in words is:" << endl;

        if(number == 0)
            cout << words_array[0];
        else if(number < 0){
            cout << "minus ";
            number *= -1;
        }

        int function_returned_value = millions(number) ; // follow the chronology
        function_returned_value = thousands(function_returned_value);
        function_returned_value = hundreds(function_returned_value);
        tens_and_units(function_returned_value);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
