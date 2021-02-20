//This program takes a string as a input from the user
//No input validation is Required
//And prints which characters occur for max times

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: MAXIMUM OCCURRENCE IN THE STRING::\n";
    cout << "\t\t\t :: All characters are valid :: \n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

/*This function is declared here to fixed the bug in the run-again loop
  As two strings can't be simply compared by str1 == str2, therefore this function is declared to compare the strings
  , by comparing the length first and then each character of the string.*/
bool compare_strings(string string1, string string2){
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

string take_input(){
    string user_input;
    cout << "Enter a String: ";
    cin >> user_input;
    return user_input;
}

//Counts the frequency of occurrence of each and
//very character in the string, it is done as follows
//Each character's frequency is stored at the ASCII code index
//of the counting array
void count_frequency(int *arr, string user_input){
    int user_input_length = string_length(user_input);
    int temp_ascii_code;

    for(int index = 0; index < user_input_length ; index++){
        temp_ascii_code = user_input[index]; //Converting to ASCII CODE
        arr[temp_ascii_code] += 1;
    }
}

//Fetches the max frequency, from from the counting array
int fetch_max_frequency(int *counting_array, int *max_frequency){
    int previous_max;
    int index = 0;
    for(int i = 0; i<200 ; i++){
        *max_frequency = max(*max_frequency, counting_array[i]);
        if(previous_max < *max_frequency)
            index = i;
        previous_max = *max_frequency;
    }
    return index;
}

//This function is useful when there are multiple characters
//Having the maximum frequency
void look_for_multiple_max_frequency(int *counting_array, int max_frequency){
    for(int i = 0; i<200 ; i++){
        if(*(counting_array + i) ==  max_frequency)
            cout << char(i) << ", ";
    }
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
        string user_input = take_input();

        int counting_array[200] = {0}; //All frequencies are initialized as 0
        count_frequency(counting_array, user_input); //And here are they modified according to the string

        // finding the max frequency
        int max_frequency = counting_array[0];
        int index = fetch_max_frequency(counting_array, &max_frequency);

        cout << endl << "The character that occurs maximum time is: ";
        look_for_multiple_max_frequency(counting_array, max_frequency);
        cout << " which occurs for " << max_frequency << " times.\n";

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
