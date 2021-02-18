//Implementing the queue data structure's FIRST IN LAST OUT algorithm
//Using the linked list to implement the queue
//Making few changes in the implementation gave the following results

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Queue's FIRST IN LAST OUT Implementation :: \n";
    cout << "\t\t  :: The Queue data can be any real number :: \n\n";
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

/*Node for the linked list, that is to be used as queue,
  it consists of two things 1). data 2). pointer of the next noden*/
struct node{
        float data;
        struct node *next_node = NULL;
    };


int queue_length(struct node *head){
    struct node *temp_node = head;
    int queue_len = 1;

    /*The linked list is not of a constant length, therefore to find the length
      we are transversing through the list to find its length*/
    while(temp_node -> next_node != NULL){
        temp_node = temp_node -> next_node;
        queue_len++;
    }
    return queue_len;
}

void front(struct node *head){
    cout << head->data << endl;
}

void pop(struct node *head){
    if(head->next_node ==  NULL){
        head = NULL;
        return;
    }

    /*here, the head is changed to second element of the queue
      and the the previous head is simply dropped*/
    struct node *temp_node;
    temp_node = head->next_node;
    head->data = temp_node->data;
    head->next_node = temp_node->next_node;
}

float peek(struct node *head, int peek_at){

    //Verifying if the peeking index is valid or not
    if(peek_at > queue_length(head) || peek_at < 1){
        cout << "Invalid peeking index. Try Again: ";
        cin >> peek_at;
        peek(head, peek_at);//recursion
    }

    struct node *temp_node = head;
    //in case the index is valid, we go to that index and will fetch the data present their
    for(int i = 1; i<peek_at ; i++){
        temp_node = temp_node->next_node;
    }
    return temp_node->data;
}

/*there's only one way of Pushing data in the queue and it is the at the rear end
  this function pushes a new node to the rear end of the queue*/
void push(struct node *head, float data){
    struct node *rear_end = (struct node*)calloc(1, sizeof(struct node)); // returns the memory address of the memory allocated
    rear_end -> data = data;
    struct node *temp_node = head;

    /*if only one item is there in the queue then pushing is simply
      like attaching a new node just after the front item */
    if(head->next_node == NULL){
        temp_node -> next_node = rear_end;
        return;
    }

    /*In case of multiple elements one has to reach to the second last element
      and then a new node has to attached there*/
    else{
        while(temp_node -> next_node != NULL){
            temp_node = temp_node -> next_node;
        }
    }

    temp_node -> next_node = rear_end;
    return;
}

/**************************** the below declared function will be directly called in the main method *********************************/

void create_queue(struct node *head){
    int no_of_pushs = take_only_positive_input("Enter the length of the queue : ");
    float data;
    cout << "\nEnter the Elements, press ENTER after every element: \n";
    printf("queue_item[1] :");
    data = take_data_input(); //Here, input for head item is taken, and
    head->data = data;

    //Input for the rest of the items and simultaneously they are being pushed in the queue
    for(int i = 1; i<no_of_pushs ; i++){
        printf("queue_item[%d] :", i+1);
        data = take_data_input();
        push(head, data);
    }
}

void peek_in_queue(struct node *head){
    string continue_peek;
    do{
        string message = "\n\nEnter the index to peek at, index is staring from 1: ";
        int to_peek_at = take_only_positive_input(message);
        cout <<  peek(head, to_peek_at);//string to integer conversion

        //Asking to peek again with a valid input
        cout << "\nWould you like to peek again...? (y for yes)/(n for no)\n";
        cin >> continue_peek;

        while( !( compare_strings(continue_peek, "y") || compare_strings(continue_peek, "n") ||
             compare_strings(continue_peek, "Y") || compare_strings(continue_peek, "N"))  ){
            cout << "Invalid Response, enter a valid one: ";
            cin >> continue_peek;
        }
    }while( continue_peek[0] == 'y' || continue_peek[0] == 'Y' );
}

void pop_full_queue(struct node *head){
    int queue_len = queue_length(head);

    while(queue_len--){
        front(head);
        pop(head);
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
        struct node front_end;

        create_queue(&front_end);
        peek_in_queue(&front_end);
        cout << "\nQUEUE POPING:\n";
        pop_full_queue(&front_end);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
