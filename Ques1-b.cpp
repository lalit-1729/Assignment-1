#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");
        // having input from the user
        int input_num;
        cout << "Enter the number of rows of the pattern: "<< endl;
        cin >> input_num;

        // implementing the logic
        for(int row = 0; row <= input_num ; row++){

            for(int space = 0; space < input_num-row ; space++ ){
                cout << " ";
            }
            for(int j = 0; j < rpw ; j++){
                cout << "$ ";
            }

            cout << endl;
        }

        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
