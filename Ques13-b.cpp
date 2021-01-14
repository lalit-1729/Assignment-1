#include <iostream>
#include <stdlib.h>
using namespace std;

// factorial function
int factorial_of(int number){
    int factorial = 1;
    for(int i = 2; i<=number; i++){
        factorial *= i;
    }
    return factorial;
}

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        cout << "Enter a number to calculate Factorial: ";
        int input_number;
        cin >> input_number;
        cout << endl << "Factorial of " << input_number << " is " << factorial_of(input_number) << endl;

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
