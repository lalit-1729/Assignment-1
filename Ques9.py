#matrix multiplication using oop
from os import system # to clear the console window after every successful run

class Matrix:
    def __init__(self, row, column):
        self.row = row
        self.column = column

    def matrix_input(self):
        #Initializing a rows x columns matrix with all elements equal to 0
        self.matrix = [[0 for i in range(self.column)] for j in range(self.row)]
        
        #this function will take the input for a single element of the matrix 
        #And will also validate the input as a integer only
        def element_input(message):
            print(message, end=" ")
            user_input = 0
            #input validation
            while True:
                try:
                    user_input = input()
                    user_input = int(user_input)
                    break
                except ValueError: #this will take the input from the user
                    print("Invalid Integer, please try again with a valid one:")
                    print(message, end=" ")
            return user_input
        
        for i in range(self.row):
            for j in range(self.column):
                message = "Matrix Element[{fi}][{fj}]:".format(fi=i, fj=j)
                self.matrix[i][j] = element_input(message)
        return self.matrix

    def multiply(self, matB):
        row_A = len(self.matrix)
        row_B = len(matB)
        col_A = len(self.matrix[0])
        col_B = len(matB[0])
        self.multiplied_matrix = []
        
        #this function perfroms the multiplication on the matrix provided
        #here we will append a row with sum of product of elements of the row and column 
        #and then this row will be later appended in the multiplied matrix
        for i in range(row_A):
            row = [] 
            for j in range(col_B):
                sum = 0
                for k in range(row_B):
                    sum += self.matrix[i][k]*matB[k][j]
                row.append(sum)
            self.multiplied_matrix.append(row)
            
        return self.multiplied_matrix

def take_positive_input(message):
    print(message, end = ' ')
    user_input = 0
    
    #input validation
    while True:
        try:
            user_input = input()
            user_input = int(user_input)
            if user_input < 1:
                print("Positive integer only ,please try again with a valid one:")
                continue
            else:
                break
        except ValueError:
            print("Invalid Integer, please try again with a valid one:")
            
    return user_input

#This function will print the matrix in its traditional manner
#i.e. in the tabular form
def print_matrix(matrix, message):
    print(message)
    rows = len(matrix)
    columns = len(matrix[0])
    
    for i in range(rows):
        for j in range(columns):
            print(matrix[i][j], end = " ")
        print(end ="\n") #
    

continue_program = 'y'
while(continue_program == 'y' or continue_program == 'Y'):
    system("cls")#clears the console window
    print("\n\n\t\t :: MATRIX MULTIPLICATION USING OOP :: \n\n  ")
    
    #taking input for all the required rows and columns 
    #and the validation is being done simultaneously 
    rows_A = take_positive_input("Enter the no of ROWS of matrix A: ")
    columns_A = take_positive_input("Enter the no of COLUMNS of matrix A: ")
    rows_B = take_positive_input("Enter the no of ROWS of matrix B: ")
    columns_B = take_positive_input("Enter the no of COLUMNS of matrix A: ")
    
    #Verifying the required condition for the matrix multiplication
    #i.e. the no fo columns of first matrix must be equal to no of rows of the second matrix
    while columns_A != rows_B:
        print("\nThe no. of rows of matrix A is not matching with the no. of columns, please try again with a valid onoe:")
        rows_A = take_positive_input("Enter the no of ROWS of matrix A: ")
        columns_A = take_positive_input("Enter the no of COLUMNS of matrix A: ")
        rows_B = take_positive_input("Enter the no of ROWS of matrix B: ")
        columns_B = take_positive_input("Enter the no of COLUMNS of matrix A: ")
        
    matrix_A =  Matrix(rows_A, columns_A)
    print("\n\nEnter the elements of matrix A, press ENTER after every entry: ")
    matrix_A.matrix_input()

    matrix_B =  Matrix(rows_B, columns_B)
    print("\n\nEnter the elements of matrix B, press ENTER after every entry: ")
    matrix_B.matrix_input()

    #matrix_multiplication
    multiplied_matrix = matrix_A.multiply(matrix_B.matrix)

    #printing all the entered matrix and the multiplied matrix
    #for better interpretation 
    system("cls")#clears the console window
    print("\n\n\t\t :: MATRIX MULTIPLICATION USING OOP :: \n")
    print_matrix(matrix_A.matrix,"\nMatrix A: ")
    print_matrix(matrix_B.matrix,"\nMatrix B: ")
    print_matrix(multiplied_matrix,"\nThe multiplied matrix is: ")
    
    #asking user to rerun
    continue_program = input("\nWould you like to rerun the program...?? (y for yes)/ (n for no)\n ")
    while not (continue_program == 'y' or continue_program == 'n'
               or continue_program == 'N' or continue_program == 'Y'):
        print("Invalid input, please try again with a valid one: ", end=" ")
        continue_program = input()
        
print("\n\n\t\t YOU JUST QUIT THE PROGRAM....!!!")