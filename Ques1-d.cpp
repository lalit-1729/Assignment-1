#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int input_num;
        cout << "Enter a Number: ";
        cin >> input_num;


        // the upper pattern including the largest row
        for(int row = 0; row<input_num ; row++){

            for(int j = 1; j < input_num-row ; j++ ){
                cout << " ";
            }

            for(int j = 0; j < (2*row + 1) ; j++){
                cout << "$";
            }

            cout << endl;
        }

        // the lower pattern
        for(int row = 0; row<input_num ; row++){

            for(int j = row; j >= 0  ; j--){
                cout << " ";
            }

            for(int j = 1; j < (2*(input_num-row)-1) - 1 ; j++ ){
                cout << "$";
            }

            cout << endl;
        }
        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
