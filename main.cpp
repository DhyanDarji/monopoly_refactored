#include <iostream>
#include <vector>
#include <string>
// #include "card.h"
// #include "tile.h"
// #include "gameboard.h"
// #include "property.h"
// #include "player.h"
#include "player.h"
#include "gameboard.h"
#include <iomanip>
//added this library for random 
#include <ctime>
//#include <ncurses.h>
using namespace std;

//START
// 1. Adelaide Uni
// 2. Flinders Uni
// 3. UNISA
// 4. TAFE
// 5. JAIL
// 6. Mount Lofty
// 7. Mount Osmond
// 8. Morialta Falls
// 9. Linear Park trail
// 10. Chance
// 11. Burnside Village
// 12. Norwood Parade
// 13. Rundel Mall
// 14. Tea tree Plaza
// 15. Got to Jail
// 16. RAH Hospital
// 17. Adelaide Oval
// 18. St Bernards F & V
// 19. Hindley Club


//creating a gameboard

// //call: :Property(string name, float price, float rent)
// Property Start("collect 300", 0, -300, 0);
// Property AdelaideUni("Adelaide Uni", 200, 40, 1);
// Property FlindersUni("Flinders Uni", 150, 20, 2);
// Property UniSA("UNISA", 155, 22.5, 3);
// Property TAFE("TAFE", 160, 25, 4);
// Property Jail("Jail", 0, 200, 5);
// Property MountLofty("Mount Lofty", 250, 50, 6);
// Property MountOsmond("Mount Osmond", 225, 45, 7);
// Property MorialtaFalls("Morialta Falls", 230, 46.5, 8);
// Property LinearParkTrail("Linear Park Trail", 245, 47, 9);
// Property Chance("Chance", 0, 0, 0);
// Property BurnsideVillage("Burnside Village", 225, 45, 11);
// Property NorwoodParade("Norwood Parade", 185, 30, 12);
// Property RundelMall("Rundel Mall", 300, 70, 13);
// Property TTP("Tea Tree Plaza", 280, 60, 14);
// Property GoToJail("Go To Jail", 0, 0, 0);
// Property RAH("RAH Hospital", 320, 80, 16);
// Property AdelaideOval("Adelaide Oval", 300, 70, 17);
// Property StBernards("St Bernards", 250, 50, 18);
// Property Hindley("Hindley Club", 275, 55, 19);

//creating some card objects
//Card(string header, int action_type, int change_balance, int change_position)
//action type 1 means we change the position
//action type 2 means we change the account_balance;

//==declaring card objects==
// const int card_count = 6;
// Card *cards = new Card[card_count];
// cards[0] = card("You got caught stealing from Burnside Village, go to jail!",1,0,5);
// cards[1] = card("Adelaide Uni awards you a game design prize foor OOP, collect a $500 dollar prize",2,500,0);
// card[2] = card("You skipped the line at Centerlink, you loose your 200 dollar allowance for passing start",2,-200,0);
// card[3] = card("St benards fruit and vegetables got attacked by ALDI staff for being too cheap, you volenteer 200 dollars out of pocket to help fix the store",2,-200,0);
// card[4] = card("Great state vouchers award you 100 dollars for SA tourism, go have some fun!",2,100,0);
// card[5] = card("You fell asleep on an O-barn bus, whoops your final bus stop is START!",1,0,0);
// std::vector<Card*> cards;
// cards.push_back(new Card("You got caught stealing from Burnside Village, go to jail!",1,0,5));
// cards.push_back(new Card("Adelaide Uni awards you a game design prize foor OOP, collect a $500 dollar prize",2,500,0));
// cards.push_back(new Card("You skipped the line at Centerlink, you loose your 200 dollar allowance for passing start",2,-200,0));
// cards.push_back(new Card("St benards fruit and vegetables got attacked by ALDI staff for being too cheap, you volenteer 200 dollars out of pocket to help fix the store",2,-200,0));
// cards.push_back(new Card("Great state vouchers award you 100 dollars for SA tourism, go have some fun!",2,100,0));
// cards.push_back(new Card("You fell asleep on an O-barn bus, whoops your final bus stop is START!",1,0,0));


//outside of function references as we want the namespace to be global for card_count so other functions can access it;


//Card::Card(string header, int action_type, int change_balance, int change_position)
//int num = 5; //this should 

void getPlayerInfo(Board* adelaide_monopoly);
void mainMenu(Board* adelaide_monopoly);
void make_move();
void board_Setup();
void play_game(int userCount, Player* Players, Board* adelaide_monopoly);

int main(void)
{
    Board* adelaide_monopoly = new Board();


    // for(int i =0; i< card_count; i++){
    //     cards.push_back(card[i]);
    // }
    system("clear");
    //create_cards();
    mainMenu(adelaide_monopoly);

}

void mainMenu(Board* adelaide_monopoly)
{

    int input;
    cout << "Welcome to Adelaide Edition Monopoly" << endl;
    cout << "it's just like regular monopoly but shoretened!" << endl;
    cout << "==============================================" << endl;
    cout << "If you feel you have had enough, press 2 to quit the game. " << endl;
    cout << "Note the game will only quit if everyone decides to quit" << endl;
    cout << "Press 1 to start a game!" << endl;

    // input validation!
    while (!(cin >> input) && input != 1 && input != 2) {
        system("clear");

        cout << "You have entered an invalid input! Try again!" << endl;

        cout << "Welcome to Adelaide Edition Monopoly" << endl;
        cout << "it's just like regular monopoly but shortened!" << endl;
        cout << "============================" << endl;
        cout << "  Press 1 to start a game!" << endl;
        cout << "  Press 2 to quit the game!" << endl;


        cin.clear(); //clears input

        cin.ignore(150, '\n');

    }

    system("clear");



    if (input == 1)

    {
        getPlayerInfo(adelaide_monopoly);
    }

    else
    {
        //end program
        delete adelaide_monopoly;
        cout << "Bye Bye!" << endl;
        exit(69);
    }
    return;
}

void getPlayerInfo(Board* adelaide_monopoly)
{
    int playercount;

    cout << "How many players will there be? (2-6)" << endl;
    cout << "=======================================" << endl;
    while (!(cin >> playercount) || playercount > 6 | playercount < 2)
    {
        cin.clear(); //clears input

        cin.ignore(256, '\n');

        system("clear");

        cout << "Invalid number! Please enter a number from 2 to 6!" << endl
            << endl;
        cout << "Enter player count:" << endl;

    }
    adelaide_monopoly->player_count = playercount;
    string tempName;

    //creating an array to store players
    Player* players = new Player[playercount];

    cin.clear(); //clears input

    cin.ignore(256, '\n');

    for (int i = 0; i < playercount; i++)
    {
        //Player* Players = new Player[player_count]; this is not what we want to do as we want to call a constructor

        //It is crucial to note that the first player starts at 1
        cout << "Enter Player " << i + 1 << " Name: " << endl;
        getline(cin, tempName);
        //player_object(name,player number);
        players[i] = Player(tempName, i + 1);
        //this is an alternative way to change the variables individually, but I prefer the above method of calling the constructor
        // Players[i].playerName = tempName;
        // Players[i].player_num = i + 1;
        // Players[i].change_balance(1500);
    }
    //we need to dereference players to become a single pointer instead of a double pointer by calling it as *players
    play_game(playercount, players, adelaide_monopoly);
}

void play_game(int userCount, Player* Players, Board* adelaide_monopoly)
{

    adelaide_monopoly->make_move(Players);
    adelaide_monopoly->~Board();

}
