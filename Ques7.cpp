//This program takes the input form the user
//Validates the input
//And gives the square of the number as output

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes the user input
void take_input(string *user_input){
    cout << "Enter a number to find it's square root: \n";
    cin >> *user_input;
}

//Validates only non-negative integer
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

int return_divisor(int num1, int num2){ // was unable to think a better name
    int output;
    int i = 0;
    do{
        output = num1*10+i;
        i++;
    }while((num1*10+i)*i <= num2);

    return output;
}


// power return_divisortion
double power(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else{
        return base*power(base, exponent-1);
    }
}

//Counts the number of digits
int no_of_digits(int number){
    int ndigits = 0;
    while(number!=0){
        number/=10;
        ndigits++;
    }
    return ndigits;
}

// square root return_divisortion
double square_root(int number, int preciseness){

    int ndigits = no_of_digits(number);

    int temp_number = number;
    int pairs = (ndigits-1)/2; // counting the number of pairs of two digit and subtracting 1 from it
    int pairs_array[pairs];
    for(int i = 0; i<=pairs; i++){ // creating an array of pairs
        pairs_array[i] = temp_number%100;
        temp_number/=100;
    }

    double quotient;

    //Computing the first digit
    for(int i = 0; i<=10 ; i++){
        if(i*i > pairs_array[pairs]){
            break;
        }
        quotient = i;
    }

    int remainder = pairs_array[pairs] - quotient*quotient;

    int divisor, n;
    for(int i = pairs-1; i>=0; i--){ // computing the non-fractional part
        divisor = return_divisor(2*quotient, remainder*100 + pairs_array[i]);
        n = divisor % 10;
        if(n == 0){
            divisor = 0;
        }
        remainder = remainder*100 + pairs_array[i] - (20*quotient + n)*n;
        quotient = quotient*10 + n;
    }

    int zeros_array[preciseness] = {0}; // initializing all elements to 0
    for(int i = preciseness-1; i>=0; i--){ //computing the fractional part but not as a fractional part
        divisor = return_divisor(2*quotient, remainder*100 + zeros_array[i]);
        n = divisor%10;
        if(n == 0){
            divisor = 0;
        }
        remainder = remainder*100 + zeros_array[i] - (20*quotient + n)*n;
        quotient = quotient*10 + n;
    }

    return quotient/power(10, preciseness); // returning the square root but with a fractional part
}

//Asking user to rerun and returning the bool value accordingly
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
        cout << "\n\n\t\t\t YOU JUST QUIT THE PROGRAM...!!!\n\n";
        return false;
    }
}


int main(){
    do{
        system("cls");//clears the screen after every successful run
        cout << "\n\n\t\t :: SQUARE ROOT :: \n\n";

        string user_input;
        take_input(&user_input);

        //input validation
        while(is_input_valid(user_input) == false){
            cout << "\nInvalid Input, please try a valid one:\n";
            take_input(&user_input);
        }
        unsigned int number = stoi(user_input);//string to integer conversion

        double sq_root = square_root(number, 5); //can change the preciseness here, less than equal to 5
        printf("\n\nThe square root of the %d is : %.5f", number, sq_root);

    }while(want_to_run_again() == true);
    return 0;
}
