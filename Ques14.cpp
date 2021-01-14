#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        // having the input
        cout << "Enter a Number: ";
        int n; // according to the question variable name is given
        cin >> n;


        long long int previous_term = 0, next_term = 1, swapping_term = 0;

        //implementing the logic
        for(int term = 0; term<n ; term++){

            next_term +=  swapping_term;
            swapping_term = previous_term;
            previous_term = next_term;

            cout << next_term << ' ';
        }
        //asking to run again
        cout << endl << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
