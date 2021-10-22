#ifndef JAIL_H
#define JAIL_H

#include "tile.h"
#include "player.h"
#include <string>

using namespace std;

class Player;


class Jail : public Tile {
public:
    Jail();
    Jail(string tileName);
    ~Jail();
    void onTile(Player* player, int i, int playercount);
    void goToJail(Player* player);




};


#endif //JAIL_H