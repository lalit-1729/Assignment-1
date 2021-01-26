// Following the international system of numeration
// not applicable for 0

#include <iostream>
#include <stdlib.h>
using namespace std;

//array containing all the required words
string words_array[28] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven",
     "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety"};


//prints for the and units place whenever required
void tens_and_units(int number){
    if(number == 0){
        return;
    }
    //for number less then 20, words are directly taken from the words_array
    else if(number <= 20 && number > 0){
        cout << words_array[number];
    }
    //for number greater than 20, some manipulation has to be done
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

//prints hundredth part of the number, whenever required
int hundreds(int number){
    if(number/100 == 0){
        return number%100;
    }
    else{
    cout << words_array[number/100] + " hundred ";
    return number%100;
    }
}

// prints the thousandth part
int thousands(int number){
    int thous = 10e2;

    if(number/thous == 0){
        return number%thous;
    }

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

// prints the millionth part
int millions(int number){
    int one_million = 10e5;

    if(number/one_million == 0){
        return number%one_million;
    }
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

//takes the input from the user
void take_input(string *user_input){
    cout << "Enter a number that is to be written in words (less than one billion): " << endl;
    cin >> *user_input;
}


//validates only non-negative integer
bool is_number_valid(string user_input){
    int i = 0;
    while(user_input[i] != '\0'){
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
        i++;
    }
    return true;
}

//asks user to rerun the program and returns a bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> continue_program;

    //input validation, validates only lowercase 'y' & 'n'
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        cout << "\n\nYOU JUST QUIT THE PROGRAM...!!!\n\n";
        return false;
    }
}


int main(){
    do{
        system("cls");//clears the screen after every successful run
        cout << "\n\n\t\t :: Numeric to words conversion :: \n";
        cout << "\t\t  :: Valid Range 1 to 1 billion ::\n\n"; //excluding the 1 billion

        string user_input;
        take_input(&user_input);

        //input validation
        while(is_number_valid(user_input) == false){
            cout << "\nInvalid input, please try again with a valid one, \n";
            take_input(&user_input);
        }

        int number = stoi(user_input); // converting a valid string to integer

        cout << "\nThe number in words is:" << endl;
        int function_returned_value = millions(number) ; // follow the chronology
        function_returned_value = thousands(function_returned_value);
        function_returned_value = hundreds(function_returned_value);
        tens_and_units(function_returned_value);

    }while(want_to_run_again() == true);

    return 0;
}
