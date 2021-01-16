#include <iostream>
#include <stdlib.h>
using namespace std;

//defining the Queue class
class Queue{
    public:
    int back_element = -1;
    int array[10000] = {0}; // assuming the max lengt of Queue is 10000

    //push method
    void push(int to_be_pushed){
        array[++back_element] = to_be_pushed;
    }

    //pop method
    void pop(){
        for(int index = 0; index < back_element ; index++){
            array[index] = array[index+1];
            if(index == 10000){
                array[index] = 0;
            }
        }
        back_element--;
    }

    // front method
    int front(){
        return array[0];
    }

    // is_empty method
    bool is_empty(){
        if(back_element == -1){
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
        Queue queue1;

        int queue_length;
        int queue_element;
        cout << "Enter the length of the Queue: " << endl;
        cin >> queue_length;
        cout << "Queue Pushing, Enter the elements of the Queue: " <<  endl;
        for(int i = 0; i < queue_length ; i++){
            cin >> queue_element ;
            queue1.push(queue_element);
        }

        cout << "\nQueue Poping:" << endl;
        for(int i = 0; i < queue_length ; i++){
            cout << queue1.front() << endl;
            queue1.pop();

            if(queue1.is_empty()){
                cout << "\nThe queue is empty.";
            }
        }

        //asking to run again
        cout << "Do you wanna run program again...??? (y/n) " << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}
