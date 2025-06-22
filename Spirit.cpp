
// Spirit.cpp
#include "Spirit.h"

Spirit::Spirit(const string& name,
               int hungerRate, int boredomRate, int sleepinessRate,
               int eBond1, int eGood1, int eBond2, int eGood2)
  : name_(name), hunger_(20), boredom_(30), sleepiness_(15), bond_(40),
    stage_(1), hoursCared_(0), goodHours_(0), mood_("happy"),
    hungerRate_(hungerRate), boredomRate_(boredomRate), sleepinessRate_(sleepinessRate)
{
    evolveBondReq_[0]      = eBond1;
    evolveGoodHoursReq_[0] = eGood1;
    evolveBondReq_[1]      = eBond2;
    evolveGoodHoursReq_[1] = eGood2;
    updateMood();
}

Spirit::~Spirit() {}

string Spirit::getName()       const { return name_; }
int    Spirit::getHunger()     const { return hunger_; }
int    Spirit::getBoredom()    const { return boredom_; }
int    Spirit::getSleepiness() const { return sleepiness_; }
int    Spirit::getBond()       const { return bond_; }
int    Spirit::getStage()      const { return stage_; }
string Spirit::getMood()       const { return mood_; }

void Spirit::feed() {
    // default no-op; override in subclasses
}

void Spirit::sleep() {
    // default no-op; override
}

void Spirit::groom() {
    // default no-op; override
}

void Spirit::train() {
    // default no-op; override
}

void Spirit::pet() {
    // default no-op; override
}

void Spirit::printDrawing(const string& filename) const {
    ifstream file(filename);
    if (!file) {
        cout << "[Cannot open " << filename << "]\n";
        return;
    }
    string line;
    while (getline(file, line)) cout << line << "\n";
}

void Spirit::nextHour() {
    hunger_     = clamp(hunger_ + hungerRate_, 0, 100);
    boredom_    = clamp(boredom_ + boredomRate_, 0, 100);
    sleepiness_ = clamp(sleepiness_ + sleepinessRate_, 0, 100);

    hoursCared_++;
    if (sleepiness_ > 50) {
        std::cout << getName() << " looks sleepy..." << std::endl;
    } 
    if (hunger_ > 50) {
        std::cout << getName() << " is feeling hungry." << std::endl;
    } 
    if (boredom_ > 50) {
        std::cout << getName() << " seems bored." << std::endl;
    }
    
    if (hunger_ < 50 && boredom_ < 50 && sleepiness_ < 50){
        goodHours_++;
    }
    updateMood();
    if (shouldEvolve()) evolve();
}

void Spirit::save(ofstream& out) const {
    out << name_       << std::endl
        << stage_      << std::endl
        << hunger_     << std::endl
        << boredom_    << std::endl
        << sleepiness_ << std::endl
        << bond_       << std::endl
        << hoursCared_ << std::endl
        << goodHours_  << std::endl
        << mood_       << std::endl;
}

void Spirit::load(ifstream& in) {
    std::getline(in, name_);           
    in >> stage_; in.ignore(1, '\n');
    in >> hunger_;    in.ignore(1, '\n');  
    in >> boredom_;   in.ignore(1, '\n');
    in >> sleepiness_;in.ignore(1, '\n');
    in >> bond_;      in.ignore(1, '\n');
    in >> hoursCared_;in.ignore(1, '\n');
    in >> goodHours_; in.ignore(1, '\n');
    std::getline(in, mood_);  
}

void Spirit::updateMood() {
    if (hunger_ >= 100 && boredom_ >= 20 && sleepiness_ >= 80)
        mood_ = "angry";
    else if ((hunger_ >= 50 && boredom_ >= 50) || (boredom_ >=50 && sleepiness_ >= 50))
        mood_ = "sad";
    else
        mood_ = "happy";
}

bool Spirit::shouldEvolve() const {
    if (stage_ >= 3) return false;
    int idx = stage_ - 1;
    return bond_ >= evolveBondReq_[idx]
        && goodHours_ >= evolveGoodHoursReq_[idx];
}

void Spirit::evolve() {
    stage_++;
    cout << name_ << " has evolved to stage " << stage_ << "!\n";
}

int Spirit::clamp(int v,int lo,int hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}

// Reset all core stats to their starting values
void Spirit::reset() {
    hunger_      = 20;   // starting hunger
    boredom_     = 30;   // starting boredom
    sleepiness_  = 15;   // starting sleepiness
    bond_        = 40;   // starting bond
    stage_       = 1;    // back to stage 1
    hoursCared_  = 0;    // no hours yet
    goodHours_   = 0;    // no good hours yet

    updateMood();        // recalculate mood based on reset stats
}
