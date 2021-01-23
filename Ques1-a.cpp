#include <iostream>
#include <stdlib.h>

using namespace std;

void take_input(int *no_of_rows){
    cout << "Enter the number of rows of patterns: "<< endl;
    cin >> *no_of_rows;
    cout << endl;
    return;
}


// function to print the pattern
void print_pattern(int no_of_rows){
    for(int row = 0; row<no_of_rows ; row++){
        for(int character = 0; character<=row ; character++){
            cout << "$";
        }
        cout << endl;
    }
}

int main(){
    // run again loop
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");
        //taking input from the user

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
