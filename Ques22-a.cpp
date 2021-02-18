//Implementing the Stack data structure's Last in first out algorithm
//Using the linked list to implement the stack
//Linked list was implement in the previous Question, Ques21

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Stack's FIRST IN LAST OUT Implementation :: \n";
    cout << "\t\t  :: The stack data can be any real number :: \n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

//this function is similar to that of 'strcmp' function of string.h,
//this function will be used in the program-run again loop, for the validation of the input
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
            if(user_input[i] == '.'){ // For fractional number, only one dot is permissible
                dot_count++;
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
    return stoi(user_input);//String to int conversion
}

float take_data_input(){
    string user_input;
    cin >> user_input;

    //input validation
    while(!is_input_real_number(user_input)){
            cout << "Invalid input, please enter valid one:\n";
            cin >> user_input;
    }
    return stof(user_input); //String to float conversion
}

//Structure for the node of the linked list
//Node will have at least two things with it
//first is data, second is the address of the next node
struct node{
    float data;
    struct node *next_node = NULL;
};

int stack_length(struct node *bottom){
    struct node *temp_node = bottom;
    int stack_len = 1;

    /*To find the length, we are doing List transversal till the NULL next node,
      and increment to the list length after each node*/
    while(temp_node -> next_node != NULL){
        temp_node = temp_node -> next_node;
        stack_len++;
    }
    return stack_len;
}

//This function will only print the data that is at the top of the stack
void top(struct node *bottom){
    //If only one item is there in the stack then the bottom is the top
    if(bottom->next_node == NULL){
        cout << bottom->data;
        return;
    }
    struct node *temp_node = bottom->next_node;
    //If multiple items are present then, we have go through each node till the top of the stack & then print it
    while(temp_node -> next_node != NULL){
        temp_node = temp_node -> next_node;
    }
    cout << temp_node->data << endl;
}

//Since, we are implementing the FIRST IN LAST OUT algorithm of the stack, therefore, POP will only remove the element from the top
//and won't return anything
void pop(struct node *bottom){
    if(bottom->next_node == NULL){ //for a single node stack
        bottom = NULL;
        return;
    }

    struct node *temp_node = bottom;
    struct node *temp_node2; //This node will store the address of the second last node, to make its next_node address NULL later
    while(temp_node -> next_node != NULL){
        temp_node2 = temp_node;
        temp_node = temp_node -> next_node;
    }

    temp_node2 ->next_node = NULL;
    free(temp_node); //freeing the allocated memory of popped item
}

//Peeks at a particular location
// assuming the indexing starts from 1
float peek(struct node *bottom, int peek_at){
    if(peek_at > stack_length(bottom) || peek_at < 1){ //for the invalid input
        cout << "Invalid peeking index. Try Again: ";
        cin >> peek_at;
        peek(bottom, peek_at);//recursion
    }

    struct node *temp_node = bottom;
    for(int i = 1; i<peek_at ; i++){
        temp_node = temp_node->next_node;
    }
    return temp_node->data;
}

//Since, its a stack data structure, the item can only be entered at the top
//And the push function does it for us
void push(struct node *bottom, float data){
    struct node *tail = (struct node*)calloc(1, sizeof(struct node)); // returns the memory address of the memory allocated
    tail -> data = data;
    struct node *temp_node = bottom;

    /*if only one item is present in the stack then pushing in the stack is very easy
      we just have to change the address of the next node of the bottom element to no new element*/
    if(bottom->next_node == NULL){
        temp_node -> next_node = tail;
        return;
    }
    else{
        while(temp_node -> next_node != NULL){
            temp_node = temp_node -> next_node;
        }
    }

    temp_node -> next_node = tail;
}

//Below declared function will use the above declared function, so that they can be directly called in the MAIN METHOD

void create_stack(struct node *bottom){
    int no_of_pushs = take_only_positive_input("\nEnter the length of the stack: ");
    cout << "\nEnter the Elements, press ENTER after every element: \n";

    //Taking the input for the bottom element only
    printf("List_item[1]: ");
    float data = take_data_input();
    bottom->data = data;

    //Taking input for the rest of the nodes
    for(int i = 1 ; i < no_of_pushs ; i++){
        printf("List_item[%d]: ", i+1);
        data = take_data_input();
        push(bottom, data);
    }
}

void peek_in_stack(struct node *bottom){
    string continue_peek;

    do{
        string message = "\n\nEnter the index to peek at, index is staring from 1: ";
        int peek_at = take_only_positive_input(message);
        cout <<  peek(bottom, peek_at);//string to integer conversion

        cout << "\nWould you like to peek again...? (y for yes)/(n for no)";
        cin >> continue_peek;

        //Asking to peek again, with a valid input
        while(  !( compare_strings(continue_peek, "y") || compare_strings(continue_peek, "n") ||
             compare_strings(continue_peek, "Y") || compare_strings(continue_peek, "N")) ){
            cout << "Invalid Response, enter a valid one: ";
            cin >> continue_peek;
        }

    }while(compare_strings(continue_peek, "y") || compare_strings(continue_peek, "Y"));
}

void pop_full_stack(struct node *bottom){
    int stack_len = stack_length(bottom);

    while(stack_len--){
        top(bottom); //displaying the top
        pop(bottom); //Removing the top
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


//the main method starts here
int main(){
    string continue_program;

    do{
        refresh_screen();
        struct node bottom;

        create_stack(&bottom);
        peek_in_stack(&bottom);
        cout << "\nSTACK POPPING:\n";
        pop_full_stack(&bottom);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
