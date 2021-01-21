#matrix multiplication using oop


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
                for k in range(col_B):
                    sum += self.matrix[i][k]*matB[k][j]
                row.append(sum)
            self.multiplied_matrix.append(row)
        return self.multiplied_matrix                 

run_again = 'y'
while(run_again == 'y'):

    #matrix_A input
    rows_A, columns_A = input("Enter the number of row and columns of the Matrix A: ").split(' ', 2)
    rows_A = int(rows_A)
    columns_A = int(columns_A)
    matrix_A =  Matrix(rows_A, columns_A)
    print("Enter the matrix A: ")
    matrix_A.matrix_input()

    #matrix_B input
    rows_B, columns_B = input("Enter the number of row and columns of the Matrix B: ").split(' ', 2)
    rows_B = int(rows_B)
    columns_B = int(columns_B)
    matrix_B =  Matrix(rows_B, columns_B)
    print("Enter the matrix B: ")
    matrix_B.matrix_input()

    #matrix_multiplication
    multiplied_matrix = matrix_A.multiply(matrix_B.matrix)

    #result output
    print("\n The multiplied matrix is: ")
    for i in range(columns_A):
        print(end ="\n")
        for j in range(rows_B):
            print(multiplied_matrix[i][j], end = " ")

    run_again = input("\n\nDo you wanna run this program again...?? (y/n)")
    



























    
    

