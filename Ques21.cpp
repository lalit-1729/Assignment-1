//implementing the linked list
//Using Struct to impement the linked list
//OOP can also be used for the same


//CHANGES ::
//Earlier the clear list function was not working well, therefore modified
//inserting at particular for index 0 was not possible, therefore modified


#include <iostream>
#include <stdlib.h>
using namespace std;

//node
struct node{
        int data;
        struct node *next_node = NULL;
};

//Validates only non-negative integers
bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        // using the ACSII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            return false;
        }
    }
    return true;
}

//Takes the input from the user
int take_input(string what_to_insert){
    string user_input;
    cout << "Enter the " << what_to_insert << " :\n";
    cin >> user_input;

    //input validation
    while(is_input_valid(user_input) == false){
        if(is_input_valid(user_input) == false){
            cout << "Invalid input, please try again with a valid one:\n";
            cin >> user_input;
        }
    }
    return stoi(user_input);
}

//Returns the length of the list
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
        free(temp_node);
        temp_node = temp_node2;
    }
    head = NULL;
    cout << "the list is cleared..!!";
    return;
}

// inserting before the head
void prepend(struct node *head, int data){ // inserts at the head
    struct node *new_head = (struct node*)calloc(1, sizeof(struct node));
    new_head->data = head->data;
    new_head->next_node = head->next_node;
    head->next_node = new_head;
    head->data = data;
    return;
}

//inserting at a particular location
void insert_at_location(struct node *head, int location, int data){

    if(location == 0){
        prepend(head, data);
        return;
    }

    struct node *to_insert = (struct node*)calloc(1, sizeof(struct node));
    to_insert -> data = data;
    struct node *temp_node = head;
    for(int i = 1; i<location; i++){
        temp_node = temp_node->next_node;
        if(i == location-1){
            break;
        }
    }
    struct node *temp_node2 = temp_node->next_node;
    temp_node->next_node = to_insert;
    to_insert->next_node = temp_node2;
}

//finding in a list and returning the index
int find_in_list(struct node *head, int to_find){ // assuming the indexing is zero based
    struct node *temp_node = head;
    for(int i = 0; temp_node->next_node !=NULL ; i++){
        if(temp_node -> data == to_find){
            return i;
        }
        temp_node = temp_node->next_node;
    }
    return 0;
}


// inserting at the tail
void extend(struct node *head, int data){ // inserts at the tail

    struct node* tail = (struct node*)calloc(1, sizeof(struct node)); // returns the memory address of the memory allocated
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

// displaying the whole list
void display_list(struct node *head){
    struct node *temp_node = head;
    while(temp_node -> next_node != NULL){
        cout << temp_node -> data << " -> ";
        temp_node = temp_node -> next_node;
    }
    cout << temp_node->data << " -> " << "NULL" << endl;
    return;
}



//Creates a link list in the main method
void create_linked_list(struct node *head){
    int data;
    cout << "Enter the head element: ";
    cin >> data;
    head->data = data;
    int no_of_extends = take_input("no of elements after the head");

    cout << "Enter the Elements to extend: \n";
    while(no_of_extends--){
        cin >> data;
        extend(head, data);
    }
}

//Prepends the linked list in the main method
void prepend_linked_list(struct node *head){
    int no_of_prepends = take_input("no of Elements to prepend"), data;

    cout << "Enter the Elements to prepend: \n";
    while(no_of_prepends--){
        cin >> data;
        prepend(head, data);
    }
}

//Inserting at a particular location in the list in the main method
void insert_in_linked_list(struct node *head){
    cout << "\nINSERTING AT A PARTICULAR LOCATION:\n\n";
    int location = take_input(" location to insert at");

    //Validating the index
    while(location > list_length(head)){
        if(location > list_length(head)){
            cout << "Index not valid please try again with a valid one:\n";
            location = take_input(" location to insert at");
        }
    }
    int data = take_input("Data to insert");
    insert_at_location(head, location, data) ;
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
        system("cls");//Clears the screen after every successful run
        cout << "\n\n\t\t :: LINKED LIST ::\n\n";
        int data;
        struct node head;
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

    }while(want_to_run_again() == true);

    return 0;
}
