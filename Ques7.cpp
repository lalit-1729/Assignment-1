//This program takes the input form the user
//Validates the input
//And gives the square of the number as output

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: SQUARE ROOT :: \n\n";
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


void take_input(string *user_input){
    cout << "Enter a number to find it's square root: \n";
    cin >> *user_input;
}

//Since, the square root of the negative number is not possible we will take only positive input from the user,
//Therefore, this function helps us with that
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

/*this function Returns divisor,
  which is required in each step of long division method*/
int return_divisor(int num1, int num2){
    int divisor;
    int i = 0;
    do{
        divisor = num1*10+i;
        i++;
    }while((num1*10+i)*i <= num2);

    return divisor;
}

//Power function declared to divide the quotient by a certain power of 10 to return a fractional quotient
double power(int base, int exponent){
    if(exponent == 0)
        return 1;
    else
        return base*power(base, exponent-1);
}

int no_of_digits(int number){
    int ndigits;
    for(ndigits = 0;number!=0 ; ndigits++, number/=10 );
    return ndigits;
}

/*To compute the square by long division method we have to create pairs of two integers
  This function will create a array of two consecutive digits*/
void create_pair_of_two(int *pairs_array, int number, int pairs){
    for(int i = 0; i<=pairs; i++){ // creating an array of pairs
        pairs_array[i] = number%100;
        number/=100;
    }
}

//this function will update the quotient after performing each step of the long division method
int update_quotient(int quotient, int *remainder, int *pairs_array, int npairs){
    int divisor, unit_place_of_divisor;

    for(int i = npairs-1; i>=0; i--){
        divisor = return_divisor(2*quotient, (*remainder)*100 + pairs_array[i]);
        unit_place_of_divisor = divisor % 10;
        if(unit_place_of_divisor == 0)   //In case the units place place of the divisor is zero, this implies that the divisor is also zero
            divisor = 0;

        *remainder = (*remainder)*100 + pairs_array[i] - (20*quotient + unit_place_of_divisor)*unit_place_of_divisor;
        quotient = quotient*10 + unit_place_of_divisor;
    }

    return quotient;
}

/*This function is used to calculate the square root of the input
  by using the long division method, for detailed explanation of long division method
  Please see : https://byjus.com/maths/square-root-long-division-method/ */
double compute_square_root(int number, int preciseness){

    int ndigits = no_of_digits(number);
    int npairs = (ndigits-1)/2; // counting the number of pairs of two digit and subtracting 1 from it
    int pairs_array[npairs];
    create_pair_of_two(pairs_array,number, npairs);

    double quotient;
    /*Computing the first digit, which is the largest number whose square
      is less than or equal to the left most digit*/
    for(int i = 0; i<=10 ; i++){
        if(i*i > pairs_array[npairs])
            break;
        quotient = i;
    }

    int remainder = pairs_array[npairs] - quotient*quotient;
    quotient = update_quotient(quotient, &remainder, pairs_array, npairs); //Here only the integer part will be computed

    int zeros_array[preciseness] = {0}; //Initializing all elements zero
    //computing the fractional part but not as a fractional part i.e. decimal point is absent
    quotient = update_quotient(quotient, &remainder, zeros_array, preciseness);

    return quotient/power(10, preciseness); // returning the square root but with a fractional part
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


int main(){
    string continue_program;

    do{
        refresh_screen();
        string user_input;
        take_input(&user_input);

        //input validation
        while(!is_input_valid(user_input)){
            cout << "\nInvalid Input, please try a valid one:\n";
            take_input(&user_input);
        }
        unsigned int number = stoi(user_input);//string to integer conversion

        double sq_root = compute_square_root(number, 5); //can change the preciseness here, less than equal to 5
        printf("\n\nThe square root of the %d is : %.5f", number, sq_root);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
