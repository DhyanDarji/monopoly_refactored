#include <string>
#include <algorithm>
#include "tile.h"
#include "property.h"
#include "player.h"

using namespace std;
// Property default constructor


//the inheretance is done int he main header
Property::Property() :Tile()
{
    owned = false;
    num_house = 0;
    num_hotel = 0;
    price = 0;
    rent = 0;
    board_position = 0;
    houseCount = 0;
    hotelCount = 0;
    housePrice = 0;
    hotelPrice = 0;
}

Property::~Property() {
    cout << name << " has been deleted! " << endl;
}


// Property Constructor with name, price and rent
Property::Property(string name, float price, float rent, int board_position) :Tile(name)
{
    owned = false;
    num_house = 0;
    num_hotel = 0;
    //this pointer avoids issue of having name = name
    this->name = name;
    this->rent = rent;
    this->price = price;
    original_name = name;
    property_owner = "none";
    this->board_position = board_position;
    houseCount = 0;
    hotelCount = 0;
    housePrice = 50;
    hotelPrice = 100;
}



//we want to change the value of the property as more houses are added. This is because houses pertain value. 
void Property::add_value(int increase) {
    rent += increase;
    //this should be in the hotel class
}

void Property::buy_property(Player* buyer)
{
    string input;
    cout << "Would you like to buy " << tileName << " for " << price << " dollars? yes/no" << endl;

    cin.clear(); //clears input

    cin.ignore(256, '\n');

    getline(cin, input);

    cout << input << "1" << endl;

    while (input != "no" && input != "yes")
    {
        cout << "please type yes or no only" << endl;
        // cin.clear(); //clears input
        // cin.ignore(256, '\n');
        getline(cin, input);
    }

    // if(input == "yes"){
    if (input.compare("yes") == 0 && buyer->playerBalance > price)
    {
        //if player chooses yes to buy property:
        //setting the player to be the owner of the property
        set_owner(buyer);
        //puts the property to the players bank account

        buyer->aquire_property(tileName);
        //
        owned = true;
        property_owner = buyer->get_name();
        //this line of code adds the buyers number next to the name on the board so that we can see owns the property
       //this is where we access title
        name += "  P" + to_string(buyer->get_number());

        return;
    }
    if (input == "no")
    {
        cout << "You chose not to buy this property" << endl;
    }

}

// Function to set owner. //this should be integrated with function on line 25 to be all in one to avoid errors.
void Property::set_owner(Player* owner)
{
    //concatenating the player number to the board so that we can see who owns that property
    //we need to typecast int to string before we add it to the
    //==WARNING cause of segmentation fault is this line, fix! or don't use dynamic array
    //properties[board_position]+= " "+std::to_string(owner.get_number());
    cout << "board position is " << board_position << endl;
    //I am struggling to figure out how to make the dynamic array global in all files so I can access the properties array here so I can append the player number
    //cout<<properties<<endl;
    //cout<<properties[board_position]<<endl;
    //properties[board_position]+= to_string(owner.get_number());

    property_owner = owner->get_name();
    //prints out saves player  number who owns the property.
    ownerNumber = owner->get_number();
    cout << "CONGRATULATIONS " << property_owner << " now owns " << tileName << " purchased for " << price << " dollars. " << endl
        << endl;
    //cout << "CONGRATULATIONS " << property_owner << " now owns " << property_name << " purchased for " << price << " dollars. " << endl;
    owned = true;
    return;
}

//gets if a player is ontile
void Property::getRent(Player* player)
{
    int owner_number = player->get_number();

    //checking if the property i owned and the owner of the property is a different player (i.e player number is different)

    if (owned && ownerNumber != player->get_number())
    {

        int price_payed = -rent; //our current system enables the player to get into debt.
        cout << player->get_name() << "pays " << -rent << " dollars in rent " << endl;
        player->change_balance(-rent);
        cout << " your account now has " << player->get_balance() << " dollars " << endl;
        get_owner();
    }

    // void Property::ontile(Player player) {
    //     int owner_number = player.get_number();
    //     //checking if the property i owned and the owner of the property is a different player (i.e player number is different)
    //     if (owned && property_owner != player.get_name()) {
    //         int price_payed = -rent; //our current system enables the player to get into debt.
    //         cout << player.get_name() << "pays " << -rent << " dollars in rent " << endl;
    //         player.change_balance(rent);
    //         cout << " your account now has " << player.get_balance() << " dollars " << endl;

    //     }
    // }
}

void Property::get_owner()
{
    cout << "this property is owned by " << property_owner << endl;
}
//this function could be useful to add later to get the name of the property instantiated.



//on tile is one of our most important methods. It decides what to do with the player objects once a player lands on a tile.
//i refers to the the player num and is the index of the array
//gets is a player is also on tile; 
//player count gets the number of players
void Property::onTile(Player* players, int i, int playercount) {
    //the i = is just a test to see if the numbers are the same. Since they are, it is obselte to pass through in i in the function.
    //cout<<players[i].get_name()<<" who is "<<i+1<<" = " << players[i].get_number()<<" has landed on "<<property_name<<endl;
    cout << players[i].get_name() << " who is p" << players[i].get_number() << " has landed on " << tileName << endl;
    if (owned == false) {
        //buying a property 
        //this functions handles everything as it is coupled with other functions
        buy_property(&players[i]);
        return;
    }
    //if the player lands on someone elses property
    if (owned == true && ownerNumber != players[i].get_number()) {
        //displaying owner
        get_owner();
        getRent(&players[i]);
        return;
    }
    //if the player lands on their own property!
    if (owned == true && ownerNumber == players[i].get_number()) {
        //displaying owner
        //calling house class here and creating a house object which increases rent;
        cout << "you already own this property!" << endl;
        cout << "type 'BUY' to buy a house/hotel or type 'SELL' to sell property/house/hotel otherwise press enter to continue" << endl;

        string sell;

        cin.clear(); //clears input

        cin.ignore(256, '\n');

        getline(cin, sell);

        while (sell != "SELL" && sell != "BUY") {

            cout << "Invalid input!" << endl;
            cout << "type 'BUY' to buy a house/hotel or type 'SELL' to sell property/house/hotel otherwise press 1 to continue" << endl;

            cin.clear(); //clears input

            cin.ignore(256, '\n');

            getline(cin, sell);

        }



        if (sell == "SELL") {

            cout << "Do you want to sell your property, house or hotel?" << endl;
            cout << "type 'PROPERTY' to sell property, 'HOUSE' to sell house and 'HOTEL' to sell hotel" << endl;
            cout << "Hit enter to exit" << endl;

            string check;

            cin.clear();

            cin.ignore(256, '\n');

            getline(cin, check);

            while (check != "PROPERTY" && check != "HOUSE" && check != "HOTEL" && check[0] != '1') {

                // cin.clear();

                // cin.ignore(256, '\n');

                cout << "Invalid entry, try again!" << endl;

                cout << "type 'PROPERTY' to sell property, 'HOUSE' to sell house and 'HOTEL' to sell hotel" << endl;

                cout << "Hit 1 to exit" << endl;

                getline(cin, check);

            }

            if (check == "PROPERTY") {
                sellProperty(players, i, playercount);
            }

            if (check == "HOUSE") {
                if (houseCount == 0) {
                    cout << "You can't sell a house you don't own!" << endl;
                    cout << "You will be returned" << endl;

                }
                else {
                    sellHouse(&players[i]);
                }
            }

            if (check == "HOTEL") {
                if (hotelCount == 0) {
                    cout << "You can't sell a hotel you don't own!" << endl;
                    cout << "You will be returned" << endl;
                }
                else {
                    sellHotel(&players[i]);
                }
            }



        }

        if (sell == "BUY") {

            string buy;
            cout << "Type 'HOUSE' to buy a house, 'HOTEL' to buy a hotel or 1 to exit" << endl;

            cin.clear(); //clears input

            cin.ignore(256, '\n');

            getline(cin, buy);

            while (buy != "HOUSE" && buy != "HOTEL" && buy[0] != '1') {

                // cin.clear(); //clears input

                // cin.ignore(256, '\n');

                cout << "invalid input!" << endl;
                cout << "Type 'HOUSE' to buy a house, 'HOTEL' to buy a hotel or enter to exit" << endl;


                getline(cin, buy);

            }

            if (buy == "HOUSE") {

                buyHouse(&players[i]);

            }

            if (buy == "HOTEL") {
                buyHotel(&players[i]);
            }

        }


        return;

    }



}

//player_num
void Property::sellProperty(Player* players, int i, int playercount)
{

    int maxPrice;

    bool bought = false;
    string input = "";

    //creating a boolean array to store the interested buyers
    bool* interestedBuyer = new bool[playercount];

    for (int j = 0; j < playercount; j++) {
        interestedBuyer[j] = true;
    }

    int count = 0;

    //stores the value of the auction offer in monoply money. The highest bidder will win
    int offer;

    int accept;
    //creating an auction system, bought determines if the property is bought
    while (bought == false) {

        for (int j = 0; j < playercount; j++) {

            if (players[j].get_number() != ownerNumber && interestedBuyer[j] == true) {

                cout << players[j].get_name() << "(" << players[j].get_number() << ") Enter a offer for " << tileName << "if you wish to not purchase enter 0 " << endl;

                while (!(cin >> offer)) {
                    cin.clear(); //clears input

                    cin.ignore(256, '\n');

                    cout << "Input a valid number!" << endl;
                }

                if (offer < players[j].playerBalance) {
                    cout << players[j].get_name() << "(" << players[j].get_number() << ") you have entered an offer that is more than the money you have, you cannot buy this!" << endl;
                    interestedBuyer[j] = false;
                }

                while (offer <= 0) {
                    cout << "Enter a valid offer!" << endl;
                    cout << players[j].get_name() << "(" << players[j].get_number() << ") Enter a offer for " << tileName << "if you wish to not purchase enter 0 " << endl;
                }

                if (offer == 0) {
                    interestedBuyer[j] = false;
                }

                cout << property_owner << "(" << ownerNumber << ")" << " you have received an offer for " << offer << " type 'yes' type 'no' to cancel" << endl;

                cin.clear(); //clears input

                cin.ignore(256, '\n');


                getline(cin, input);

                while (input != "yes" || input != "no")
                    cout << "Type yes or no only please" << endl;
                cin >> input;
            }

            if (input == "yes")
                accept = 1;
            else if (input == "no")
                accept = 0;


            while (accept != 0 || accept != 1) {
                cout << "Invalid answer!" << endl;
                cout << property_owner << "(" << ownerNumber << ")" << " you have received an offer for " << offer << " type 'yes' type 'no' to cancel" << endl;
                cin >> input;
                if (input == "yes")
                    accept = 1;
                else if (input == "no")
                    accept = 0;
            }

            if (accept == 1) {
                cout << "Congrats " << players[j].get_name() << " you have bought the property for " << offer << endl;
                set_owner(&players[j]);
                players[j].change_balance(-offer);
                players[i].change_balance(offer);
                name = original_name;
                ownerNumber = players[j].get_number();
                players[i].properties_owned.erase(remove(players[i].properties_owned.begin(), players[i].properties_owned.end(), tileName), players[i].properties_owned.end());
                players[j].properties_owned.push_back(tileName);
                bought = true;

            }
        }
        count++;

        if (count == 3) {
            break;
        }
    }

    if (count == 3) {

        cout << "Nobody wishes to buy the property or you are receiving bad prices, the government will now buy at price bought" << endl;
        players[i].properties_owned.erase(remove(players[i].properties_owned.begin(), players[i].properties_owned.end(), tileName), players[i].properties_owned.end());
        ownerNumber = 0;
        owned = false;
        name = original_name;
        players[i].change_balance(price);

    }

}

void Property::buyHouse(Player* p) {

    if (p->get_balance() < housePrice) {
        cout << "You don't have enough money for a house, you need 50!" << endl;
        return;
    }
    else if (houseCount == 4) {
        cout << "You cannot build anymore houses, maximum number of houses is 4!" << endl;
        return;
    }
    else {
        houseCount++;
        p->change_balance(-housePrice);
        rent = rent * 1.1;
        cout << "Congrats " << p->get_name() << "(" << p->get_number() << ")  you now have a house!" << endl;
        cout << "Your rent has increased by 10%!" << endl;
        return;

    }

}

void Property::sellHouse(Player* p) {

    houseCount--;
    p->change_balance(housePrice * 0.9);
    cout << "You have sold your house, you will get paid " << 0.9 * housePrice << endl;
    cout << p->get_name() << "(" << p->get_number() << ") your balance is now $" << p->get_balance() << endl;

}

void Property::buyHotel(Player* p) {

    if (p->get_balance() < hotelPrice) {
        cout << "You don't have enough money for a hotel, you need 100!" << endl;
        return;
    }

    if (houseCount != 4) {
        cout << "You cannot buy a hotel if you do not have 4 houses!" << endl;
        cout << "Do you wish to buy a house?" << endl;
        cout << "'YES to buy a house, 1 to return" << endl;
        string command;

        cin.clear(); //clears input

        cin.ignore(256, '\n');

        getline(cin, command);

        while (command != "YES" && command[0] != '1') {

            // cin.clear(); //clears input

            // cin.ignore(256, '\n');

            cout << "Invalid entry" << endl;

            cout << "Do you wish to buy a house?" << endl;
            cout << "'YES to buy a house, 1 to return" << endl;

            getline(cin, command);

        }

        if (command == "YES") {
            buyHouse(p);
        }
        return;
    }
    else {
        hotelPrice++;
        p->change_balance(-hotelPrice);
        rent = rent * 1.2;
        cout << "Congrats " << p->get_name() << "(" << p->get_number() << ")  you now have a hotel!" << endl;
        cout << "Your rent has increased by 20%!" << endl;
        cout << p->get_name() << "(" << p->get_number() << ") your balance is now $" << p->get_balance() << endl;

        return;

    }

}

void Property::sellHotel(Player* p) {

    hotelCount--;
    p->change_balance(hotelPrice * 0.9);
    cout << "You have sold your house, you will get paid " << 0.9 * housePrice << endl;
    cout << p->get_name() << "(" << p->get_number() << ") your balance is now $" << p->get_balance() << endl;

}

