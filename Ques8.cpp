#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        // matrix A input
        int ncols_A, nrows_A;
        cout << "Enter the no. of Rows and Columns of the matrix A, respectively: " << endl;
        cin >> nrows_A >>  ncols_A;
        int matrix_a[nrows_A][ncols_A];
        cout << "Enter the matrix A elements: " << endl;

        for(int row_no =0; row_no < nrows_A ; row_no++){
            for(int col_no = 0; col_no < ncols_A ; col_no++){
                cin >> matrix_a[row_no][col_no];
            }
        }


        cout << "\n\nEnter the no. of Rows and Columns of the matrix B, respectively: " << endl;
        // matrix B input
        int ncols_B , nrows_B;
        cin >> nrows_B >>  ncols_B;
        int matrix_B[nrows_B][ncols_B];
        cout << "Enter the matrix A elements: " << endl;

        for(int row_no = 0; row_no < nrows_B ; row_no++){
            for(int col_no = 0; col_no < ncols_B ; col_no++){
                cin >> matrix_B[row_no][col_no];
            }
        }


        int multiplied_matrix[nrows_A][ncols_B];

        // matrix multiplication
        if(ncols_A == nrows_B){

            for(int matA_rowNo = 0; matA_rowNo < nrows_A ; matA_rowNo++){
                for(int matB_colNo = 0; matB_colNo < ncols_B; matB_colNo++){
                    int sum = 0;
                    for(int k = 0; k < nrows_B; k++){ // k can be either matrix A col number or matrix B row number
                        sum += matrix_a[matA_rowNo][k]*matrix_B[k][matB_colNo];
                    }
                    multiplied_matrix[matA_rowNo][matB_colNo] = sum ;
                }
            }

        }

        else{
            cout << "\n\nMatrix multiplication is not possible. ";
            return 0;
        }

        // displaying results
        cout << "\n\nResultant matrix: \n" << endl;
        for(int rowNo =0; rowNo < nrows_A ; rowNo++){
            for(int colNo = 0; colNo < ncols_B ; colNo++){
                cout << multiplied_matrix[rowNo][colNo] << " ";
            }
            cout << endl;
        }

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
