// implementing the linked list

#include <iostream>
#include <stdlib.h>
using namespace std;

// node
struct node{
        int data;
        struct node *next_node = NULL;
    };

// clearing list
void clear_list(struct node *head){
    struct node *temp_node = head;
    while(temp_node -> next_node != NULL){
        temp_node = temp_node -> next_node;
        free(temp_node);
    }
    cout << "the list is cleared..!!";
    return;
}

//inserting at a particular location
void insert_at_location(struct node *head, int location, int data){
    struct node *to_insert = (struct node*)calloc(1, sizeof(struct node));
    to_insert -> data = data;
    struct node *temp_node = head;
    for(int i = 1; i<=location; i++){
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

// inserting before the head
void prepend(struct node *head, int data){ // inserts at the head
    struct node *HEAD = (struct node*)calloc(1, sizeof(struct node));
    HEAD->data = head->data;
    HEAD->next_node = head->next_node;
    head->next_node = HEAD;
    head->data = data;
    return;
}

// displaying the whole list
void display_list(struct node *head){ // displays the whole list
    struct node *temp_node = head;
    while(temp_node -> next_node != NULL){
        cout << temp_node -> data << " -> ";
        temp_node = temp_node -> next_node;
    }
    cout << temp_node->data << " -> " << "NULL" << endl;
    return;
}

int main(){
    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        int data;
        cout << "Enter the head element: ";
        cin >> data;
        struct node head;
        head.data = data;

        int no_of_extends;
        cout << "\nEnter the no of elements you wanna add at the tail: ";
        cin >> no_of_extends;

        cout << "Enter the Elements to extend: \n";
        while(no_of_extends--){
            cin >> data;
            extend(&head, data);
        }
        cout << "The list after extending is as follows: " << endl;
        display_list(&head);



        int no_of_prepends;
        cout << "\nEnter the no of elements you wanna add before the head: ";
        cin >> no_of_prepends;

        cout << "Enter the Elements to prepend: \n";
        while(no_of_prepends--){
            cin >> data;
            prepend(&head, data);
        }
        cout << "The list after prepending is as follows: " << endl;
        display_list(&head);


        cout << "\n\nClearing the list....\n";
        clear_list(&head);

        //asking to run again
        cout << "\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
