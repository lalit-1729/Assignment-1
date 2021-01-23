#include <iostream>
#include <stdlib.h>
using namespace std;

// to take input from the user
void take_input(int *no_of_rows){
    cout << "Enter a Number: ";
    cin >> *no_of_rows;
    return;
}


//function to print the required pattern
void print_pattern(int no_of_rows){

    // the upper pattern including the largest row
    for(int row = 0; row<no_of_rows ; row++){
        for(int space = 1; space < no_of_rows-row ; space++ ){ // printing the spaces
            cout << " ";
        }
        for(int j = 0; j < (2*row + 1) ; j++){
            cout << "$";
        }
        cout << endl;
    }

    // the lower pattern
    for(int row = 0; row<no_of_rows ; row++){
        for(int space = row; space >= 0  ; space--){ // printing the spaces
            cout << " ";
        }
        for(int j = 1; j < (2*(no_of_rows-row)-1) - 1 ; j++ ){
            cout << "$";
        }
        cout << endl;
    }

    return;
}

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int input_num;
        take_input(&input_num);
        print_pattern(input_num);

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
