#include <string>
#include "tile.h"
#include "start.h"
#include "player.h"

using namespace std;


Start::Start() {

    tileName = "";

}

Start::Start(string tileName) {
    this->tileName = tileName;
}

Start::~Start() {



}

void Start::onTile(Player* player, int i, int playercount) {
    cout << player->get_name() << " you have landed on Start!" << endl;

}

void Start::passStart(Player* player) {
    cout << "congratualtions for passing Go " << player->get_name() << "(" << player->get_number() << ") Centerlink awards you 200 AUD! " << endl;
    player->change_balance(200);

}