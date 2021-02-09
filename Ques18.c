//NOTE: the program is case sensitive
//This program takes two input from the user and validates it
//ANd prints whether they are anagram or not

#include <stdio.h>
#include <stdlib.h>

// declaring the string_length function
int string_length(char string1[]);
void take_input(char *user_input, int string_number);
void check_for_anagram(char *string1, char *string2);
int is_string_valid(char *user_input);
void ask_to_run_again(char *continue_program);


//Main method starts here
int main(){
    char continue_program;
    do{
        system("cls");
        printf("\n\n\t\t :: CHECKING FOR ANAGRAM :: \n\n\n");
        char input_string1[100000], input_string2[100000];
        take_input(input_string1, 1);
        //input validation
        while(!is_string_valid(input_string1)){
            if(!is_string_valid(input_string1)){
                printf("Invalid input, please try again with a valid one:\n");
                take_input(input_string1, 1);
            }
        }

        take_input(input_string2, 2);
        //input validation
        while(!is_string_valid(input_string2)){
            if(!is_string_valid(input_string2)){
                printf("Invalid input, please try again with a valid one:\n");
                take_input(input_string2, 2);
            }
        }

        int length_of_string1 = string_length(input_string1);
        int length_of_string2 = string_length(input_string2);
        if(length_of_string1 != length_of_string2){
            printf("Not Anagram.");
            return 0;
        }
        else{
            check_for_anagram(input_string1, input_string2);
        }

        ask_to_run_again(&continue_program);
    }while(continue_program == 'y' || continue_program == 'Y');

    printf("\n\n\t\t YOU JUST QUIT THE PROGRAM....!!\n\n");
    return 0;
}


//Checks and prints the result of the anagrams
void check_for_anagram(char *string1, char *string2){
    int letters_matched = 0;
    int string_size = string_length(string1);

    for(int i= 0; i<string_size; i++){
        for(int j = 0; j< string_size; j++ ){
            if(*(string1 + i) == *(string2 + j)){
                *(string2 + j) = '.';
                letters_matched++;
                break;
            }
        }
    }

    if(letters_matched == string_size){
        printf("\n\nAnagram\n");
    }
    else{
        printf("\n\nNot Anagram\n");
    }
}

//Takes the input from the user
void take_input(char *user_input, int string_number){
    printf("Enter the string%d: ", string_number);
    scanf(" %s", user_input);
}

//Validates the input as alphabetic string only
int is_string_valid(char *user_input){
    int string_size = string_length(user_input);
    for(int i = 0; *(user_input+i) != '\0' ; i++){
        // using the ACSII code for validation, 'a' = 97 & 'z' = 122
        if(*(user_input + i) < 97 || *(user_input + i) > 122){
            return 0;
        }
    }
    return 1;
}

//defining the string length function
int string_length(char string1[]){
    int string_len;
    while(string1[string_len] != '\0'){
        string_len++;
    }
    return string_len;
}

//Asks user to run again and validates the input
void ask_to_run_again(char *continue_program){
    printf("Would you like to run the program again...??? (y for yes) / (n for no)\n");
    scanf(" %c", continue_program);

    //Validating only 'y' & 'n'
    if(!(*continue_program == 'y' || *continue_program == 'n' ||
          *continue_program == 'Y' || *continue_program == 'N')){

        while(!(*continue_program == 'y' || *continue_program == 'n' ||
                 *continue_program == 'Y' || *continue_program == 'N')){
            printf("Invalid ibput please try again with a valid input:\n");
            scanf(" %c", continue_program);
        }
    }
}
