//program reads the text from the .txt file or similar files
//gives the number of the lines in the files
//Or returns error if the files is not found

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Counting No Of Lines In A File :: \n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

//This function is declared here to fixed the bug in the run-again loop
//As two strings can't be simple compared by str1 == str2, therefore this function is declared to compare the strings
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

//This function reads the text from the file
//To do so it reads it by fetching a single letter from the text
//Till the EOF (end of file) and stores it in a string
string read_text_from_file(FILE *file){
    char single_character= fgetc(file);// getting the first character
    string file_text;

    // checking for the end of the file, EOF == End of file
    while(single_character != EOF){
        file_text += single_character;
        single_character = fgetc(file);
    }
    return file_text;
}

void display_text(string file_text){
    string display_file_text;
    cout << "would you like to display the text...?? (y for yes) / ( anything else for no )\n";
    cin >> display_file_text;

    if(compare_strings(display_file_text,"y") || compare_strings(display_file_text, "y")){
        cout << "The text of file is: \n\nStart---------------------------------------\n";
        cout << file_text;
        cout << "\n---------------------------------------End";
    }
}


//This function will count new line using the text of the file,
//this function will go through each character of the text and look for new line character,
//i.e. '\n', if it finds it its gonna increment the no of lines
int count_no_of_lines(string funciton_string){
    int no_of_lines = 0;

    for(int i = 0;funciton_string[i] != '\0'; i++){
        if(funciton_string[i] == '\n')
            no_of_lines++;
    }
    return no_of_lines+1; // adding one for the last line
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

int main(){
    string continue_program;

    do{
        refresh_screen();
        char filename[50];
        cout << "Enter the name of the file: " << endl;
        cin >> filename;

        FILE *file; //File pointer
        file = fopen(filename, "r");

        if( file == NULL ) //If the file is not found or file name is incorrect
            cout << "File not found, please try again:\n\n";
        else{
            string file_text = read_text_from_file(file);
            display_text(file_text);
            cout << "\n\n\nNumber of lines in the file provided are: ";
            cout << count_no_of_lines(file_text);
        }

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
