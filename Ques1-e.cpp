#include <iostream>
#include <stdlib.h>
using namespace std;

// to take the input from the user
void take_input(int *n){
    cout << "Enter a Number: ";
    cin >> *n;
    return ;
}


// function to print the fibonacci pattern
void print_fibonacci_pattern(int no_of_terms){
    long long int next_term = 0, previous_term = 1, swapping_term = 0;

    //implementing the logic
    for(int term = 0;  ; term++){

        if(next_term > no_of_terms){
            break;
        }

        cout << next_term << ' ';
        previous_term +=  swapping_term;
        swapping_term = next_term;
        next_term = previous_term;

    }
    return;
}

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        // having the input
        int n;

        take_input(&n);
        print_fibonacci_pattern(n);

        //asking to run again
        cout << endl << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
