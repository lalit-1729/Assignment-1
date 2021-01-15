#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int array_length;
        cout << "Enter the length of the Array: ";
        cin >> array_length;
        int input_array[array_length];

        //having the array inputs
        cout << "Enter the elements of the array: "<< endl;
        for(int index = 0; index < array_length ; index++){
            cin >> input_array[index];
        }

        int zero_count = 0;
        for(int i = 0; i<array_length ; i++){

            if(input_array[i] == 0){
                for(int j = i ; j > zero_count; j--){
                    input_array[j] = input_array[j-1];
                }
                input_array[zero_count] = 0;
                zero_count++;
            }
            else{
                continue;
            }
        }

        cout << "\n\n\nThe required array is: "<< endl;
        for(int index = 0; index < array_length ; index++){
            cout << input_array[index] << " ";
        }


        //asking to run again
        cout << endl << endl <<"Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
