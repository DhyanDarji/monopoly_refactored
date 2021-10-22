#include "tile.h"
#include "player.h"
#include <string>
#include <iostream>



Tile::Tile() {

    tileName = "";


}

Tile::Tile(string name) {

    tileName = name;


}




Tile::~Tile() {
    cout << tileName << " has been deleted!" << endl;
}

string Tile::get_name() {

    return tileName;

}

void goToJail(Player* player) {

}

void passStart(Player* player) {

}