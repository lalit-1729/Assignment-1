#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        string input_string;
        cout << "Enter a string: ";
        cin >> input_string;

        //counting the input string length
        int input_string_size = 0;
        int index = 0;
        while(input_string[index] != '\0'){
            input_string_size++;
            index++;
        }

        //implementing the logic
        int flag = 0;
        for(index = 0; index<input_string_size/2 ; index++){
            if(input_string[index] != input_string[input_string_size - 1 - index]){
                flag = 1;
                break;
            }
        }


        if(flag){
            cout << endl << "It is not a palindrome"<< endl;
        }
        else{
            cout << endl << "It is a Palindrome"<< endl;
        }

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
