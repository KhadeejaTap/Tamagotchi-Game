// Spirit.h
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

class Spirit {
public:
    Spirit(const string& name, int hungerRate, int boredomRate, int sleepinessRate, int eBond1, int eGood1, int eBond2, int eGood2);
    virtual ~Spirit();

    // Accessors
    string getName() const;
    int getHunger() const;
    int getBoredom() const;
    int getSleepiness() const;
    int getBond() const;
    int getStage() const;
    string getMood() const;

    // Interactions
    virtual void reset();

    virtual void feed();
    virtual void play() = 0;
    virtual void sleep();
    virtual void groom();
    virtual void train();
    virtual void pet();

    // draw each spirit
    virtual void draw() const = 0;

    // Time 
    void nextHour();

    // save
    virtual void save(ofstream& out) const;
    virtual void load(ifstream& in);
    //fstream to output ascii files
    void printDrawing(const string& filename) const;
protected:
    void updateMood();
    bool shouldEvolve() const;
    void evolve();

    static int clamp(int v,int lo,int hi);

    string name_, mood_;
    int hunger_, boredom_, sleepiness_, bond_, stage_;
    int hoursCared_, goodHours_;
    int hungerRate_, boredomRate_, sleepinessRate_;
    int evolveBondReq_[2], evolveGoodHoursReq_[2];
};

