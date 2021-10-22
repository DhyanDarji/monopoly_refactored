#include "gameboard.h"
#include "tile.h"
#include "property.h"
#include "jail.h"
#include "start.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;

//as Property inherets tile we can go property->tile_method() and it should be able to access all the features of the tile
// default constructor
Board::Board()
{
    //creating player objects in board constructor
    // these go in board class
    //if we want to use vector<Property*> properties;
    // Property *property1 = new adelaide_uni("Adelaide Uni", 200, 40, 1);
    // properties.push_back(property1);
    //we need to change this to tile and have property objects pointing to the tile objects
    //Property AdelaideUni(rent,owner,number) = &adelaideUni_tile_object
    //AdelaideUni-> do_something

    //this needs to be tile now
   // Tile* p1 = new Tile("Start", 0, 0, 0);

    Tile* p1 = new Start("Start");
    //these remain properties because they are properties
    Tile* p2 = new Property("Adelaide Uni", 200, 40, 1);
    Tile* p3 = new Property("Flinders Uni", 150, 20, 2);
    Tile* p4 = new Property("UNISA", 155, 22.5, 3);
    Tile* p5 = new Property("TAFE", 160, 25, 4);
    //Jail* p16 = new Jail("jail", 0, 0, 165);
    Tile* p6 = new Jail("Jail");
    Tile* p7 = new Property("Mount Lofty", 250, 50, 6);
    Tile* p8 = new Property("Mount Osmond", 225, 45, 7);
    Tile* p9 = new Property("Morialta Falls", 230, 46.5, 8);
    Tile* p10 = new Property("Linear Park Trail", 245, 47, 9);
    Tile* p11 = new Property("Chance", 0, 0, 10);
    Tile* p12 = new Property("Burnside Village", 225, 45, 11);
    Tile* p13 = new Property("Norwood Parade", 185, 30, 12);
    Tile* p14 = new Property("Rundel Mall", 300, 70, 13);
    Tile* p15 = new Property("Tea Tree Plaza", 280, 60, 14);
    //this should be part of the jail class
    //Jail* p16 = new Jail("go to jail", 0, 0, 165);
    Tile* p16 = new Jail("Go to jail");
    Tile* p17 = new Property("RAH Hospital", 380, 80, 16);
    Tile* p18 = new Property("Adelaide Oval", 400, 70, 17);
    Tile* p19 = new Property("St Bernards", 420, 50, 18);
    Tile* p20 = new Property("Hindley club", 420, 50, 18);

    tiles.push_back(p1);
    tiles.push_back(p2);
    tiles.push_back(p3);
    tiles.push_back(p4);
    tiles.push_back(p5);
    tiles.push_back(p6);
    tiles.push_back(p7);
    tiles.push_back(p8);
    tiles.push_back(p9);
    tiles.push_back(p10);
    tiles.push_back(p11);
    tiles.push_back(p12);
    tiles.push_back(p13);
    tiles.push_back(p14);
    tiles.push_back(p15);
    tiles.push_back(p16);
    tiles.push_back(p17);
    tiles.push_back(p18);
    tiles.push_back(p19);
    tiles.push_back(p20);
    //adding properties to a property array
    // properties.push_back(AdelaideUni);
    // properties.push_back(FlindersUni);
    // properties.push_back(UniSA);
    // properties.push_back(TAFE);
    // properties.push_back(Jail);
    // properties.push_back(MountLofty);
    // properties.push_back(MountOsmond);
    // properties.push_back(MorialtaFalls);
    // properties.push_back(LinearParkTrail);
    // properties.push_back(BurnsideVillage);
    // properties.push_back(NorwoodParade);
    // properties.push_back(RundelMall);
    // properties.push_back(TTP);
    // properties.push_back(RAH);
    // properties.push_back(AdelaideOval);
    // properties.push_back(StBernards);
    // we actually need to pass this property array into other functions for it to be used
    //cout << "default constructor called" << endl;

}
// sets user position on gameboard by modifying array
// we could later integrate this function elsewhere with set_position() in player class

//most of the main classes are being moved into the gameboard classes

Board::~Board() {

    cout << "Game has ended!" << endl;

}


void Board::make_move(Player* players) {
    int game_conclude = 0;
    int control;

    while (game_conclude != player_count)
    {
        system("clear");
        game_conclude = 0;
        for (int i = 0; i < player_count; i++)
        {
            cout << "Its " << players[i].get_name() << "'s turn!" << endl;
            cout << "1: Roll Dice " << endl;
            cout << "2: End Game " << endl;


            while (!(cin >> control)) {

                cin.clear(); //clears input
                //ignoires everything up to a \n until we reach a new l ine
                cin.ignore(256, '\n');

                cout << "Invalid Entry! Try again" << endl;
                cout << "Press 1 to roll the dice" << endl;
                cout << "Press 2 to End Game " << endl;
            }

            if (control == 2)
            {
                game_conclude++;
            }

            //rolls the dice;
            //dice integrated into set position
            if (players[i].position == 10) {
                set_user_pos(players[i]);
                Display_Board();

            }
            else {
                players[i].set_position(tiles);

                set_user_pos(players[i]);


                Display_Board();
            }

            //temporary fix to stop user from buying jail or start

            //we need to have an if statement to account for the other classes
            if (players[i].get_position() == 15) {
                tiles[15]->goToJail(&players[i]);
                tiles[players[i].get_position()]->onTile(players, i, player_count);
            }
            else {
                tiles[players[i].get_position()]->onTile(players, i, player_count);

            }




        }
        this_thread::sleep_for(chrono::seconds(2));

    }
}

void Board::set_user_pos(Player player) {
    // changing old position
    int prev_pos = player.get_previous_position();
    (*user_pos)[prev_pos] = "";
    // now updating new position
    int pos = player.get_position();

    // updating old position by setting (*properties) index to be empty
    switch (player.get_number())
    {
    case 1:
        // we want to concatenate player position to either empty or prexisting index incase multiple players are on the same square.
        // the fix for this error is complex: https://stackoverflow.com/questions/56962047/c-error-no-operator-matches-these-operand'
        (*user_pos)[pos] += " p1";
        break;
    case 2:
        (*user_pos)[pos] += " p2";
        break;
    case 3:
        (*user_pos)[pos] += " p3";
        break;
    case 4:
        (*user_pos)[pos] += " p4";
        break;
    case 5:
        (*user_pos)[pos] += " p5";
        break;
    case 6:
        (*user_pos)[pos] += " p6";
        break;
    }
};

void Board::Display_Board() {

    cout << " ===========================================================================================================================================" << endl;
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        //we want to format the name of the property/tile and get_the name from the object

        cout << left << setw(20) << tiles[i]->get_name() << "|  "; //CHECK HERE!!
    }
    cout << endl;
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        cout << left << setw(20) << (*user_pos)[i] << "|  ";
    }
    cout << endl;
    cout << " ===========================================================================================================================================" << endl;

    for (int i = 0; i < 4; i++)
    {
        // we add numbers for formatting. They seem random but they actually correspond to the amount of spaces needed for the properties to line up.

        cout << " |  " << setw(20) << tiles[19 - i]->get_name() << "|"
            << setw(92) << ""
            << "| " << setw(20) << tiles[i + 6]->get_name() << "|" << endl;
        cout << " |  " << setw(20) << (*user_pos)[19 - i] << "|"
            << setw(92) << ""
            << "| " << setw(20) << (*user_pos)[i + 6] << "|  " << endl;
        if (i == 3)
        {
            cout << " ===========================================================================================================================================" << endl;
        }
        else
            cout << " ========================                                                                                            =======================" << endl;
    }
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        cout << setw(20) << tiles[15 - i]->get_name() << "|  ";
    }
    cout << endl;
    cout << " |  ";
    for (int i = 0; i <= 5; i++)
    {
        cout << setw(20) << (*user_pos)[15 - i] << "|  ";
    }
    cout << endl;
    cout << " ===========================================================================================================================================" << endl;
};
// roll dice should be a function in the main. Perhaps it could be in the gameboard class
// int Board::rollDice()
// {
//     int dice_roll = rand() % 12 + 1;
//     return dice_roll;
// }
