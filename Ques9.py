#matrix multiplication using oop
from os import system # to clear the console window after every successful run

class Matrix:
    def __init__(self, row, column):
        self.row = row
        self.column = column

    def matrix_input(self):
        self.matrix = [input().split(' ', self.column) for i in range(self.row)]
        for i in range(self.row):
            for j in range(self.column):
                self.matrix[i][j] = int(self.matrix[i][j])
        return self.matrix

    def multiply(self, matB):
        row_A = len(self.matrix)
        row_B = len(matB)
        col_A = len(self.matrix[0])
        col_B = len(matB[0])
        self.multiplied_matrix = []

        for i in range(row_A):
            row = []
            for j in range(col_B):
                sum = 0
                for k in range(row_B):
                    sum += self.matrix[i][k]*matB[k][j]
                row.append(sum)
            self.multiplied_matrix.append(row)
        return self.multiplied_matrix

def take_input(matrix_name):
    print("Enter the rows and columns of matrix of ", matrix_name," :")
    rows , columns = 0,0
    #input validation
    while True:
        try:
            user_input1, user_input2 = input().split(' ', 2)
            rows = int(user_input1)
            columns = int(user_input2)
            if rows < 1 or columns < 1:
                print("Positive integer only ,please try again with a valid one:")
                continue
            else:
                break
        except ValueError:
            print("Invalid Integer, please try again with a valid one:")
            
    return rows, columns

def print_matrix(matrix):
    rows = len(matrix)
    columns = len(matrix[0])
    for i in range(rows):
        print(end ="\n")
        for j in range(columns):
            print(multiplied_matrix[i][j], end = " ")
    

continue_program = 'y'
while(continue_program == 'y'):
    system("cls")#clears the console window

    print("\n\n\t\t :: MATRIX MULTIPLICATION USING OOP :: \n\n  ")
    rows_A, columns_A = take_input('A')
    rows_B, columns_B = take_input('B')
    
    #Verifying the required condition for the matrix multiplication
    while columns_A != rows_B:
        print("\nThe no. of rows of matrix A is not matching with the no. of columns, please try again with a valid onoe:")
        rows_A, columns_A = take_input('A')
        rows_B, columns_B = take_input('B')
        
    matrix_A =  Matrix(rows_A, columns_A)
    print("Enter the matrix A: ")
    matrix_A.matrix_input()

    matrix_B =  Matrix(rows_B, columns_B)
    print("Enter the matrix B: ")
    matrix_B.matrix_input()

    #matrix_multiplication
    multiplied_matrix = matrix_A.multiply(matrix_B.matrix)

    #result output
    print("\n The multiplied matrix is: ")
    print_matrix(multiplied_matrix)
    
    #asking user to rerun
    continue_program = input("\nWould you like to rerun the program...?? (y for yes)/ (n for no)\n")
    while not (continue_program == 'y' or continue_program == 'n'):
        print("Invalid input, please try again with a valid one:")
        continue_program = input("\n\nWould you like to rerun the program...?? (y for yes)/ (n for no)")
        
print("\n\n\t\t YOU JUST QUIT THE PROGRAM....!!!")