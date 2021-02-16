//TIC-TAC-TOE game
//Here, the game is played using a board which has 1-9 marks on it
//conveying the position of the X & O, that is to be marked on the board
//And the winner is declared based on the moves made

#include <iostream>
#include <stdlib.h>
using namespace std;

char board_array[9];
int moves_made[9];

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: TIC-TAC-TOE :: \n\n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

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

void take_input(short int player_number, string *user_input){
    printf("\n\nPlayer %d turn, make your move: ", player_number);
    cin >> *user_input;
}

bool is_input_numeric(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }

    return true;
}

//Here we are checking whether the user input is
//Between 1-9 only
bool is_move_range_valid(int move){
    if(move < 0 || move > 9)
        return false;
    else
        return true;
}

bool is_move_repeated(int move){
    for(int i = 0; i<9 ; i++){
        if(moves_made[i] == move)
            return false;

    }

    return true;
}

//Validates the input using the above three function
void validating_input(string *user_input, int player_number){
    while(!is_input_numeric(*user_input)||
           !is_move_range_valid(stoi(*user_input))||
          !is_move_repeated(stoi(*user_input)) )
        {
        cout << "Invalid move: ";
        take_input(player_number, user_input);
    }
}

//To Check whether a player won or not
//ALl the possible winning combination are taken here
bool check_for_win(){

    if(board_array[0] == board_array[1] && board_array[1] == board_array[2])
        return true;
    else if(board_array[3] == board_array[4] && board_array[4] == board_array[5])
        return true;
    else if(board_array[6] == board_array[7] && board_array[7] == board_array[8])
        return true;
    else if(board_array[0] == board_array[3] && board_array[3] == board_array[6])
        return true;
    else if(board_array[1] == board_array[4] && board_array[4] == board_array[7])
        return true;
    else if(board_array[2] == board_array[5] && board_array[5] == board_array[8])
        return true;
    else if(board_array[0] == board_array[4] && board_array[4] == board_array[8])
        return true;
    else if(board_array[6] == board_array[4] && board_array[4] == board_array[2])
        return true;
    else
        return false;
}

//the following function will refresh all the moves
//and the board for the new game
void refresh_moves_n_board(){
    for(int index = 0; index<9 ; index++){
        board_array[index] = char('1'+index);
        moves_made[index] = -1;
    }
}

void draw_board(char arr[9]){
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\tTIC-TAC-TOE\n\n\n\nPlayer 1 - X & Player 2 - O\n\n\n";
    cout << "     |     |     " << endl;
    printf("  %c  |  %c  |  %c  \n", arr[0], arr[1], arr[2]);
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    printf("  %c  |  %c  |  %c  \n", arr[3], arr[4], arr[5]);
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    printf("  %c  |  %c  |  %c  \n", arr[6], arr[7], arr[8]);
    cout << "     |     |     " << endl;
}

//asks user to rerun the program
void want_to_play_again(string *user_input){
    cout << "\nWould you like to play again? (y for yes)/(n for no)" << endl;
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
        refresh_moves_n_board();

        int num = 8;
        string game_status;
        string user_input;

        do{
            draw_board(board_array);

            // player 1 turn
            if(num%2 == 0){
                take_input(1, &user_input);
                validating_input(&user_input, 1);

                int move = stoi(user_input);//string to integer conversion
                moves_made[num] = move;     //updating the moves made
                board_array[move-1] = 'X';  //updating the board

                if(check_for_win()){
                    game_status = "Player 1 won the game";
                    break;
                }
            }

            // player 2 turn
            else{
                take_input(2, &user_input);
                validating_input(&user_input, 2);

                int move = stoi(user_input);//string to integer conversion
                moves_made[num] = move;     //updating the moves made
                board_array[move - 1] = 'O';//updating the board

                if(check_for_win()){
                    game_status = "Player 2 won the game";
                    break;
                }
            }
        }while(num--);

        draw_board(board_array);
        if(!compare_strings(game_status, "Player 1 won the game") && !compare_strings(game_status, "Player 2 won the game") )
            game_status = "Game Tied";

        cout << "\n\n***************************" << game_status << "***************************\n\n";

        want_to_play_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
