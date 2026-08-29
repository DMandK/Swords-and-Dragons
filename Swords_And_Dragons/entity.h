#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
using namespace std;

//Stores the Fucions used in all the classes
class entity {
public:
    string name; //entity name
    int ehp; //entity HP
    int alive; //How long they have been alive

    //virtual attack used for other entitys to change by override
    virtual int attack() {
        return 0;
    }

    //hatk how much the damage the hero dose
    virtual void takeD(int eatk) { // change in to a virtual for a hero death to be unique
        std::cout << "Error With Damage" << std::endl;
    }

    //For the art used
    virtual void art() {
        std::cout << "No Image Found" << std::endl;
    }

    virtual void flavor() {
        std::cout << "No flavor text found" << std::endl;
    }

    // Out prints the enemie hp left 
    void estats() {
        std::cout << name << " HP left: " << ehp << std::endl;
    }
    // enemie HP class to have thier hp increase as you kill more
    // enemies Damage class so they do more as you kill more
};

#endif