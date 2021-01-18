// abstract class

#include <iostream>
#include <stdlib.h>
using namespace std;

// base class = CricketPlayer
class CricketPlayer{
private:


public:
    string player_name;
    float runs;
    int matches;
    int balls_faced;

    virtual string role() = 0; // virtual function
    virtual string name() = 0; // virtual function
    virtual float compute_average() = 0; // virtual function
    virtual float compute_strike_rate() = 0; // virtual function;

    void setName(){
        cout << "Enter the " << this -> role() << "'s only first name: ";
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
        return "BatsMan";
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


int main(){
    int query;
    cout << "Who are you...??? Batsman-0/ Bowler-1/ WicketKeeper -(-1): ";
    cin >> query;
    // try to enter genuine data to have genuine output
    if(query == 1){
        Bowler obj;
        obj.setName();
        obj.getRuns();
        obj.getMatches();
        obj.getBalls();
        cout << obj.role() << "-> " << obj.name() << "'s average is: "<< obj.compute_average()<< endl;
        cout << obj.role() << "-> " << obj.name() << "'s strike rate is: "<< obj.compute_strike_rate();
    }

    else if(query == 0){
        Batsman obj;
        obj.setName();
        obj.getRuns();
        obj.getMatches();
        obj.getBalls();
        cout << obj.role() << "-> " << obj.name() << "'s average is: "<< obj.compute_average()<< endl;
        cout << obj.role() << "-> " << obj.name() << "'s strike rate is: "<< obj.compute_strike_rate();
    }

    else if(query == -1){
        WicketKeeper obj;
        obj.setName();
        obj.getRuns();
        obj.getMatches();
        obj.getBalls();
        cout << obj.role() << "-> " << obj.name() << "'s average is: " << obj.compute_average()<< endl;
        cout << obj.role() << "-> " << obj.name() << "'s strike rate is: "<< obj.compute_strike_rate();
    }

    return 0;
}
