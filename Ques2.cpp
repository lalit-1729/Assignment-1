#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        string output_string = "00000000";

        int input_num;
        cout <<  "Enter a number less than or equal to 256: ";
        cin >> input_num;

        cout <<"Binary representation of " << input_num << " is ";

        for(int bit = 0; bit<8 ; bit++ ){
            if(input_num == 0){
                break;
            }
            if(input_num%2 != 0){
                output_string[7-bit] = '1';
            }
            input_num /= 2;
        }

        cout << output_string << '.' << endl << endl;

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
