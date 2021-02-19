//This program provides and example of abstract class
//Abstract class
/*By definition, an abstract class in C++ is a class that has at least one pure virtual function
  (i.e., a function that has no definition). The classes inheriting the abstract class must provide
  a definition for the pure virtual function; otherwise, the subclass would become an abstract class itself.*/
//Pure Virtual function
/*A virtual function is a member function which is declared within a base class and
  is re-defined ( Over ridden ) by a derived class. */


#include <iostream>
#include <stdlib.h>
using namespace std;

void refresh_screen(){
    system("cls"); //To clear the Console window
    cout << "\n\n\t\t :: Example Of Abstract Class ::\n\n";
}

int string_length(string user_input){
    int string_size = 0;
    while(user_input[string_size] != '\0'){
         string_size++;
    }
    return string_size;
}

/* Similar to that of 'strcmp' function of string.h, here we are comparing every single character of both string
   this function will will used later in the program run-again loop for input validation */
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

bool is_input_numeric(string user_input){
    int i = 0;
    if(user_input[i] == '-')
        i++;

    for( i ; user_input[i] != '\0' ; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57)
            return false;
    }
    return true;
}



int ask_who_are_you(){
    string user_input;
    cout << "Who are you...??? 0 for Batsman/ 1 for Bowler/ (-1) for WicketKeeper: ";
    cin >> user_input;

    while(!is_input_numeric(user_input)||
           !(stoi(user_input) == 1 ||
             stoi(user_input) == 0 ||
             stoi(user_input) == -1))
        {
        cout << "Invalid Input, please try again with a valid one:\n";
        cout << "Who are you...??? 0 for Batsman/ 1 for Bowler/ (-1) for WicketKeeper: ";
        cin >> user_input;
    }
    return stoi(user_input);
}

// base class = CricketPlayer
class CricketPlayer{
public:
    string message; //This string will later be used to in other function
    string player_name;
    float runs;
    int matches;
    int balls_faced;

    virtual string role() = 0; //pure virtual function
    virtual string name() = 0; //pure virtual function
    virtual float compute_average() = 0; //pure virtual function
    virtual float compute_strike_rate() = 0; //pure virtual function;

    /*in case the user enters invalid data, function here declared is used to validate the input,
      it is using ASCII character to verify whether it is numeric or not.*/
    bool is_input_numeric(string user_input){
        for(int i=0 ; user_input[i] != '\0' ; i++){
            //Using the ASCII code for validation
            if(user_input[i] < 48 || user_input[i] > 57)
                return false;
        }
        return true;
    }

    /*this function used to take input for non-negative quantity likes runs scored,
      matches played, balls played,etc. */
    int take_non_negative_input(string message){
        string user_input;
        cout << message;
        cin >> user_input;

        while(!is_input_numeric(user_input)){
            cout << "Invalid Input, please try again with a valid one:\n";
            cout << message;
            cin >> user_input;
        }
        return stoi(user_input);
    }

    void setName(){
        cout << "\nEnter the " << this -> role() << "'s first name only: ";
        cin >> this->player_name ;
    }

    void getRuns(){
        this -> runs = take_non_negative_input("\nEnter the player's run: ") ;
    }

    void getMatches(){
        this -> matches = take_non_negative_input("\nEnter the player's matches played: ");
    }

    void getBalls(){
        this ->balls_faced = take_non_negative_input("\nEnter the balls faced by the player: ");
    }

};


// Below are some the derived class
/*if the pure virtual function is not overridden in the derived class,
  then the derived class also becomes an Abstract class*/

// derived class = Batsman
class Batsman: public CricketPlayer{
public:
    string name(){
        return player_name;
    }

    string role(){
        return "BatsMan";
    }

    float compute_average(){
        return runs/matches;
    }

    float compute_strike_rate(){
        return runs*100/balls_faced;
    }
};

// derived class = Bowler
class Bowler: public CricketPlayer{
public:
    string name(){
        return player_name;
    }

    string role(){
        return "Bolwer";
    }

    float compute_average(){
        return runs/matches;
    }

    float compute_strike_rate(){
        return runs*100/balls_faced;
    }
};

// derived class
class WicketKeeper: public CricketPlayer{
public:
    string name(){
        return player_name;
    }

    string role(){
        return "WicketKeeper";
    }

    float compute_average(){
        return runs/matches;
    }

    float compute_strike_rate(){
        return runs*100/balls_faced;
    }
};

void get_bowlers_detail(){
    Bowler obj;
    obj.setName();
    obj.getRuns();
    obj.getMatches();
    obj.getBalls();
    cout << obj.role() << "-> " << obj.name() << "'s average is: "<< obj.compute_average()<< endl;
    cout << obj.role() << "-> " << obj.name() << "'s strike rate is: "<< obj.compute_strike_rate();
}

void get_batsman_details(){
    Batsman obj;
    obj.setName();
    obj.getRuns();
    obj.getMatches();
    obj.getBalls();
    cout << obj.role() << "-> " << obj.name() << "'s average is: "<< obj.compute_average()<< endl;
    cout << obj.role() << "-> " << obj.name() << "'s strike rate is: "<< obj.compute_strike_rate();
}

void get_wicketkeepers_details(){
    WicketKeeper obj;
    obj.setName();
    obj.getRuns();
    obj.getMatches();
    obj.getBalls();
    cout << obj.role() << "-> " << obj.name() << "'s average is: " << obj.compute_average()<< endl;
    cout << obj.role() << "-> " << obj.name() << "'s strike rate is: "<< obj.compute_strike_rate() << endl;
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
        int query = ask_who_are_you();
        cout << endl << endl;

        // try to enter genuine data to have genuine output
        if(query == 1)
            get_bowlers_detail();
        else if(query == 0)
            get_batsman_details();
        else
            get_wicketkeepers_details();

        want_to_run_again(&continue_program);

    }while( continue_program[0] == 'y' || continue_program[0] == 'Y' );
    cout << "\n\n\t\tYOU HAVE QUIT THE PROGRAM....!!!\n";
}
