#include "jail.h"
#include "tile.h"
#include "player.h"
#include "string"
#include <random>
#include <iostream>



using namespace std;

Jail::Jail() {
    tileName = "";
}

Jail::Jail(string tileName) {
    this->tileName = tileName;

}

Jail::~Jail() {


}

void Jail::onTile(Player* player, int i, int playercount) {
    string input;

    player->in_jail = true;

    cout << "you are in jail, either pay a 400 dollar bail or roll a two of the same numbers" << endl;
    cout << "would you like to pay the bail? yes/no" << endl;
    cin.clear();
    cin.ignore(256, '\n');
    getline(cin, input);


    while (input != "yes" && input != "no") {
        cout << "please type yes or no only" << endl;
        getline(cin, input);


    }

    if (input == "yes") {
        if (player->get_balance() >= 400) {
            player->change_balance(-400);
            cout << "congratulations you are out of jail via the bail" << endl;
            cout << "your account now has " << player->get_balance() << " dollars" << endl;
            player->in_jail = false;
            return;
        }
        else {
            cout << "unfortunately you can't afford the bail" << endl;
        }
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 7);
        int roll_1 = dist6(rng);
        int roll_2 = dist6(rng);

        cout << "you rolled a " << roll_1 << " and a " << roll_2 << endl;
        if (roll_1 == roll_2) {
            cout << "congratulations you are out of jail and will be free from your next turn!" << endl;
            player->in_jail = false;
            return;
        }
        else
        {
            cout << "Unlucky, you aren't free yet!" << endl;
        }
    }

}

void Jail::goToJail(Player* player) {

    player->position = 5;


}