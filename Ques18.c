//NOTE: the program is case sensitive
//This program takes two input from the user and validates it
//ANd prints whether they are anagram or not

#include <stdio.h>
#include <stdlib.h>

// declaring the compute_string_length function
int compute_string_length(char string1[]);
void take_input(char *user_input, int string_number);
void check_for_anagram(char *string1, char *string2);
int is_string_valid(char *user_input);
void ask_to_run_again(char *continue_program);
void refresh_screen();


//Main method starts here
int main(){
    char continue_program[50];
    do{
        refresh_screen();
        char input_string1[100000], input_string2[100000];
        take_input(input_string1, 1);

        //input validation
        if(!is_string_valid(input_string1)){
            while(!is_string_valid(input_string1)){
                printf("Invalid input, please try again with a valid one:\n");
                take_input(input_string1, 1);
            }
        }

        take_input(input_string2, 2);
        //input validation
        if(!is_string_valid(input_string2)){
            while(!is_string_valid(input_string2)){
                printf("Invalid input, please try again with a valid one:\n");
                take_input(input_string2, 2);
            }
        }

        //It is obvious that if the length of the strings are not same then they can't be anagram
        if(compute_string_length(input_string1) != compute_string_length(input_string2)){
            printf("Not Anagram.\n\n");
        }
        else{
            check_for_anagram(input_string1, input_string2);
        }

        ask_to_run_again(continue_program);
    }while(continue_program[0] == 'y' || continue_program[0] == 'Y');

    printf("\n\n\t\t YOU JUST QUIT THE PROGRAM....!!\n\n");
    return 0;
}


//Checks and prints the result of the anagrams
void check_for_anagram(char *string1, char *string2){
    int letters_matched = 0;
    //Here, we assume that the length of both the strings are same
    int string_size = compute_string_length(string1);

    /*here, each character  of string1 is compared to each elements of the string two,
      and if the match is found the no of letters matched is incremented, and the matched letter
      in the string two is replaced by '.'*/
    for(int i= 0; i<string_size; i++){
        for(int j = 0; j< string_size; j++ ){
            if(*(string1 + i) == *(string2 + j)){
                *(string2 + j) = '.';
                letters_matched++;
                break;
            }
        }
    }

    /*now, here the given two strings will be anagram only if the no of letters matched
      is equal to the no of letters in both the strings.*/
    if(letters_matched == string_size){
        printf("\n\nAnagram\n");
    }
    else{
        printf("\n\nNot Anagram\n");
    }
}


void take_input(char *user_input, int string_number){
    printf("Enter the string%d: ", string_number);
    scanf(" %s", user_input);
}


int is_string_valid(char *user_input){
    int string_size = compute_string_length(user_input);
    for(int i = 0; *(user_input+i) != '\0' ; i++){
        // using the ACSII code for validation, 'a' = 97 & 'z' = 122
        if(*(user_input + i) < 97 || *(user_input + i) > 122){
            return 0;
        }
    }
    return 1;
}

int compute_string_length(char *string1){
    int string_len = 0;
    while(*(string1+string_len) != '\0'){
        string_len++;
    }
    return string_len;
}

//Asks user to run again and validates the input
void ask_to_run_again(char *continue_program){
    printf("Would you like to run the program again...??? (y for yes) / (n for no)\n");
    scanf("%s", continue_program);

    /*Since we are having a single character as a valid input,
      we will validate the input by comparing the length.*/
    int string_size = compute_string_length(continue_program);

    //Validating only 'y' & 'n'
    if(!(*continue_program == 'y' || *continue_program == 'n' ||
          *continue_program == 'Y' || *continue_program == 'N') || string_size != 1){

        while(!(*continue_program == 'y' || *continue_program == 'n' ||
                 *continue_program == 'Y' || *continue_program == 'N') || string_size != 1){
            printf("Invalid ibput please try again with a valid input:\n");
            scanf("%s", continue_program);
            string_size = compute_string_length(continue_program); //Updating the length
        }
    }
}

void refresh_screen(){
    system("cls");
    printf("\n\n\t\t :: CHECKING FOR ANAGRAM :: \n");
    printf("\t   :: Only lowercase string is valid ::\n\n");
}
