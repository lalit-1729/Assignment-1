// LAST QUESTION UPLOADED

// TO CALCUALTE THE SQUARE ROOT
// WAS ABLE TO DO WITHOUT ANY ONLINE REFRENCE

#include <iostream>
#include <stdlib.h>
using namespace std;


int func(int num1, int num2){ // was unable to think a better name
    int output;
    int i = 0;
    do{
        output = num1*10+i;
        i++;
    }while((num1*10+i)*i <= num2);

    return output;
}


// power function
float power(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else{
        return base*power(base, exponent-1);
    }
}


// square root function
float square_root(int number, int preciseness){

    int ndigits = 0;
    int temp_number = number;
    while(temp_number!=0){ // counting the no of digits
        temp_number/=10;
        ndigits++;
    }
    temp_number = number;
    int pairs = (ndigits-1)/2; // counting the number of pairs of two digit and subtracting 1 from it
    int pairs_array[pairs];
    for(int i = 0; i<=pairs; i++){ // creating an array of pairs
        pairs_array[i] = temp_number%100;
        temp_number/=100;
    }

    float quotient;
    for(int i = 0; i<=10 ; i++){
        if(i*i > pairs_array[pairs]){
            break;
        }
        quotient = i;
    }

    int remainder = pairs_array[pairs] - quotient*quotient;

    int m, n;
    for(int i = pairs-1; i>=0; i--){ // computing the non-fractional part
        m = func(2*quotient, remainder*100 + pairs_array[i]);
        n = m%10;
        if(n == 0){
            m = 0;
        }
        remainder = remainder*100 + pairs_array[i] - (20*quotient + n)*n;
        quotient = quotient*10 + n;
    }

    int zeros_array[preciseness] = {0};
    for(int i = preciseness-1; i>=0; i--){ // computing the fractional part but not as a fractional part
        m = func(2*quotient, remainder*100 + zeros_array[i]);
        n = m%10;
        if(n == 0){
            m = 0;
        }
        remainder = remainder*100 + zeros_array[i] - (20*quotient + n)*n;
        quotient = quotient*10 + n;
    }

    return quotient/power(10, preciseness); // returning the square root but with a fractional part
}

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        unsigned int input_number;
        cout << "Enter a number to find it's square root: \n";
        cin >> input_number;
        cout << "The square root of the " << input_number << " is: "<< endl;
        float sq_root = square_root(input_number, 4); // can change the preciseness here
        cout <<  sq_root << endl;

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
