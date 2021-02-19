//This program takes matrix input from the user,
//And Validates each and every input entered by the user
//And performs the matrix multiplication

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: MATRIX MULTIPLICATION :: \n";
    cout << "\t :: The matrix elements must be positive ::\n\n";
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


//This function is used to validate only positive integers,
//so that it can be used to take inputs for no of list item, no of extends, no of prepends, etc.
bool is_input_numeric(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//This function will validate all the real numbers,
//so that this function can be used for list item data
bool is_input_real_number(string user_input){
    int i = 0, dot_count = 0;
    if(user_input[i] == '-') //minus sign is valid, in case of negative numbers
        i++;

    for(i; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

int take_only_positive_input(string message){
    string user_input;
    cout << message;
    cin >> user_input;

    //input validation
    while(!is_input_numeric(user_input)){
            cout << "Invalid input, please enter valid one:\n";
            cout << message;
            cin >> user_input;
    }
    return stoi(user_input);
}

float take_matrix_element_input(){
    string user_input;
    cin >> user_input;

    //input validation
    while(!is_input_real_number(user_input)){
            cout << "Invalid input, please enter valid one:\n";
            cin >> user_input;
    }
    return stof(user_input); //String to float conversion
}


//Take matrix as a input from the user
void take_matrix_input(int *matrix, int rows , int columns,char matrix_name){
    int product_of_row_n_columns = rows*columns;
    cout << "\nEnter the elements of the matrix " << matrix_name << " \n";
    /* Since that the C & C++ stores the multidimensional array in row major form,
      that is elements are stored row by row, therefore we are taking input in a linear manner
      till last index which will be the product of the no of rows & no of columns columns*/
    int present_row = 0;
    for(int i = 0; i<product_of_row_n_columns; i++){
        printf("Matrix %c element[%d][%d] : ",matrix_name, present_row,i%columns); //Printing the index of the present row and column
        *(matrix + i) = take_matrix_element_input();

        if((i%columns+1) == columns )
            present_row++;
    }
}

/*this function will multiply two matrices, by following the traditional method of multiplication,
  i.e. every single row of matrix a is multiplied by every single column of matrix B,
  and addition results in one element of the resultant matrix*/
void multiply_matrixes(int *matrix_a, int *matrix_b, int *multiplied_matrix, int nrows_a, int ncols_b, int nrows_b, int ncols_a){
    for(int i = 0; i < nrows_a ; i++){
        for(int j = 0; j < ncols_b; j++){
            int sum = 0;
            for(int k = 0; k < nrows_b; k++){ //here ncols_a can also be used
                /*Accessing the elements of the matrix through their address, in order to do so
                  some manipulation is done to fetch the data from the right address*/
                sum += *(matrix_a+i*ncols_a + k)*(*(matrix_b + k*ncols_b + j ));
            }
            *(multiplied_matrix + i*ncols_b + j) = sum ;
        }
    }
}

void print_matrix(int *matrix, int nrows, int ncols, string message){
    cout << message;

    for(int i =0; i < nrows ; i++){
        for(int j = 0; j < ncols ; j++){
            cout << *(matrix + i*ncols + j) << " ";
        }
        cout << endl; //new line for new row
    }
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

//Main Method

int main(){
    string continue_program;

    do{
        refresh_screen();
        // matrix's rows & columns input
        int ncols_a, nrows_a, ncols_b , nrows_b;
        nrows_a = take_only_positive_input("Enter no of rows of matrix A: ");
        ncols_a = take_only_positive_input("Enter no of columns of matrix A: ");
        nrows_b = take_only_positive_input("Enter no of rows of matrix B ");
        ncols_b = take_only_positive_input("Enter no of columns of matrix B: ");

        /*Verifying the necessary condition for matrix multiplication,
          i.e. the no of columns of matrix A and no of rows of matrix must be equal*/
        while(ncols_a != nrows_b){
            cout << "\nRows of matrix A & Columns of matrix B are not matching, \nPlease try again with valid input :\n";
            int ncols_a, nrows_a, ncols_b , nrows_b;
            nrows_a = take_only_positive_input("Enter no of rows of matrix A: ");
            ncols_a = take_only_positive_input("Enter no of columns of matrix A: ");
            nrows_b = take_only_positive_input("Enter no of rows of matrix B: ");
            ncols_b = take_only_positive_input("Enter no of columns of matrix B: ");
        }

        //Matrix elements input
        int matrix_a[nrows_a][ncols_a], matrix_b[nrows_b][ncols_b];
        take_matrix_input(&matrix_a[0][0], nrows_a,ncols_a, 'A');
        take_matrix_input(&matrix_b[0][0], nrows_b,ncols_b, 'B');

        int multiplied_matrix[nrows_a][ncols_b];
        multiply_matrixes(&matrix_a[0][0], &matrix_b[0][0], &multiplied_matrix[0][0], nrows_a, ncols_b,nrows_b, ncols_a);

        //Printing the entered matrix and multiplied matrix, for better interpretation
        refresh_screen();
        print_matrix(&matrix_a[0][0], nrows_a, ncols_a,"Matrix A: \n");
        print_matrix(&matrix_b[0][0], nrows_b, ncols_b,"\nMatrix B: \n");
        print_matrix(&multiplied_matrix[0][0], nrows_a, ncols_b,"\nResultant matrix: \n");

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
