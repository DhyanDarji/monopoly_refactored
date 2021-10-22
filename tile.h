#ifndef TILE_H
#define TILE_H


#include "player.h"
#include <string>
using namespace std;
class Player;

class Tile {
public:
    Tile();
    Tile(string name);
    ~Tile();
    string get_name();
    string tileName;
    virtual void onTile(Player* player, int i, int playercount) = 0;
    virtual void goToJail(Player* player);
    virtual void passStart(Player* player);
};


#endif //TILE_H
