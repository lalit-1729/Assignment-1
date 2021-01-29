//This program takes the user input
//Validates the input
//And Draws the pascal triangle

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes the user input
void take_input(string *user_input){
    cout << "Enter the number of rows: ";
    cin >> *user_input;
}

//Validates only non-negative integer
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

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

//Draws the pascal's triangle
void draw_pascal_triangle(int rows){
    for(int i = 0; i < rows ; i++){
        //printing the spaces
        for(int j = 1; j < rows-i ; j++ ){
                cout << " ";
            }
        for(int j = 0; j<=i;j++){
            printf("%d ", nCr(i, j) );
        }
        cout << endl;
    }
    return;
}

//Asking user to rerun and returning the bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> continue_program;

    //input validation, validates only lowercase 'y' & 'n'
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        cout << "\n\n\t\t\t YOU JUST QUIT THE PROGRAM...!!!\n\n";
        return false;
    }
}


int main(){
    do{
        system("cls");
        cout << "\n\n\t\t :: PASCAL'S TRIANGLE :: \n\n\n";
        string user_input;
        take_input(&user_input);

        //input validation
        while(is_input_valid(user_input) == false){
            cout << "\nInvalid Input, please try again with a valid one:\n";
            take_input(&user_input);
        }
        int rows = stoi(user_input);//string to integer conversion

        draw_pascal_triangle(rows);

    }while(want_to_run_again() == true);

    return 0;
}
