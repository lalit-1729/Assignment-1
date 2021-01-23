#include <iostream>
#include <stdlib.h>
using namespace std;

// to take the user input
void take_input(int *no_of_rows){
    cout << "Enter the no. of rows of the pattern: ";
    cin >> *no_of_rows;
    cout << endl;
    return;
}


// function to print the pattern
void print_pattern(int no_of_rows){
    for(int row = 0; row < no_of_rows ; row++){
        for(int space = 1; space < no_of_rows - row ; space++ ){
            cout << " ";
        }
        for(int character = 0; character < (2*row + 1) ; character++){
            cout << "$";
        }
        cout << endl;
    }
    return;
}

int main(){
    // run again loop
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int input_num;

        take_input(&input_num);
        print_pattern(input_num);

        //asking to run again
        cout << "\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
