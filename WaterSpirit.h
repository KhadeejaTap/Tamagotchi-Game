// WaterSpirit.h
#pragma once
#include "Spirit.h"
#include <iostream>

class WaterSpirit : public Spirit {
public:
    WaterSpirit(const string& name)
      : Spirit(name,2,2,8,60, 8,120,20){}

    void feed() override {
        hunger_     = clamp(hunger_ - 30, 0, 100);
        boredom_    = clamp(boredom_ + 5, 0, 100);
        bond_       = clamp(bond_ + 20, 0, 100);
        std::cout << "You fed " << getName() <<" a dewy rainjelly!" << std::endl;

    }
    void play() override {
        boredom_    = clamp(boredom_ - 30, 0, 100);
        hunger_     = clamp(hunger_ + 10, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 15, 0, 100);
        bond_       = clamp(bond_ + 15, 0, 100);
        std::cout << getName() <<" waves with excitement!" << std::endl;

    }
    void sleep() override {
        sleepiness_ = clamp(sleepiness_ - 40, 0, 100);
        hunger_     = clamp(hunger_ + 10, 0, 100);
        boredom_    = clamp(boredom_ + 5, 0, 100);
        bond_       = clamp(bond_ + 8, 0, 100);
        std::cout << getName() <<" is sleeping..." << std::endl;

    }
    void groom() override {
        boredom_ = clamp(boredom_ - 10, 0, 100);
        bond_    = clamp(bond_ + 15, 0, 100);
        std::cout << "You gently brush through the rippling mist around " << getName() << "." << std::endl;
    }
    void train() override {
        hunger_     = clamp(hunger_ + 15, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 20, 0, 100);
        boredom_    = clamp(boredom_ - 5, 0, 100);
        bond_       = clamp(bond_ + 20, 0, 100);
        std::cout << getName() << " swirls in a focused whirlpool, mastering fluid motion with grace." << std::endl;

    }
    void pet() override {
        hunger_     = clamp(hunger_ + 5, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 5, 0, 100);
        boredom_    = clamp(boredom_ - 15, 0, 100);
        bond_       = clamp(bond_ + 12, 0, 100);
        std::cout << getName() << " hums like a soft stream, nuzzling your hand with a cool splash." << std::endl;

    }

    void draw() const override {
        std::string artFile = "water.txt";
        printDrawing(artFile);
    
        std::string mood = getMood();
    
        if (mood == "angry") {
            std::cout << "Waves crash violently—your Water Spirit is upset!" << std::endl;
        } else if (mood == "sad") {
            std::cout << "Droplets fall slowly... your Water Spirit seems down." << std::endl;
        } else {
            std::cout << "The tide is calm and gentle, your Water Spirit feels happy and refreshed!" << std::endl;
        }
    }
};
