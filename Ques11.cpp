// this implementation is just using the same concept from the previous question
//It takes the input from the user, a string of alphabets both lowercase and uppercase
//Validates the input
//And performs the Quick sort on the provided string

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: QUICK SORT OVER ALPHABETIC STRING :: \n";
    cout << "\t\t:: Both lowercase & uppercase are valid :: \n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

/*This function is declared here to fixed the bug in the run-again loop.
  As two strings can't be simple compared by str1 == str2, therefore this function is declared to compare the strings*/
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


void take_input(string *user_input){
    cout << "\nEnter a string of alphabets only:\n";
    cin >> *user_input;
}

//Validates only alphabetic string
bool is_input_valid(string user_input){
    for(int i = 0;user_input[i] != '\0'; i++){ // running the loop till the terminating value
        //using the ASCII table to verify, ACSII code for 'a'= 97 , 'z'= 122, 'A' = 65 & 'Z' = 91
        if( !( (user_input[i] >= 97 && user_input[i] <= 122) || (user_input[i] >= 65 && user_input[i] <= 91) ) ){
            return false;
        }
    }
    return true;
}

/*this function will check if the character is of uppercase of or not,
  it is done by verifying the ASCII code of the character*/
bool is_character_uppercase(char character){
    if(character >= 65 && character <= 91)
        return true;
    else
        return false;
}

/*Since there is a gap of 32 between the uppercase and lowercase ACSII code of any alphabet character,
  will we return a temporary new type of ASCII code for upper case, such that it that the new type of ASCII code for the uppercase and
  lower case are alternate to each other, following the alphabetic sequence like A, a, B, b, C, c, D, d, .... , Z, z.*/
float return_modified_ascii_code(char character){
    if(is_character_uppercase(character))
        /*if the the character is of uppercase we will add 31.5 to it's ASCII code to generate new type of ASCII code
          such that it comes between its previous lowercase and next lowercase character*/
        return (float)(character + 31.5);
    //No modification required for lowercase characters
    else
        return (float)(character);

}

/*Partition function performs very essential part of Quick sort Technique
  It rearranges the elements in such a way,
  one side of pivot point contain elements smaller than pivot point and
  other contains the elements greater than pivot point, following
  the new ASCII code created*/
int partition(char *function_string, int lower_bound, int upper_bound){
    //Note: The comparison will we done on the basis of the modified ASCII code
    int start = lower_bound, end = upper_bound;
    float pivot = return_modified_ascii_code(function_string[lower_bound]);             //Pivot will store the modified ASCII code for the first element

    while(start <  end){

        float modified_ascii_code = return_modified_ascii_code(function_string[start]);
        while(modified_ascii_code <= pivot){
            start++;
            modified_ascii_code = return_modified_ascii_code(function_string[start]);   //Updating the modified ASCII code for the next element
        }

        modified_ascii_code = return_modified_ascii_code(function_string[end]);
        while(modified_ascii_code > pivot){
            end--;
            modified_ascii_code = return_modified_ascii_code(function_string[end]);     //Updating the modified ASCII code for the next element
        }

        // swapping the terms
        if(start < end){
            char temp = function_string[start];
            function_string[start] = function_string[end];
            function_string[end] = temp;
        }
    }

    // swapping the terms
    if(start > end){
        char temp = function_string[lower_bound];
        function_string[lower_bound] = function_string[end];
        function_string[end] = temp;
    }
    return end;
}

/*The Quick Sort function uses the above Partition function
  And using recursion performs partition till the whole array is sorted*/
string quick_sort(char *function_string, int lower_bound, int upper_bound){
    int location;
    if(lower_bound < upper_bound){
        location = partition(function_string, lower_bound, upper_bound);

        quick_sort(function_string, lower_bound, location-1);
        quick_sort(function_string, location+1, upper_bound);
    }
    return function_string;
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


//Main method
int main(){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //Input Validation
        while(!is_input_valid(user_input)){
            cout << "Invalid Input, please try again with a valid one:\n";
            take_input(&user_input);
        }

        int string_size = string_length(user_input);
        user_input = quick_sort(&user_input[0], 0, string_size-1);
        cout << "\nSorted string in alphabetical order is: \n" << "==> " << user_input;

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
