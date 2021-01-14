#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    // run again loop
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");
        //taking input from the user
        cout << "Enter the number of rows of patterns: "<< endl;
        int input_num;
        cin >> input_num;
        cout << endl;

        //implementing the logic
        for(int row = 0; row<input_num ; row++){

            for(int character = 0; character<=row ; character++){
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
