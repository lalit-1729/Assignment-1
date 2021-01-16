// Following the international system of numeration

#include <iostream>
#include <stdlib.h>
using namespace std;

// array of the required words
string words_array[28] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven",
     "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety"};

// tens and units function
void tens_and_units(int number){
    if(number == 0){
        cout << words_array[0];
    }

    else if(number <= 20 && number > 0){
        cout << words_array[number];
    }
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

// hundred function
int hundreds(int number){
    if(number/100 == 0){
        return number%100;
    }
    else{
    cout << words_array[number/100] + " hundred ";
    return number%100;
    }
}

// thousand function
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

// million function
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


int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        // asking user input
        int input_number;
        cout << "Enter a number that is to be written in words (less than one billion): " << endl;
        cin >> input_number;

        cout << "\nThe number in words:" << endl;
        int function_returned_value = millions(input_number) ;
        function_returned_value = thousands(function_returned_value);
        function_returned_value = hundreds(function_returned_value);
        tens_and_units(function_returned_value);

        //asking to run again
        cout << "\n\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
