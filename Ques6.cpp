//This program takes an array as a input
//Validates each entry
//And arranges all the zeros to the start of the array

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Accumulating all Zero To Start :: \n";
    cout << "\t\t  :: All real numbers are accepted :: \n\n";
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

void take_input(string *user_input){
    cout << "Enter the length of the Array: ";
    cin >> *user_input;
}

bool is_input_valid(string user_input){ //Only positive number are Valid
    for(int i = 0; user_input[i] != '\0' ; i++){
        //using the ASCII table to verify, ACSII code for '0'=48 and '9'=57
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

bool is_array_input_valid(string user_input){
    int dot_count, i = 0;
    if(user_input[0] == '-')  //For negative number
        i++;

    for(i ; user_input[i] != '\0' ; i++){ // running the loop till the terminating Character
        //using the ASCII table to verify, ACSII code for '0'=48 and '9'=57
        if(user_input[i] < 48 || user_input[i] > 57){
            if(user_input[i] == '.'){ // For fractional number
                dot_count++;
                if(dot_count > 1)
                    return false;
                else
                    continue;
            }
            return false;
        }
    }
    return true;
}

void take_array_input(float *arr, int array_size){
    cout << "\n\nEnter the array elements, press ENTER after every element: \n";
    string user_input;

    for(int i = 0;i<array_size ; i++){
        printf("arr[%d] = ", i);
        cin >> user_input;

        //input validation
        while(!is_array_input_valid(user_input)){
            cout << "Invalid Input, please enter a valid one: arr[" << i << "] = ";
            cin >> user_input;
        }
        arr[i] = stof(user_input);//converting the valid input string to float
    }
}

void bring_zeros_to_start(float *arr, int array_length){
    int zero_count = 0;
    for(int i = 0; i<array_length ; i++){
        //finding the index of the zero
        if(arr[i] == 0){
            //the elements between i and zero_count are rotated once Anti-Clockwise
            for(int j = i ; j > zero_count; j--){
                arr[j] = arr[j - 1];
            }
            arr[zero_count] = 0;
            zero_count++;
        }
        else
            continue;
    }
}

void print_array(float *arr, int array_size){
    for(int i = 0; i<array_size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
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


//Main Method
int main(void){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //input Validation
        while(!is_input_valid(user_input)){
            cout << "Invalid input, Please enter a valid one:\n";
            take_input(&user_input);
        }

        int array_length = stoi(user_input); //Converting a valid input string to integer
        float user_input_array[array_length];

        take_array_input(user_input_array, array_length);
        cout << "\nThe User Entered Array is: \n";
        print_array(user_input_array, array_length);

        bring_zeros_to_start(user_input_array, array_length);
        cout << "\nThe Rearranged Array is: \n";
        print_array(user_input_array, array_length);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
