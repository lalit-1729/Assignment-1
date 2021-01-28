//This program takes an array as a input
//Validates each entry
//And arranges all the zeros to the start of the array

#include <iostream>
#include <stdlib.h>
using namespace std;

void take_input(string *user_input){
    cout << "Enter the length of the Array: ";
    cin >> *user_input;
}

//Validates only the positive values
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){ // running the loop till the terminating value
        //using the ASCII table to verify, ACSII code for '0'=48 and '9'=57
        if(user_input[i] < 49 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Validates every integer
bool is_array_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){ // running the loop till the terminating value
        //using the ASCII table to verify, ACSII code for '0'=48 and '9'=57
        if(user_input[i] < 48 || user_input[i] > 57){
            if(user_input[i] == '-'){
                i++;
                continue;
            }
            return false;
        }
    }
    return true;
}

//Takes the array input from the user
void take_array_input(int *arr, int array_size){
    cout << "\n\nEnter the array elements, press ENTER after every element: \n";

    for(int i = 0;i<array_size ; i++){
        string user_input;
        cout << "arr[" << i << "] = ";
        cin >> user_input;

        //input validation
        while(is_array_input_valid(user_input) == false){
            cout << "Invalid Input, please enter a valid one: arr[" << i << "] = ";
            cin >> user_input;
        }
        *(arr+i) = stoi(user_input);//converting the valid input string to integer
    }
}

//brings all zeros to the start of the array
void bring_zeros_to_start(int *arr, int array_length){
    int zero_count = 0;
    for(int i = 0; i<array_length ; i++){
        if(*(arr + i) == 0){
            for(int j = i ; j > zero_count; j--){
                *(arr + j) = *(arr + j - 1);
            }
            *(arr + zero_count) = 0;
            zero_count++;
        }
        else{
            continue;
        }
    }
}

//Prints the array
void print_array(int *arr, int array_size){
    for(int i = 0; i<array_size ; i++){
        cout << *(arr+i)<< " ";
    }
    cout << endl;
}

//Asks user to run again & returns bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes) / (n for no)" << endl;
    cin >> continue_program;

    //input validation
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, please enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        cout << "\n\n\nYOU JUST QUIT THE PROGRAM....!!!!\n\n";
        return false;
    }
}


int main(){
    do{
        system("cls");//clears the screen after a successful run
        cout << "\n\n\t\t :: Accumulating all Zero To Start :: \n\n\n";
        string user_input;
        take_input(&user_input);

        //input Validation
        while(is_input_valid(user_input) == false){
            cout << "Invalid input, Please try again with a valid one:\n";
            take_input(&user_input);
        }

        int array_length = stoi(user_input);
        int user_input_array[array_length];

        take_array_input(user_input_array, array_length);
        cout << "\nThe User Entered Array is: \n";
        print_array(user_input_array, array_length);

        bring_zeros_to_start(user_input_array, array_length);
        cout << "\nThe Rearranged Array is: \n";
        print_array(user_input_array, array_length);

    }while(want_to_run_again() == true);

    return 0;
}
