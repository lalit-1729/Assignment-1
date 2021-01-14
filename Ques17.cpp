#include <iostream>
using namespace std;

int main(){
    // having the input from the user
    string input_string;
    cout << "Enter a String; ";
    cin >> input_string;

    // counting the length of the input_string
    int input_string_length = 0;
    int index = 0;
    while(input_string[index] != '\0'){
        input_string_length++;
        index++;
    }

    // counting the frequency of characters
    int counting_array[200] = {0};
    int temp;
    for(index = 0; index < input_string_length ; index++){
        temp = input_string[index];
        counting_array[temp] += 1;
    }

    // finding the max frequency
    int temp_max;
    int maxNO = counting_array[0];
    for(int i = 0; i<200 ; i++){

        maxNO = max(maxNO, counting_array[i]);

        if(temp_max < maxNO){
            index = i;
        }

        temp_max = maxNO;

    }

    //printing the results
    cout << endl << "The character that occurs maximum time is: " << (char)(index) << ", which occurs for " << maxNO << " times.";

    return 0;
}
