//Implementing the Stack data structure
//Using the linked list to implement the stack
//Linked list was implement in the previous Question

#include <iostream>
#include <stdlib.h>
using namespace std;

//Validates only non-negative number
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Node for the linked list
struct node{
        int data;
        struct node *next_node = NULL;
    };

//Returns the length of the stack
int stack_length(struct node *head){
    struct node *temp_node = head;
    int stack_len = 1;
    while(temp_node -> next_node != NULL){ //going through each node
        temp_node = temp_node -> next_node;
        stack_len++;
    }
    return stack_len;
}

//Prints the top node's data
void top(struct node *head){
    if(head->next_node == NULL){
        cout << head->data;
        return;
    }
    struct node *temp_node = head->next_node;
    while(temp_node -> next_node != NULL){ //going through each node
        temp_node = temp_node -> next_node;
    }
    cout << temp_node->data << endl;
}

//POPS the top node
void pop(struct node *head){
    if(head->next_node == NULL){ //for a single node stack
        head = NULL;
        return;
    }
    struct node *temp_node = head;
    struct node *temp_node2; //This node will store the address of the second last node
    while(temp_node -> next_node != NULL){ //going through each node
        temp_node2 = temp_node;
        temp_node = temp_node -> next_node;
    }
    temp_node2 ->next_node = NULL;
    free(temp_node);
}

//Peeks at a particular location
// assuming the indexing starts from 1
int peek(struct node *head, int peek_at){
    if(peek_at > stack_length(head) || peek_at < 1){
        cout << "Invalid peeking index. Try Again: ";
        cin >> peek_at;
        peek(head, peek_at);//recursion
    }

    struct node *temp_node = head;
    for(int i = 1; i<peek_at ; i++){
        temp_node = temp_node->next_node;
    }
    return temp_node->data;
}

//Pushing at the top
void push(struct node *head, int data){
    struct node *tail = (struct node*)calloc(1, sizeof(struct node)); // returns the memory address of the memory allocated
    tail -> data = data;
    struct node *temp_node = head;

    if(head->next_node == NULL){
        temp_node -> next_node = tail;
        return;
    }

    else{
        while(temp_node -> next_node != NULL){
            temp_node = temp_node -> next_node;
        }
    }

    temp_node -> next_node = tail;
    return;
}

//Creates a stack in the main method
void create_stack(struct node *head){
    string user_input;
    cout << "\nEnter the length of the stack: ";
    cin >> user_input;
    //input validation
    while(is_input_valid(user_input) == false){
        cout << "Invalid input, Please try a valid one: ";
        cin >> user_input;
    }

    int no_of_pushs = stoi(user_input) - 1;
    int data;
    cout << "\nEnter the Elements, press ENTER after every element: \n";
    cin >> data; //first element data
    head->data = data;

    //Rest elements data
    while(no_of_pushs--){
        cin >> data;
        push(head, data);
    }
}

//Peek in stack function for the main method
void peek_in_stack(struct node *head){
    char continue_peek;
    do{
        string user_input;
        cout << "\n\nEnter the index to peek at, index is staring from 1: ";
        cin >> user_input;

        //Input Validation
        while(is_input_valid(user_input) == false){
            cout << "Invalid input, please try a valid one: ";
            cin >> user_input;
        }
        cout <<  peek(head, stoi(user_input));//string to integer conversion

        cout << "\nWould you like to peek again...? (y for yes)/(n for no)";
        cin >> continue_peek;

        //Input Validation
        while( !( continue_peek == 'y' || continue_peek == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> continue_peek;
        }
        if(continue_peek == 'n' )
            break;

    }while(continue_peek != 'q');
}

//Pops the full stack in the main method
void pop_full_stack(struct node *head){
    int stack_len = stack_length(head);

    while(stack_len--){
        top(head);
        pop(head);
    }
}

//Asking user to rerun and returning the bool value accordingly
bool want_to_run_again(){
    char continue_program;
    cout << "\n\nWould you like to run the program again? (y for yes)/(n for no)" << endl;
    cin >> continue_program;

    //input validation, validates only lowercase 'y' & 'n'
    while( !( continue_program == 'y' || continue_program == 'n' ) ){
        cout << "Invalid Response, enter a valid one: ";
        cin >> continue_program;
    }

    if(continue_program == 'y'){
        return true;
    }
    else{
        cout << "\n\n\t\t\t YOU JUST QUIT THE PROGRAM...!!!\n\n";
        return false;
    }
}


int main(){
    do{
        system("cls");//Clears the console window after every successful run
        cout << "\n\n\t\t :: STACK IMPLEMENTATION :: \n\n";
        struct node head;

        create_stack(&head);
        peek_in_stack(&head);
        cout << "\nSTACK POPING:\n";
        pop_full_stack(&head);

    }while(want_to_run_again() == true);

    return 0;
}
