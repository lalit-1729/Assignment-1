#include <iostream>
#include <stdlib.h>
using namespace std;

//to take the user inout
void take_input(int *no_of_rows){
    cout << "Enter the number of rows of the pattern: "<< endl;
    cin >> *no_of_rows;
    return;
}


// function to print the pattern
void print_pattern(int no_of_rows){
    for(int row = 0; row <= no_of_rows ; row++){
        for(int space = 0; space < no_of_rows - row ; space++ ){
            cout << " ";
        }
        for(int j = 0; j < row ; j++){
            cout << "$ ";
        }
        cout << endl;
    }
}

int main(){

    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");
        // having input from the user
        int input_num;
        take_input(&input_num);
        print_pattern(input_num);

        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
