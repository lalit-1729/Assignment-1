#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    // run again loop
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int input_num;
        cout << "Enter the no. of rows of the pattern: ";
        cin >> input_num;


        for(int row = 0; row < input_num ; row++){

            for(int space = 1; space < input_num-row ; space++ ){
                cout << " ";
            }
            for(int character = 0; character < (2*row + 1) ; character++){
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
