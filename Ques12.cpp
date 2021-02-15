//This program takes the user input
//Validates the input
//And Draws the pascal triangle

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: PASCAL'S TRIANGLE :: \n";
    cout << "\t\t:: Valid output for 0-12 only ::\n\n"; //Due to four byte limit of the int data type
    //It can be increased by using long long int, but it won't be of use after a certain limit
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

bool compare_strings(string string1, string string2){ //Similar to that of 'strcmp' function of string.h
    if(string_length(string1) != string_length(string2))
        return false;
    else{
        for(int i = 0; i<string_length(string1) ; i++){
            if(string1[i] != string2[i])
                return false;
        }
    }
    return true;
}

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

bool is_input_in_range(string user_input){
    int number = stoi(user_input);
    if(number <= 12)
        return true;
    else
        return false;
}

// factorial simply refers to the no of all the possible arrangements
// of n different objects, mathematically it is given by:
// n! = 1.2.3.......(n-2).(n-1).n
int compute_factorial(int num){
    int factor = num;
    if(num != 1 && num != 0)
        return factor*compute_factorial(num-1);
    else if( num == 0)
        return 1;
    else
        return 1;
}

//Here nCr is a mathematical term that refers to no of combination
//of selecting r different objects from the n different objects
//The formula is given by:
// nCr = n!/((n-r)!r!)
int calculate_nCr(int n, int r){
    return compute_factorial(n)/(compute_factorial(r)*compute_factorial(n-r));
}

//Drawing a pascal triangle is like writing the
//binomial coefficients of the a equation given by
//Binomial theorem given by:
//              n
// (x + a)^n = sum nCr.x^r.a^(n-r)
//             r=1
//Therefore nCr are the coefficients
void draw_pascal_triangle(int rows){
    for(int i = 0; i < rows ; i++){
        for(int j = 1; j < rows-i ; j++ ){ //printing the spaces
                cout << " ";
            }
        for(int j = 0; j<=i;j++){
            printf("%d ", calculate_nCr(i, j) );//Printing the binomial coefficients
        }
        cout << endl;
    }
    return;
}

//asks user to rerun the program
void want_to_run_again(string *user_input){
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> *user_input;

    //input validation, only y, n, Y, N are allowed
    while( !( compare_strings(*user_input, "y") || compare_strings(*user_input, "n") ||
             compare_strings(*user_input, "Y") || compare_strings(*user_input, "N")) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> *user_input;
    }
}


int main(void){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_input_valid(user_input) || !is_input_in_range(user_input)){
            cout << "\nInvalid Input, please try again with a valid one:\n";
            take_input(&user_input);
        }
        int rows = stoi(user_input);//string to integer conversion

        draw_pascal_triangle(rows);
        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
