/******************************************************************************

SWORDS AND DRAGONS GAME

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "entity.h"
#include "dragon.h"
#include "troll.h"
#include "direWolf.h"
#include "hero.h" 

using namespace std;

//-----------------------------------------------------------------------
// Functions
void clean(entity* ename, int turn);
void title();
void win();
//-----------------------------------------------------------------------

// Main class / using the classes
int main() {
    //Intializing other objects
    srand(time(0));
    string choice;
    int damage;
    //Intializing tyhe enemie
    int renemie;
    char flag = 'y';

    title();
    cin >> flag;

    while (flag == 'y' || flag == 'Y') {
        // Repeting statments
        int turn = 1; // used to store total tunrs
        hero h;
        dragon dr;
        troll t;
        direWolf dW;

        //vector used to store the enemie classes
        vector<entity*> eN = { &dr, &t, &dW };

        while (!eN.empty()) {
            renemie = rand() % eN.size(); // pulls a rand enemie with a -i amount of array size;
            eN[renemie]->alive = 0;       // used as turn counter per enemie

            //Battle loop
            while (h.ehp > 0 && eN[renemie]->ehp > 0) {

                //Game Promts
                clean(eN[renemie], turn);

                //Heros Turn
                damage = h.turn();
                eN[renemie]->takeD(damage);

                //enemie Turn
                if (eN[renemie]->ehp > 0) { // used so you both dont die
                    damage = eN[renemie]->attack();
                    h.takeD(damage);
                }

                eN[renemie]->alive++; // adds the enemie turn counter
                turn++;               // adds to the game turn counter
            }
            //Used to remove the index of the enemie for no reppetion
            eN.erase(eN.begin() + renemie);
        }

        if (h.ehp > 0) {
            std::cout << "YOU HAVE SLAIN ALL THE ENEMIES!" << std::endl;
            win();
        }

        std::cout << "Want to play again? Y or N" << std::endl;
        cin >> flag;

    }
    return 0;
}

//-----------------------------------------------------------------------
// Functions
void clean(entity* ename, int turn) {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    std::cout << "It's turn " << turn << "!" << std::endl;

    if (ename->alive > 0) {
        std::cout << "The " << ename->name << " is still alive" << std::endl;
        ename->flavor();
    }
    else {
        std::cout << "A " << ename->name << " has appeard" << std::endl;
    }

    ename->art();
    ename->estats();

    std::cout << "What would you like to do" << std::endl;
}

void title() {
    std::cout << R"(
      _________                       .___           
     /   _____/_  _  _____________  __| _/______     
     \_____  \\ \/ \/ /  _ \_  __ \/ __ |/  ___/     
     /        \\     (  <_> )  | \/ /_/ |\___ \      
    /_______  / \/\_/ \____/|__|  \____ /____  >     
            \/                         \/    \/      
                                  .___               
               _____    ____    __| _/               
               \__  \  /    \  / __ |                
                / __ \|   |  \/ /_/ |                
               (____  /___|  /\____ |                
                    \/     \/      \/                
________                                             
\______ \____________     ____   ____   ____   ______
 |    |  \_  __ \__  \   / ___\ /  _ \ /    \ /  ___/
 |    `   \  | \// __ \_/ /_/  >  <_> )   |  \\___ \ 
/_______  /__|  (____  /\___  / \____/|___|  /____  >
        \/           \//_____/             \/     \/ 

            Would You like to enter the dungeon?
                            y?
        )" << std::endl;
} // title screen

void win() {
    std::cout << R"(
_____.___.                      .__        
\__  |   | ____  __ __  __  _  _|__| ____  
 /   |   |/  _ \|  |  \ \ \/ \/ /  |/    \ 
 \____   (  <_> )  |  /  \     /|  |   |  \
 / ______|\____/|____/    \/\_/ |__|___|  /
 \/                                     \/ 
        )" << std::endl;
} // win screen

