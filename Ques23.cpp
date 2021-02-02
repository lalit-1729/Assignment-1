//TIC-TAC-TOE game

#include <iostream>
#include <stdlib.h>
using namespace std;

char array[9];
int moves_made[9];

//Takes the input from the user
void take_input(int player_number, string *user_input){
    cout << "\n\nPlayer " << player_number << " turn, make your move: " << endl;
    cin >> *user_input;
}

//Validates the integers only
bool is_input_numeric(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

// Move range Validator
bool is_move_range_valid(int MOVE){

    if(MOVE < 0 || MOVE > 9){
        return false;
    }
    else{
        return true;
    }
}

// repeated move vallidator
bool is_move_repeated(int MOVE){
    for(int i = 0; i<9 ; i++){
        if(moves_made[i] == MOVE){
            return false;
        }
    }

    return true;
}

//Validates the input using the above three function
void input_validator(string *user_input, int player_number){
    while(is_input_numeric(*user_input) == false ||
           is_move_range_valid(stoi(*user_input)) == false ||
           is_move_repeated(stoi(*user_input)) == false )
        {
        cout << "Invalid Move: ";
        take_input(player_number, user_input);
    }
}

// To Check whether a player won or not
bool check_for_win(){

    if(array[0] == array[1] && array[1] == array[2]){
        return true;
    }

    else if(array[3] == array[4] && array[4] == array[5]){
        return true;
    }

    else if(array[6] == array[7] && array[7] == array[8]){
        return true;
    }

    else if(array[0] == array[3] && array[3] == array[6]){
        return true;
    }

    else if(array[1] == array[4] && array[4] == array[7]){
        return true;
    }

    else if(array[2] == array[5] && array[5] == array[8]){
        return true;
    }

    else if(array[0] == array[4] && array[4] == array[8]){
        return true;
    }

    else if(array[6] == array[4] && array[4] == array[2]){
        return true;
    }
    else{
        return false;
    }
}

//for new game equating all moves made to -1
void refresh_moves_n_board(){
    for(int index = 0; index<9 ; index++){
        array[index] = char('1'+index);
        moves_made[index] = -1;
    }
}

//  Drawing the board
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

//asks user to play again and takes action accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to play again? (y for yes)/(n for no)" << endl;
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
        cout << "\n\n\t\t YOU JUST QUIT THE GAME...!!!\n\n";
        return false;
    }
}


int main(){

    do{
        refresh_moves_n_board();

        int num = 8;
        bool is_winner_found = false;
        string user_input;
        do{
            draw_board(array);
            // player 1 turn
            if(num%2 == 0){
                take_input(1, &user_input);
                input_validator(&user_input, 1);

                int move = stoi(user_input);
                moves_made[num] = move;//updating the moves made
                array[move-1] = 'X';//updating the board

                if(check_for_win()){
                    draw_board(array);
                    cout << "\n\n*****************Player 1 won the game*****************\n\n";
                    is_winner_found = true;
                    break;
                }
            }
            // player 2 turn
            else{
                take_input(2, &user_input);
                input_validator(&user_input, 2);

                int move = stoi(user_input);
                moves_made[num] = move;//updating the moves made
                array[move - 1] = 'O';//updating the board

                if(check_for_win()){
                    draw_board(array);
                    cout << "\n\n*****************Player 2 won the game*****************\n\n";
                    is_winner_found = true;
                    break;
                }
            }
        }while(num--);

        if(is_winner_found == false){
            draw_board(array);
            cout << "\n\n\nThe Game is Tied\n";
        }
    }while(want_to_run_again() == true);
    return 0;
}
