#ifndef PROPERTY_H
#define PROPERTY_H

#include "tile.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

class Player;

class Property : public Tile {

private:
    bool owned;

protected:
    int num_house, num_hotel;
    int increase;

public:
    string name;
    string original_name;
    int board_position;
    int price;
    //string *properties;
    int rent;
    int houseCount;
    int hotelCount;
    int housePrice;
    int hotelPrice;
    int ownerNumber;
    string property_owner;
    Property();
    Property(string name, float price, float rent, int board_position);
    ~Property();
    void add_value(int increase);
    //for some reason player object is not registering
    void buy_property(Player* buyer); //1
    void set_owner(Player* owner);//2
    void get_owner();
    void getRent(Player* player);//3
    void onTile(Player* player, int i, int playercount);
    void sellProperty(Player* players, int i, int playercount);
    void buyHouse(Player* p);
    void sellHouse(Player* p);
    void buyHotel(Player* p);
    void sellHotel(Player* p);

};


#endif