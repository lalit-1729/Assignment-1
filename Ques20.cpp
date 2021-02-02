// abstract class

#include <iostream>
#include <stdlib.h>
using namespace std;

bool is_input_valid(string user_input){
    for(int i = 0; user_input[i] != '\0' ; i++){
        //Using the ASCII code for validation
        if(user_input[i] < 48 || user_input[i] > 57){
            if(user_input[i] == '-'){
                continue;
            }
            return false;
        }
    }
    return true;
}

int take_input_n_validate(){
    string user_input;
    cout << "Who are you...??? 0 for Batsman/ 1 for Bowler/ (-1) for WicketKeeper: ";
    cin >> user_input;

    while(is_input_valid(user_input) == false ||
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
    string player_name;
    float runs;
    int matches;
    int balls_faced;

    virtual string role() = 0; //pure virtual function
    virtual string name() = 0; //pure virtual function
    virtual float compute_average() = 0; //pure virtual function
    virtual float compute_strike_rate() = 0; //pure virtual function;

    void setName(){
        cout << "Enter the " << this -> role() << "'s first name only: ";
        cin >> player_name;
    }

    void getRuns(){
        cout << "Enter the player's run:" << endl;
        cin >> this -> runs;
    }

    void getMatches(){
        cout << "Enter the player's matches played: " << endl;
        cin >> this -> matches;
    }

    void getBalls(){
        cout << "Enter the balls faced by the player: " << endl;
        cin >> this ->balls_faced;
    }

};


// Below are the derived class

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
    cout << obj.role() << "-> " << obj.name() << "'s strike rate is: "<< obj.compute_strike_rate();
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
        cout << "\n\n\t\t :: Example Of Abstract Class ::\n\n";

        int query = take_input_n_validate();
        cout << endl << endl;

        // try to enter genuine data to have genuine output
        if(query == 1){
            get_bowlers_detail();
        }
        else if(query == 0){
            get_batsman_details();
        }
        else{
            get_wicketkeepers_details();
        }

    }while(want_to_run_again() == true);

    return 0;
}
