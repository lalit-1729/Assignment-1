#include <iostream>
#include <stdlib.h>
using namespace std;

// defining the power function
int power(int base, int exponent){

    if(exponent == 0){
        return 1;
    }
    else{
        return base*power(base, exponent-1);
    }
}

int main(){
    char run_again = 'y';

    while(run_again == 'y'){
        system("cls");

        int input_number;
        cout << "Enter a number: ";
        cin >> input_number;

        //counting the number of digits
        int temp_number = input_number, sum = 0, digit, no_of_digits = 0;
        while(temp_number){
            no_of_digits++;
            temp_number /= 10;
        }
        cout << "No. of digits: " << no_of_digits << endl;


        //summing the digits with power of no_of_digits
        temp_number = input_number;
        for(int i = 0; i<no_of_digits; i++){
            digit = temp_number%10;
            //cout << digit << " ";
            sum += power(digit, no_of_digits);
            temp_number /= 10;
        }


        cout << "The some of digits with the power of No. of no_of_digits: " << sum << endl;
        if(sum == input_number){
            cout << "The given number is a Armstrong Number" << endl;
        }
        else{
            cout << "The given number is not a Armstrong Number" << endl;
        }

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
