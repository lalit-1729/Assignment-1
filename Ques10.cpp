// Here, we are using the quick sort method
// it is the method, that uses the divide and rule strategy
// we will implement it by defining the two function
// 1). perform_partition
// 2). quick_sort

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Quick Sort On the integers :: \n\n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

/*This function is declared here to fixed the bug in the run-again loop
  As two strings can't be simply compared by str1 == str2, therefore this function is declared to compare the strings
  , by comparing the length first and then each character of the string.*/
bool compare_strings(string string1, string string2){
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

string take_input(){
    string user_input;
    cout << "Enter the size of the array: ";
    cin >> user_input;
    return user_input;
}

bool is_array_input_valid(string user_input){
    int dot_count, i = 0;
    if(user_input[0] == '-')  //For negative number
        i++;

    for(i ; user_input[i] != '\0' ; i++){
        //using the ASCII table to verify, ACSII code for '0'=48 and '9'=57
        if(user_input[i] < 48 || user_input[i] > 57){
            if(user_input[i] == '.'){ // For fractional number
                dot_count++;
                /*A fractional integer can have only one dot to separate the integer and fractional part
                  and the same is being verified here.*/
                if(dot_count > 1)
                    return false;
                else
                    continue;
            }
            return false;
        }
    }
    return true;
}

/*it will take the input form the user, for the whole array,
  but one element at a time and will validate it.*/
void take_array_input(float *arr, int array_size){
    cout << "\n\nEnter the array elements, one at a time, And press ENTER after every element: \n";
    string user_input;

    for(int i = 0;i<array_size ; i++){
        printf("arr[%d] = ", i);
        cin >> user_input;

        //input validation
        while(!is_array_input_valid(user_input)){
            cout << "Invalid Input, please enter a valid one: arr[" << i << "] = ";
            cin >> user_input;
        }
        arr[i] = stof(user_input);//converting the valid input string to float
    }
}

//Validates only the positive values
bool is_input_valid(string user_input){
    for(int i = 0;user_input[i] != '\0'; i++){ // running the loop till the terminating value
        //using the ASCII table to verify, ACSII code for '0'=48 and '9'=57
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

/*prints the provided array with the message provided by the programmer.*/
void print_array(float *arr, int array_size, string message){
    cout << message;
    for(int i = 0; i<array_size ; i++){
        cout << *(arr+i)<< " ";
    }
    cout << endl;
}

//Partition function performs very essential part of Quick sort Technique
//It rearranges the elements in such a way,
//one side of pivot point contain elements smaller than pivot point and
//other contains the elements greater than pivot point
int perform_partition(float arr[], int lower_bound , int upper_bound){
    int start = lower_bound, end = upper_bound;
    float pivot = arr[lower_bound];

    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }

        while(arr[end] > pivot ){
            end--;
        }

        if(start < end){
            swap(arr[end], arr[start]);
        }
    }

    swap(arr[lower_bound] , arr[end]);
    return end;
}

//The Quick Sort function uses the above Partition function
//And using recursion performs partition till the whole array is sorted
void quick_sort(float arr[], int lower_bound, int upper_bound){
    int location;
    if(lower_bound < upper_bound){
        location = perform_partition(arr, lower_bound, upper_bound);

        quick_sort(arr, lower_bound, location - 1);
        quick_sort(arr, location + 1, upper_bound);
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
int main(void){
    string continue_program;

    do{
        refresh_screen();
        string user_input = take_input();

        //input validation
        while(!is_input_valid(user_input)){
            cout << "Invalid Input, please enter a valid one:\n";
            user_input = take_input();
        }

        int array_size = stoi(user_input);   //converting the valid input to integer
        float user_array_input[array_size];

        take_array_input(user_array_input, array_size);
        print_array(user_array_input, array_size, "The User entered array is:\n");//Entered array is being printed

        quick_sort(user_array_input, 0, array_size-1);
        print_array(user_array_input, array_size, "The sorted array is:\n");//Sorted array is being printed

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
