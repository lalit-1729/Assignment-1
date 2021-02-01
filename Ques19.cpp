//program reads the text from the .txt file or similar files
//gives the number of the lines in the .txt files

#include <iostream>
#include <stdlib.h>
using namespace std;

//Reads the text from the file
string read_text_from_file(FILE *file){
    // getting the first character
    char single_character= fgetc(file);
    string file_text;
    // checking for the end of the file, EOF == End of file
    while(single_character != EOF){
        file_text += single_character;
        single_character = fgetc(file);
    }
    return file_text;
}

//Asks to display the text from the file, and if yes then it displays it
void display_text(string file_text){
    char display_text;
    cout << "would you like to display the text...?? (y for yes) / ( anything else for no)\n";
    cin >> display_text;
    if(display_text == 'y'){
        cout << "The text of file is: \n\n---------------------------------------Start\n";
        cout << file_text;
        cout << "\n---------------------------------------End";
    }
}


//no of lines function
int count_no_of_lines(string funciton_string){
    int no_of_lines = 0;
    for(int i = 0;funciton_string[i] != '\0'; i++){
        if(funciton_string[i] == '\n'){
            no_of_lines++;
        }
    }
    return no_of_lines+1; // adding one for the last line
}

//Asks the user to rerun and returns the bool value accordingly
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
    cout << "\n\t\tYou just Quit the program...!!\n\n";
    return false;
}

int main(){
    do{
        system("cls");//Clears the console window after every successful run
        cout << "\n\n\t\t :: Counting No Of Lines In A File :: \n\n";

        char filename[50];
        cout << "Enter the name of the file: " << endl;
        cin >> filename;

        FILE *file;
        file = fopen(filename, "r");
        if( file == NULL){
            cout << "File not found, please try again:";
        }
        else{
            string file_text = read_text_from_file(file);
            display_text(file_text);
            cout << "\n\n\nNumber of new lines in the file provided are: ";
            cout << count_no_of_lines(file_text);
        }

    }while(want_to_run_again() == true);

    return 0;
}
