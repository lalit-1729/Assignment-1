#include <stdlib.h>
#include <iostream>
using namespace std;

// defining the stack class
class Stack{

    public:
    int top_element = -1;
    int array[10000]= {0};

    void push(int to_be_pushed){
        array[++top_element] = to_be_pushed;
    }

    void pop(){
        array[top_element--] = 0;
    }

    int size(){
        return top_element+1;
    }

    int peek(int index){
        return array[index-1];
    }

    int top(){
        return array[top_element];
    }

    bool is_empty(){
        if(top_element == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    char run_again = 'y';
    while(run_again == 'y'){
        system("cls");

        Stack stack1;

        int stack_size;
        cout << "Enter the size of the stack (less than 10000) you want: " << endl;
        cin >> stack_size;

        int stack_element;
        cout << "Stack Pushing, Enter the elements: "<< endl;
        for(int i = 0 ; i<stack_size ; i++){
            cin >> stack_element;
            stack1.push(stack_element);
        }

        char to_peek = 'y';
        while(to_peek == 'y'){

            cout << "\nDo you want to peek in the stack...??? (y/n) ";
            cin >> to_peek;
            if(to_peek != 'y'){
                break;
            }

            int to_peek_at;
            cout << "Enter the index of the element to: ";
            cin >> to_peek_at;
            cout << stack1.peek(to_peek_at) << "\n";

        }

        cout  << "\nStack Poping:" << endl;
        for(int i = 0 ; i<stack_size ; i++){
            cout << stack1.top() << endl;
            stack1.pop();

            if(stack1.is_empty()){
                cout << "The stack is empty" << endl;
            }
        }

        //asking to run again
        cout << "\nDo you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }

    return 0;
}
