//This program takes a string as a input from the user
//And prints which characters occur for max times

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes the user input
string take_input(){
    string user_input;
    cout << "Enter a String: ";
    cin >> user_input;
    return user_input;
}

//Computes string length
int string_length(string user_input){
    int length;
    for(length = 0; user_input[length] != '\0';  length++);
    return length;
}

//Counts the frequency of occurence of every character in the string
void count_frequency(int *arr, string user_input, int len){
    int temp_ascii_code;
    for(int index = 0; index < len ; index++){
        temp_ascii_code = user_input[index]; //Converting to ASCII CODE
        *(arr + temp_ascii_code) += 1;
    }
}

//Looks for the multiple characters having same max frequency
void look_for_multiple_max_frequency(int *counting_array, int max_no){
    for(int i = 0; i<200 ; i++){
        if(*(counting_array + i) ==  max_no){
            cout << char(i) << ", ";
        }
    }
}

//Fetches the max frequency
int fetch_max_frequency(int *counting_array, int *max_no){
    int previous_max;
    int index = 0;
    for(int i = 0; i<200 ; i++){
        *max_no = max(*max_no, *(counting_array + i));
        if(previous_max < *max_no){
            index = i;
        }
        previous_max = *max_no;
    }
    return index;
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
        system("cls");//Clears the console window after every successful run
        cout << "\n\n\t\t :: MAXIMUN OCCURENCE :: \n\n";
        string user_input = take_input();

        int user_input_length = string_length(user_input);

        // counting the frequency of characters of the string
        int counting_array[200] = {0};
        count_frequency(counting_array, user_input, user_input_length);

        // finding the max frequency
        int max_no = counting_array[0];
        int index = fetch_max_frequency(counting_array, &max_no);

        cout << endl << "The character that occurs maximum time is: ";
        look_for_multiple_max_frequency(counting_array, max_no);
        cout << " which occurs for " << max_no << " times.\n";

    }while(want_to_run_again() == true);
    return 0;
}
