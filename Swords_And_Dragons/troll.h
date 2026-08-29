#ifndef TROLL_H
#define TROLL_H

#include <iostream>
#include <string>
#include "entity.h"
using namespace std;

class troll : public entity {
public:
    int atk;
    int times;
    int lasttimes;

    //stats
    troll() {
        name = "Troll";
        ehp = 75; //Troll 
        alive = 0;
    }

    //Atack Function
    int attack() override {         //attack with 5-10 damage but can attack 2-4 times???
        int sum = 0;
        int times = rand() % 3 + 2;
        for (int i = 0; i < times; i++) {
            atk = rand() % 5 + 6;
            sum += atk;
        }

        lasttimes = times;
        return sum;
    }

    void takeD(int eatk) override {
        ehp -= eatk;

        if (ehp <= 0) {
            cout << "You have slain the Torll" << endl;
        }
    }

    void flavor() override {
        if (alive > 0) {
            std::cout << "The Troll Hit " << lasttimes << " times" << std::endl;
        }
        else {
            std::cout << "A Troll Has Appread" << std::endl;
        }
    }

    void art() override {
        std::cout << R"( 
              _,
           _,/'/;
          /__,/ |
          oo \,/
         (/__/_
         ,/.-. `.
        /(( . )) \
        `-'---'`-'
          `--'--'
        )" << std::endl;
    }
};
#endif