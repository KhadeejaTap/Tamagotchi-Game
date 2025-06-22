// EarthSpirit.h
#pragma once
#include "Spirit.h"
#include <iostream>

class EarthSpirit : public Spirit {
public:
    EarthSpirit(const string& name)
      : Spirit(name, 3,1,10, 55,4, 105,10)
    {}

    void feed() override {
        hunger_     = clamp(hunger_ - 30, 0, 100);
        boredom_    = clamp(boredom_ + 5, 0, 100);
        bond_       = clamp(bond_ + 10, 0, 100);
        std::cout << "You fed " << getName() <<" rock candy." << std::endl;

    }
    void play() override {
        boredom_    = clamp(boredom_ - 30, 0, 100);
        hunger_     = clamp(hunger_ + 10, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 15, 0, 100);
        bond_       = clamp(bond_ + 15, 0, 100);
        std::cout << getName() <<" seems happy!" << std::endl;
    }
    void sleep() override {
        sleepiness_ = clamp(sleepiness_ - 20, 0, 100);
        hunger_     = clamp(hunger_ + 3, 0, 100);
        boredom_    = clamp(boredom_ + 1, 0, 100);
        bond_       = clamp(bond_ + 15, 0, 100);
        std::cout <<  getName() <<" is enjoying a calming nap..." << std::endl;

    }
    void groom() override {
        boredom_ = clamp(boredom_ - 10, 0, 100);
        bond_    = clamp(bond_ + 5, 0, 100);
        std::cout << "You dust off a few leaves from " << getName() << std::endl;
        
    }
    void train() override {
        hunger_     = clamp(hunger_ + 15, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 20, 0, 100);
        boredom_    = clamp(boredom_ - 5, 0, 100);
        bond_       = clamp(bond_ + 20, 0, 100);
        std::cout << getName() << "roots its strength deeper." << std::endl;

    }
    void pet() override {
        hunger_     = clamp(hunger_ + 5, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 5, 0, 100);
        boredom_    = clamp(boredom_ - 15, 0, 100);
        bond_       = clamp(bond_ + 20, 0, 100);
        std::cout << getName() << " leans into your touch." << std::endl;
    }

    void draw() const override {
        std::string artFile = "earth.txt";
        printDrawing(artFile);
    
        std::string mood = getMood();
    
        if (mood == "angry") {
            std::cout << "The ground trembles—your Earth Spirit is rumbling with frustration!" << std::endl;
        } else if (mood == "sad") {
            std::cout << "Leaves fall quietly... your Earth Spirit seems weary and still." << std::endl;
        } else {
            std::cout << "The earth is warm and steady—your Earth Spirit is content and grounded!" << std::endl;
        }
    }
};
