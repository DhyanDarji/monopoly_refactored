#ifndef PLAYER_H
#define PLAYER_H
#include "tile.h"
#include "gameboard.h"
#include <string>
#include <vector>
#include <ctime>
//#include "gameboard.h"
using namespace std;
class Tile;
//Player  
class Player {
    // private:
    //     int roll_1;
    //     int roll_2;
    //we want to fix this if it is unecessary
protected:
    int player_num;

public:
    //variables

    vector <string> properties_owned;
    string playerName;

    int position;
    int playerBalance;
    int previous_position;
    bool in_jail;

    //class methods
    Player(string Name, int num);
    Player();
    ~Player();
    void InJail();
    int get_number();
    //this is a very important function that needs to be called when a player lands on the property
    void get_properties(vector<Tile*>& tiles);
    void aquire_property(string name);
    void show_properties();
    int get_previous_position();
    //makes a move for the player
    void set_position(vector<Tile*>& tiles);
    int get_position();
    string get_name();
    int get_balance();
    void change_balance(int balance);
};

#endif //PLAYER_H