// FireSpirit.h
#pragma once
#include "Spirit.h"
#include <iostream>

class FireSpirit : public Spirit {
public:
    FireSpirit(const string& name)
      : Spirit(name, 5,8,5, 50,5, 100,15)
    {}

    void feed() override {
        hunger_     = clamp(hunger_ - 30, 0, 100);
        boredom_    = clamp(boredom_ + 5, 0, 100);
        bond_       = clamp(bond_ + 10, 0, 100);
        std::cout << "You fed " << getName() <<" a hot emberfruit." << std::endl;

    }
    void play() override {
        boredom_    = clamp(boredom_ - 40, 0, 100);
        hunger_     = clamp(hunger_ + 10, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 15, 0, 100);
        bond_       = clamp(bond_ + 25, 0, 100);
        std::cout << getName() <<" is radiating excitement!" << std::endl;

    }
    void sleep() override {
        sleepiness_ = clamp(sleepiness_ - 50, 0, 100);
        hunger_     = clamp(hunger_ + 15, 0, 100);
        boredom_    = clamp(boredom_ + 10, 0, 100);
        bond_       = clamp(bond_ + 5, 0, 100);
        std::cout << "Lights out! " << std::endl;

    }
    void groom() override {
        boredom_ = clamp(boredom_ - 10, 0, 100);
        bond_    = clamp(bond_ + 5, 0, 100);
        std::cout << "You polish " << getName()<< "'s fiery glow. "<< std::endl;
    }
    void train() override {
        hunger_     = clamp(hunger_ + 5, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 10, 0, 100);
        boredom_    = clamp(boredom_ - 5, 0, 100);
        bond_       = clamp(bond_ + 30, 0, 100);
        std::cout << getName() << " flares up with determination, blazing through their training trial." << std::endl;

    }
    void pet() override {
        hunger_     = clamp(hunger_ + 5, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 5, 0, 100);
        boredom_    = clamp(boredom_ - 15, 0, 100);
        bond_       = clamp(bond_ + 12, 0, 100);
        std::cout << "A gentle warmth pulses from " << getName() << " as they flicker contentedly under your hand." << std::endl;
    }

    void draw() const override {
        std::string artFile = "fire.txt";
        printDrawing(artFile);
    
        std::string mood = getMood();
    
        if (mood == "angry") {
            std::cout << "Flames flare up—your Fire Spirit is burning with rage!" << std::endl;
        } else if (mood == "sad") {
            std::cout << "A dim flicker glows... your Fire Spirit seems downcast." << std::endl;
        } else {
            std::cout << "Sparks dance cheerfully—your Fire Spirit feels bright and joyful!" << std::endl;
        }
    }
};
