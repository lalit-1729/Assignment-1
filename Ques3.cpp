#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");
        string input_string;
        cout << "Enter a string a without space: ";
        cin >> input_string;

        // here input_string.size() can also be used
        int string_size = 0;
        while(input_string[string_size] != '\0'){
            string_size++;
        }

        string reversed_string = input_string;
        for(int index = 0; index<string_size ; index++){
            reversed_string[string_size-index-1] = input_string[index];
        }

        cout << "Original String: " << input_string << "   " << "Reversed String: " << reversed_string << endl << endl;

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
