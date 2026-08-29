#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>
#include "entity.h"
using namespace std;

class hero : public entity {
public:

    //stats
    hero() {
        name = "Hero";
        ehp = 150;
    }

    int cooldown = 0;
    int healHP;
    string choice;

    //Calculates Hero Damage
    int attack() override {
        int eatk = rand() % 5 + 26;
        return eatk; // return the damage out
    }

    //heals the Hero
    void heal() {
        healHP = rand() % 10 + 31;
        ehp += healHP;
    }

    // Allow for user to decied what to dose
    int turn() {
        string choice;

        if (cooldown > 0) {
            cooldown--;
            std::cout << "Heal is on Cooldown right now for " << cooldown << " turns left." << std::endl;
        }
        while (true) {

            std::cout << "Attack or Heal? Current HP: " << ehp << std::endl;

            cin >> choice;

            for (int i = 0; i < choice.length(); i++) { //used to get rid of cap sensitivity
                choice[i] = toupper(choice[i]);
            }

            if (choice == "ATTACK") {
                int hatk = attack();
                return hatk;
            }

            //If Heal
            else if (choice == "HEAL") {
                if (cooldown == 0) { //can only heal every 2 turns
                    heal();
                    cooldown = 3;
                    return 0;
                }
                else {
                    std::cout << "Heal need to recharge" << std::endl;
                }
            }

            //If Wrong
            else {
                std::cout << "Please enter Attack or Heal" << std::endl;
            }

        }
    }

    void takeD(int eatk) override {
        ehp -= eatk;

        if (ehp <= 0) {
            cout << R"(
_____.___.              ________  .__           .___
\__  |   | ____  __ __  \______ \ |__| ____   __| _/
 /   |   |/  _ \|  |  \  |    |  \|  |/ __ \ / __ | 
 \____   (  <_> )  |  /  |    `   \  \  ___// /_/ | 
 / ______|\____/|____/  /_______  /__|\___  >____ | 
 \/                             \/        \/     \/ 
            )" << endl;
        }
    }

};
#endif