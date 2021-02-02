// NOTE: the program is case sensitive

#include <stdio.h>
#include <stdlib.h>

// declaring the string_length function
int string_length(char string1[]);

int main(){
    char run_again = 'y';

    while(run_again == 'y'){
        system("cls");


        char input_string1[100000]; // assuming 100000 as max_length
        char input_string2[100000];
        printf("Enter the string1: ");
        scanf("%s", &input_string1);
        printf("Enter the String2: ");
        scanf("%s", &input_string2);


        // checking the length logic
        int length_of_string1 = string_length(input_string1), length_of_string2 = string_length(input_string2);
        if(length_of_string1 != length_of_string2){
            printf("The strings are not Anagram.");
            return 0;
        }

        // implementing the anagram logic
        else{

            int flag = 0;
            for(int i= 0; i<length_of_string1; i++){
                for(int j = 0; j< length_of_string1; j++ ){
                    if(input_string1[i] == input_string2[j]){
                        input_string2[j] = '.';
                        flag++;
                        break;
                    }
                }
            }

            if(flag == length_of_string1){
                printf("\n\nAnagram\n");
            }
            else{
                printf("\n\nNot Anagram\n");
            }
        }

        printf("Do you wanna run program again....??? (y/n) ");
        scanf(" %c", &run_again);
        printf("\n");
    }

    return 0;
}

//defining the string length function
int string_length(char string1[]){
    int string_len;
    while(string1[string_len] != '\0'){
        string_len++;
    }
    return string_len;
}
