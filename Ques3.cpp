//This program takes a string input from the user
//No validation is required here as our only task is to reverse it

#include <iostream>
#include <stdlib.h>
using namespace std;

//Takes the input from the user
void take_input(string *user_input){
    cout << "Enter a string a without space: ";
    cin >> *user_input;
}

//Computes the length of the string
int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

//Reverses the provided string
string reverse_string(string user_input, int string_size){
    string reversed_string = user_input; //having a string of same length to changes it later
    for(int i = 0; i < string_size ; i++){
        reversed_string[string_size - i - 1] = user_input[i];
    }
    return reversed_string;
}

//asks user to rerun the program and returns a bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> continue_program;

    //input validation
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    do{
        system("cls"); //clears the screen after every successful run
        cout << "\n\n\t\t\t :: Reversing A String :: \n";
        cout << "\t    :: You can enter any alphanumeric character ::\n\n";

        string user_input;
        take_input(&user_input);

        int string_size = string_length(user_input);
        string reversed_string = reverse_string(user_input, string_size);

        cout << "Reversed String: " << reversed_string << endl;

    }while(want_to_run_again() == true);
    return 0;
}
