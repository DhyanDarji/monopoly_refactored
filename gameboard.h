
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

//#include "space.h"
//#include "move_action.h"
#include "tile.h"
#include "player.h"
#include <iomanip>
#include <vector>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;

//we need to use forward declaration. This is important due to the order of object calls

class Board
{
public:
	//this needs to be of type property * so we can properly use our virtual functions in the tile class
	//virtual functions only work for pointers
	Board();
	//std::vector<Tile*> tiles;
	//since properties inherets tiles it all should be accessible from

	vector<Tile*> tiles;
	vector<string>* user_pos = new vector<string>(20);
	int variable;
	int player_count;
	//class methods
	void make_move(Player* players);
	void set_user_pos(Player player);
	void Display_Board();
	~Board();
	// void player_position(string player);
	// int rollDice();

	//create players should be done in the main function, not in our gameboard class.
	// Player* createPlayers(int numPlayers);
	// Player* playerList;
};
#endif