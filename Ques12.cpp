#include <iostream>
#include <stdlib.h>
using namespace std;

// factorial funtion
int factorial(int num){

    int factor = num;
    if(num != 1 && num != 0){
        return factor*factorial(num-1);
    }
    else if( num == 0){
        return 1;
    }
    else{
        return 1;
    }
}

// nCr function
int nCr(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");
        int rows;
        cout << "Enter the number of rows: ";
        cin >> rows;

        for(int i = 0; i < rows ; i++){
            for(int j = 1; j < rows-i ; j++ ){
                    cout << " ";
                }
            //cout << "1" << endl;
            for(int j = 0; j<=i;j++){
                printf("%d ", nCr(i, j) );
            }
            cout << endl;
        }

        // asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
