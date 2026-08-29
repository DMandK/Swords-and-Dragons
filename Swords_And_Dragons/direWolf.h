#ifndef DIREWOLF_H
#define DIREWOLF_H

#include <iostream>
#include <string>
#include "entity.h"
using namespace std;

class direWolf : public entity {
public:
    double atk;
    int sum;
    int flav;

    //Stats
    direWolf() {
        name = "Dire Wolf";
        ehp = 125; //Dire Wolf HP
    }

    //Atack Function
    int attack() override {         //attack with 10-20 damage but can cirt???
        int crit = rand() % 10 + 1;
        if (crit < 8) {
            flav = 0;
            return rand() % 10 + 11;
        }

        else if (crit < 10) {
            double atk = rand() % 10 + 11;
            atk = atk * 1.5 + .5;
            flav = 1;
            return atk;
        }

        else {
            double atk = rand() % 10 + 11;
            atk = atk * 2;
            flav = 2;
            return atk;
        }
    }

    void takeD(int eatk) override {
        ehp -= eatk;

        if (ehp <= 0) {
            cout << "You have slain the Dire Wolf" << endl;
        }
    }

    void flavor() override {
        if (flav == 0) {
            std::cout << "" << std::endl;
        }
        else if (flav == 1) {
            std::cout << "The Dire Wolf was Super Effective" << std::endl;
        }
        else {
            std::cout << "The Dire Wold Hit a Cirtical Attack" << std::endl;
        }
    }

    void art() override {
        std::cout << R"( 
                _
               / \      _-'
             _/|  \-''- _ /
        __-' { |          \
            /             \
            /       "o.  |o }
            |            \ ;
                          ',
               \_         __\
                 ''-_    \.//
                   / '-____'
                  /
                _'
              _-'
        )" << std::endl;
    }
};
#endif