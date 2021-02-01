//This program takes matrix input from the user
//And performs the matrix multiplication

#include <iostream>
#include <stdlib.h>
using namespace std;

//Validates only for positive integers
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 49 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Takes the user input for rows and columns and validates it
void take_rows_n_columns_input(int *rows, int *columns, string matrix_name){
    cout << "Enter the no. of Rows and Columns of the matrix " << matrix_name << " , respectively: " << endl;
    string user_input1, user_input2;
    cin >> user_input1 >> user_input2;

    //input validation
    while(is_input_valid(user_input1) == false || is_input_valid(user_input2) == false ){
        cout << "Invalid input, please try again with a valid one: \n";
        cout << "Enter the no. of Rows and Columns of the matrix " << matrix_name << " , respectively: " << endl;
        cin >> user_input1 >> user_input2;
    }
    *rows = stoi(user_input1);
    *columns = stoi(user_input2);
}

//Take matrix as a input from the user
void take_matrix_input(int *matrix, int product_of_row_n_columns, string matrix_name){
    cout << "\nEnter the elements of the matrix " << matrix_name << " \n";
    for(int i = 0; i<product_of_row_n_columns; i++){
        cin >> *(matrix + i);
    }
}

//Function to multiply matrix
void multiply_matrixes(int *matrix_a, int *matrix_b, int *multiplied_matrix, int nrows_a, int ncols_b, int nrows_b, int ncols_a){
    for(int i = 0; i < nrows_a ; i++){
        for(int j = 0; j < ncols_b; j++){
            int sum = 0;
            for(int k = 0; k < nrows_b; k++){ //here ncols_a can also be used
                //Accessing the elements of the matrix through their address
                sum += *(matrix_a+i*ncols_a + k)*(*(matrix_b + k*ncols_b + j ));
            }
            *(multiplied_matrix + i*ncols_b + j) = sum ;
        }
    }
}

//Print the provided matrix
void print_matrix(int *matrix, int nrows_a, int ncols_b){
    for(int i =0; i < nrows_a ; i++){
        for(int j = 0; j < ncols_b ; j++){
            cout << *(matrix + i*ncols_b + j) << " ";
        }
        cout << endl;
    }
}

//Asks user to run again & takes action accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\nWould you like to run the program again? (y for yes) / (n for no)" << endl;
    cin >> continue_program;

    //input validation
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, please enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        cout << "\n\n\t\t YOU JUST QUIT THE PROGRAM....!!!\n\n";
        return false;
    }
}


int main(){
    do{
        system("cls");
        cout << "\n\n\t\t :: MATRIX MULTIPLICATION :: \n\n\n";

        // matrix rows & columns input
        int ncols_a, nrows_a, ncols_b , nrows_b;
        take_rows_n_columns_input(&nrows_a, &ncols_a, "A");
        take_rows_n_columns_input(&nrows_b, &ncols_b, "B");

        //Verifying the necessary condition for matrix multiplication
        while(ncols_a != nrows_b){
            cout << "\nRows of matrix A & Columns of matrix B are not matching, \nPlease try again with valid input :\n";
            take_rows_n_columns_input(&nrows_a, &ncols_a, "A");
            take_rows_n_columns_input(&nrows_b, &ncols_b, "B");
        }

        //Matrix elements input
        int matrix_a[nrows_a][ncols_a], matrix_b[nrows_b][ncols_b];
        take_matrix_input(&matrix_a[0][0], nrows_a*ncols_a, "A");
        take_matrix_input(&matrix_b[0][0], nrows_b*ncols_b, "B");

        int multiplied_matrix[nrows_a][ncols_b];
        multiply_matrixes(&matrix_a[0][0], &matrix_b[0][0], &multiplied_matrix[0][0], nrows_a, ncols_b,nrows_b, ncols_a);

        cout << "\n\nResultant matrix: \n" << endl;
        print_matrix(&multiplied_matrix[0][0], nrows_a, ncols_b);
    }while(want_to_run_again() == true);
    return 0;
}
