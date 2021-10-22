#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "gameboard.h"
#include "property.h"
#include "player.h"
#include <iomanip>
#include <ctime>
using namespace std;

//makefile line
// test : test_main.cpp gameboard.cpp gameboard.h player.cpp player.h property.cpp property.h property.cpp property.h Tile.cpp Tile.h
//            clang++ test_main.cpp gameboard.cpp player.cpp property.cpp Tile.cpp -
//     std = c++ 11 - o test
//                            ./test

//==player objects==

// Player* players = new Player[2];
// players[1] = Player("p1", 1);
// players[0] = p1; players[1] = p2
// players[0] = Player("p1", 1);
// players[1] = Player("p2", 2);

//creating global properties outside of class so that they can be accessed for teting;

int main()
{

    //==testing player objects==
    Player p1("p1", 1);
    Player p2("p2", 2);
    //==game board class test==
    Board adelaide_monopoly;

    //==testing player class==
    p1.set_position();
    //rolls dice no expected output you rolled a number: range(1-12), actual: you rolled a number: 8

    p1.change_balance(200);
    //expected to add 200 dollars to account
    //no expected output as function does not print. should add 200 dollars to the player balance
    p1.InJail();
    p1.get_number();
    p1.aquire_property("property name");
    //expected to add property name to array;
    //expected: p1 owns: property name
    p1.show_properties();
    //expected: 0 (previous position)
    cout << p1.get_previous_position() << endl;
    //expected: 0 as previous position was start
    p1.set_position();
    cout << p1.get_position() << endl;
    //expected: random number range(1,8), actual =
    cout << p1.get_name() << endl;
    //expected p1, actual = p1
    cout << "player funds: ";
    cout << p1.get_balance() << endl;
    //expected: player funds: 1700
    //changing position yet again
    p1.set_position();
    //checking if previous position is traced
    cout << "previous position is: " << p1.get_previous_position() << endl;
    //now making a roll for the p2 player
    p2.set_position();

    //==testing gameboard class==
    //displaying board initially
    cout << "displaying board:" << endl;
    adelaide_monopoly.Display_Board();
    //passing through new player positions into the gameboard to output changes
    adelaide_monopoly.set_user_pos(p1);
    adelaide_monopoly.set_user_pos(p2);
    //displaying board to view changes
    adelaide_monopoly.Display_Board();

    //these card objects will go on the gamboard header

    // //Card *card1 = new Card("You got caught stealing from Burnside Village, go to jail!",1,0,5);
    // Card *card2 = new Card("Adelaide Uni awards you a game design prize foor OOP, collect a $500 dollar prize", 2, 500, 0);
    // Card *card3 = new Card("You skipped the line at Centerlink, you loose your 200 dollar allowance for passing start", 2, -200, 0);
    // Card *card4 = new Card("Great state vouchers award you 100 dollars for SA tourism, go have some fun!", 2, 100, 0);
    // Card *card5 = new Card("You fell asleep on an O-barn bus, whoops your final bus stop is START!", 1, 0, 0);
    // Card *card6 = new Card("Great state vouchers award you 100 dollars for SA tourism, go have some fun!", 2, 100, 0);

    // vector<Card *> cards;
    // //i can't seem to figure out why cards is an undeclared identifier when it is cleary declared here
    // cards.push_back(card1);
    // cards.push_back(card2);
    // cards.push_back(card3);
    // cards.push_back(card4);
    // cards.push_back(card5);
    // cards.push_back(card6);
    // //std::srand*(std::time(nullptr)); //set rand seed
    // int choice = std::rand() % card_count;
    // //alternative syntax used to flex programming skills XD
    // //*(cards+choice)->activate_card(Players,adelaide_monopoly,i);
    // cards[choice]->activate_card(Players, adelaide_monopoly, i);
    // // Chance.ontile(Players,i,playercount);
}
