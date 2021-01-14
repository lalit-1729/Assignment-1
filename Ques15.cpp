#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

    char run_again = 'y';

    while(run_again == 'y'){
        system("cls");

        int year;
        cout << "Enter the year: ";
        cin >> year;

        if(year%100 == 0 && year%400 == 0){
            cout << "This is a Leap year." << endl;
            }
        else if( year%4 ==0 && year%100 != 0 ){
            cout << "This is a Leap year." << endl;
        }
        else{
            cout << "This is not a leap year." << endl;
        }

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
