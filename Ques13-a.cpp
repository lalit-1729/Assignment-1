#include <iostream>
#include <stdlib.h>
using namespace std;

//factorial function with recurrsion
int factorial_of(long long int number){
    if(number != 1){
        return number*factorial_of(number-1);
    }
    else{
        return 1;
    }
}

int main(){
    char run_again = 'y';

    while(run_again == 'y'){
        system("cls");

        int input_number;
        cout << "Enter a number: ";
        cin >> input_number;

        cout << "Factorial is " << factorial_of(input_number) << endl;

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
