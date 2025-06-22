// AirSpirit.h
#pragma once
#include "Spirit.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class AirSpirit : public Spirit {
public:
    AirSpirit(const string& name)
      : Spirit(name, 
            //rates
            3, 11, 3,
            40, 3,
            100, 10)
    {}

    void feed() override {
        hunger_     = clamp(hunger_ - 30, 0, 100);
        boredom_    = clamp(boredom_ + 5, 0, 100);
        bond_       = clamp(bond_ + 10, 0, 100);
        std::cout << "You fed " << getName() <<" a fluffy cloudpuff." << std::endl;
    }
    void play() override {
        boredom_    = clamp(boredom_ - 30, 0, 100);
        hunger_     = clamp(hunger_ + 10, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 15, 0, 100);
        bond_       = clamp(bond_ + 25, 0, 100);
        std::cout << getName() <<" whirls with excitement!" << std::endl;
    }
    void sleep() override {
        sleepiness_ = clamp(sleepiness_ - 40, 0, 100);
        hunger_     = clamp(hunger_ + 10, 0, 100);
        boredom_    = clamp(boredom_ + 5, 0, 100);
        bond_       = clamp(bond_ + 2, 0, 100);
        std::cout << "Shhh... " << getName() <<" is sleeping!" << std::endl;
    }
    void groom() override {
        boredom_ = clamp(boredom_ - 10, 0, 100);
        bond_    = clamp(bond_ + 5, 0, 100);
        std::cout << getName() <<" feels fresh!" << std::endl;
    }
    void train() override {
        hunger_     = clamp(hunger_ + 15, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 20, 0, 100);
        boredom_    = clamp(boredom_ - 10, 0, 100);
        bond_       = clamp(bond_ + 30, 0, 100);
        std::cout << getName() << " darts like a gust through the sky, mastering agile new moves." << std::endl;

    }
    void pet() override {
        hunger_     = clamp(hunger_ + 5, 0, 100);
        sleepiness_ = clamp(sleepiness_ + 5, 0, 100);
        boredom_    = clamp(boredom_ - 20, 0, 100);
        bond_       = clamp(bond_ + 15, 0, 100);
        std::cout << getName() << " twirls playfully around you, a breeze brushing your cheek in delight." << std::endl;
    }

    void draw() const override {
        std::string artFile = "air.txt";
        printDrawing(artFile);
    
        std::string mood = getMood();
    
        if (mood == "angry") {
            std::cout << "The wind howls—your Air Spirit is in a stormy rage!" << std::endl;
        } else if (mood == "sad") {
            std::cout << "A gentle breeze brushes by... your Air Spirit seems distant and gloomy." << std::endl;
        } else {
            std::cout << "The air is light and playful—your Air Spirit dances joyfully!" << std::endl;
        }
    }
};

