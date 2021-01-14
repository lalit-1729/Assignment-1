#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int marks_array[7] = {-1, -1, -1, -1, -1, -1, -1};
        int index = 0;

        int sum_of_marks = 0;
        while(index<7){
            int flag = 1;
            cout << "Enter the marks of subject: " << index+1 << ": ";
            while(flag){
                cin >> marks_array[index];
                if(marks_array[index] > -1 && marks_array[index] <101){
                    flag = 0;
                }
                else{
                    cout << "Enter the marks of the subject" << index+1 << " again, but correctly:" ;
                }
            }

            sum_of_marks += marks_array[index];
            index++;
        }

        cout << endl << "The average of the marks is: " <<  sum_of_marks/7.0 << endl;
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
