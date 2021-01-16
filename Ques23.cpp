#include <iostream>
#include <stdlib.h>
using namespace std;

char array[9];
int moves_made[9];

// Move range Validator
bool move_range_validator(int MOVE){

    if(MOVE < 0 || MOVE > 9){
        return true;
    }
    else{
        return false;
    }
}

// repeated move vallidator
bool repeated_move_validator(int MOVE){
    for(int i = 0; i<9 ; i++){
        if(moves_made[i] == MOVE){
            return false;
        }
    }

    return true;
}

// To Check whether a player won or not
int check_for_win(){

    if(array[0] == array[1] && array[1] == array[2]){
        return 1;
    }

    else if(array[3] == array[4] && array[4] == array[5]){
        return 1;
    }

    else if(array[6] == array[7] && array[7] == array[8]){
        return 1;
    }

    else if(array[0] == array[3] && array[3] == array[6]){
        return 1;
    }

    else if(array[1] == array[4] && array[4] == array[7]){
        return 1;
    }

    else if(array[2] == array[5] && array[5] == array[8]){
        return 1;
    }

    else if(array[0] == array[4] && array[4] == array[8]){
        return 1;
    }

    else if(array[6] == array[4] && array[4] == array[2]){
        return 1;
    }
    else{
        return 0;
    }
}

//  Drawing the board
void draw_board(char arr[9]){
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


int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        for(int index = 0; index<9 ; index++){
            array[index] = char('1'+index);
            moves_made[index] = -1;
        }
        int num = 8;
        bool flag = true;
        do{
            system("cls");

            draw_board(array);
            int move;

            // player 1 turn
            if(num%2 == 0){
                cout << "\n\nPlayer 1 turn, make your move: " << endl;
                cin >> move;
                while(move_range_validator(move) == false && repeated_move_validator(move) == false){
                    cout << "Invalid Move: ";
                    cin >> move;
                }
                moves_made[num] = move;
                array[move-1] = 'X';
                if(check_for_win()){
                    system("cls");
                    draw_board(array);
                    cout << "\n\n*****************Player 1 won the game*****************\n\n";
                    flag = false;
                    break;
                }
            }

            // player 2 turn
            else{
                cout << "\n\nPlayer 2 turn, make your move: " << endl;
                cin >> move;
                while(move_range_validator(move) == false && repeated_move_validator(move) == false){
                    cout << "Invalid Move: ";
                    cin >> move;
                }
                moves_made[num] = move;
                array[move -1] = 'O';
                if(check_for_win()){
                    system("cls");
                    draw_board(array);
                    cout << "\n\n*****************Player 2 won the game*****************\n\n";
                    flag = false;
                    break;
                }
            }

        }while(num--);

        // if game is tied
        if(flag){
            system("cls");
            draw_board(array);
            cout << "\n\n\nThe Game is Tied\n";

        }

        //asking to run again
        cout << "\n\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
