//program reads the text from the .txt file and also gives the number of the lines in the .txt files

#include <iostream>
#include <stdlib.h>
using namespace std;

// no of lines function
int no_of_lines(string funciton_string){
    int index = 0;
    int no_of_lines = 0;
    while(funciton_string[index] != '\0'){
        if(funciton_string[index] == '\n'){
            no_of_lines++;
        }

        index++;
    }

    return no_of_lines+1; // adding one for the last line
}


int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");
        FILE *file;
        char filename[50];
        cout << "Enter the name of the file: " << endl;
        cin >> filename;
        file = fopen(filename, "r");
        char c = fgetc(file); // getting the first character

        string file_text;
        while(c != EOF){ // checking for the end of the file, EOF == End of file
            file_text += c;
            c = fgetc(file); // getting the next character each time
        }

        char display_text;
        cout << "Want to display the text...??? (y/n)\n";
        cin >> display_text;
        if(display_text == 'y'){
            cout << "The text of file is: \n";
            cout << file_text;
        }

        cout << "\n\n\nNumber of new lines in the file provided are: " << no_of_lines(file_text);

        //asking to run again
        cout << endl << endl <<"\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
