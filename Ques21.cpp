//implementing the linked list
//Using Struct to implement the linked list
//OOP can also be used for the same

#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Linked List Implementation :: \n";
    cout << "\t\t :: The list data can be any real number ::\n";
    cout << "\t\t :: The indexing of list is 0 based :: \n\n";
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

//Node is like the smallest part of the linked list
//it stores consists of at two parts
//1). data 2). Pointer of the next node
struct node{
        float data;
        struct node *next_node = NULL;
};

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
    return stoi(user_input);
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

int list_length(struct node *head){
    struct node *temp_node = head;
    int list_len = 1;
    while(temp_node -> next_node != NULL){ //going through each node
        temp_node = temp_node -> next_node;
        list_len++;
    }
    return list_len;
}

//clearing list, except the head
void clear_list(struct node *head){
    struct node *temp_node = head->next_node;
    struct node *temp_node2;
    while(temp_node -> next_node != NULL){
        //Keeping the address of the next node safe.
        temp_node2 = temp_node->next_node;
        free(temp_node); //Freeing the allocated memory
        temp_node = temp_node2;
    }
    head = NULL;
    cout << "the list is cleared..!!";
    return;
}

void prepend(struct node *head, float data){ // inserts at the head
    struct node *new_head = (struct node*)calloc(1, sizeof(struct node));
    new_head->data = head->data;
    new_head->next_node = head->next_node;
    head->next_node = new_head;
    head->data = data;
}

//This function will be used to enter at a particular index of the list
void insert_at_location(struct node *head, int location, float data){
    //If we want to insert at the head, we will simply prepend it
    if(location == 0)
        prepend(head, data);

    struct node *to_insert = (struct node*)calloc(1, sizeof(struct node));
    to_insert -> data = data;
    struct node *temp_node = head; //Tempnode2 will be having the address of the node with index location-1
    for(int i = 1; i<location; i++){
        temp_node = temp_node->next_node;
        if(i == location-1)
            break;
    }
    struct node *temp_node2 = temp_node->next_node; //Tempnode2 will be having the address of the node with index location
    //Inserting a node between node at location and location-1
    temp_node->next_node = to_insert;
    to_insert->next_node = temp_node2;
}

//finding in a list and returning the index
int find_in_list(struct node *head, float to_find){ // assuming the indexing is zero based
    struct node *temp_node = head;
    for(int i = 0; temp_node->next_node !=NULL ; i++){
        if(temp_node -> data == to_find)
            return i;
        temp_node = temp_node->next_node;
    }
    return 0;
}

void extend(struct node *head, float data){

    struct node* tail = (struct node*)calloc(1, sizeof(struct node)); // returns the memory address of the memory allocated
    tail -> data = data; //Creating the new tail
    struct node *temp_node = head;

    //Extending after the first element is simple, just giving head the address of the tail
    if(head->next_node == NULL){
        temp_node -> next_node = tail;
        return;
    }

    //Here, we are finding the index of the previous tail
    else{
        while(temp_node -> next_node != NULL){
            temp_node = temp_node -> next_node;
        }
    }
    temp_node -> next_node = tail; //Giving the previous tail the address of the new tail
    return;
}

void display_list(struct node *head){
    struct node *temp_node = head;

    //fetching the data of each node and printing it
    while(temp_node -> next_node != NULL){
        cout << temp_node -> data << " -> ";
        temp_node = temp_node -> next_node;
    }
    cout << temp_node->data << " -> " << "NULL" << endl;
}

//Below defined function are using the above mentioned function, so that they can be directly called in the main method

void create_linked_list(struct node *head){
    cout << "Enter the head element:";
    float data = take_data_input();
    head->data = data;
    short int no_of_extends = take_only_positive_input("Enter the no of elements to add after the head:");

    cout << "\nEnter the Elements to extend, press ENTER after every entry: \n";
    for(int i = 1; i <= no_of_extends; i++){
        printf("list_item[%d] :", i);
        data = take_data_input();
        extend(head, data);
    }
}


void prepend_linked_list(struct node *head){
    short int no_of_prepends = take_only_positive_input("\n\nEnter the no of Elements to prepend in the list :");
    float data;

    cout << "Enter the Elements to prepend, press ENTER after every entry: \n";
    for(int i = 1; i <= no_of_prepends; i++){
        printf("list_item[%d] :", i);
        data = take_data_input();
        prepend(head, data);
    }
}

void insert_in_linked_list(struct node *head){
    cout << "\nINSERTING AT A PARTICULAR LOCATION:\n\n";
    int location = take_only_positive_input("Enter the location to insert at: ");

    //Validating the index
    while(location > list_length(head)){
            cout << "Index not valid please try again with a valid one:\n";
            location = take_only_positive_input("Enter the location to insert at: ");
    }
    cout << "Enter the data to insert: ";
    float data = take_data_input();
    insert_at_location(head, location, data) ;
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
        int data;
        struct node head; //Head node, this will represent thew whole list
        create_linked_list(&head);

        cout << "\nThe list after extending is as follows: " << endl;
        display_list(&head);

        prepend_linked_list(&head);
        cout << "\n\nThe list after prepending is as follows: " << endl;
        display_list(&head);

        insert_in_linked_list(&head);
        cout << "\n\nThe list after inserting is as follows: " << endl;
        display_list(&head);

        cout << "\n\nClearing the list....\n";
        clear_list(&head);

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
