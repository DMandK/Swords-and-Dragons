#ifndef DRAGON_H
#define DRAGON_H

#include <iostream>
#include <string>
#include "entity.h"
using namespace std;

class dragon : public entity {
public:
    //stats
    dragon() {
        name = "Dragon";
        ehp = 175;//Dragon HP
    }

    //Atack Function
    int attack() override {      //attack with 15-25 damage
        return rand() % 20 + 16;
    }

    void takeD(int eatk) override {
        ehp -= eatk;

        if (ehp <= 0) {
            cout << "You have slain the Dragon" << endl;
        }
    }

    // Addds Askii Art
    void art() override {
        std::cout << R"( 
             <>=======() 
           (/\___   /|\\          ()==========<>_
                \_/ | \\        //|\   ______/ \)
                    \_|  \\      // | \_/
                    \|\/|\_   //  /\/
                     (oo)\ \_//  /
                      //_/\_\/ /  |
                     @@/  |=\  \  |
                          \_=\_ \ |
                            \==\ \|\_ 
                         __(\===\(  )\
                        (((~) __(_/   |
                             (((~) \  /
                             ______/ /
                             '------'
        )" << std::endl;
    }

    //Adds Flavor text
    void flavor() override {
        std::cout << "RAW!" << std::endl;
    }
};
#endif