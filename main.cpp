// main.cpp
#include <iostream>
#include <memory>
#include <limits>
#include <fstream>
#include "WaterSpirit.h"
#include "FireSpirit.h"
#include "EarthSpirit.h"
#include "AirSpirit.h"
using namespace std;

// status bar
void printBar(const string& label, int val) {
    cout << label << " [";
    int bars = val / 10;
    for (int i = 0; i < 10; ++i)
        cout << (i < bars ? '/' : ' ');
    cout << "] " << val << "\n";
}

// Pet interaction loop
void petLoop(unique_ptr<Spirit>& pet) {
    
    while (true) {
        cout << "\n=== Managing " << pet->getName() << " ===\n";
        pet->draw();
        printBar("Hunger    ", pet->getHunger());
        printBar("Boredom   ", pet->getBoredom());
        printBar("Sleepiness", pet->getSleepiness());
        printBar("Bond      ", pet->getBond());
        cout << "Stage      " << pet->getStage() << endl << endl;

        cout << "1) Feed\t2) Play\t3) Sleep\n";
        cout << "4) Groom\t5) Train\t6) Pet\n";
        cout << "7) Reset Spirit\t8) Return to Main Menu\n";
        cout << "Choose an action: ";

        int action;
        if (!(cin >> action)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        if (action == 8) break;

        switch (action) {
          case 1: pet->feed();  break;
          case 2: pet->play();  break;
          case 3: pet->sleep(); break;
          case 4: pet->groom(); break;
          case 5: pet->train(); break;
          case 6: pet->pet();   break;
          case 7: pet->reset(); cout<<"Spirit reset.\n"; break;
          default: cout<<"Invalid action.\n"; break;
        }
        pet->nextHour();
        
    }
}

// Save & load
void saveAll(unique_ptr<Spirit> pets[4]) {
    static const string files[4] = {
      "save_water.txt","save_fire.txt",
      "save_earth.txt","save_air.txt"
    };
    ofstream out;
    for (int i = 0; i < 4; ++i) {
        if (!pets[i]) continue;
        out.open(files[i]);
        pets[i]->save(out);
        out.close();
    }
}

void loadAll(unique_ptr<Spirit> pets[4]) {
    static const string files[4] = {
      "save_water.txt","save_fire.txt",
      "save_earth.txt","save_air.txt"
    };
    for (int i = 0; i < 4; ++i) {
        ifstream in(files[i]);
        if (!in) continue;
        string name, dummy;
        getline(in, name);             // name line
        // Determine subclass from filename index
        switch (i) {
          case 0: pets[i] = make_unique<WaterSpirit>(name); break;
          case 1: pets[i] = make_unique<FireSpirit>(name);  break;
          case 2: pets[i] = make_unique<EarthSpirit>(name); break;
          case 3: pets[i] = make_unique<AirSpirit>(name);   break;
        }
        pets[i]->load(in);
    }
}

int main() {
    unique_ptr<Spirit> pets[4] = {nullptr,nullptr,nullptr,nullptr};
    loadAll(pets);

    while (true) {
        cout << "\n=== ELEMENTAL SPIRIT MENU ===\n";
        cout << "1) " << (pets[0] ? "Manage" : "Create") << " Water Spirit" << endl;
        cout << "   The Water Spirit is gentle and pure. It thrives on bonding and soft care." << endl;
        cout << "2) " << (pets[1] ? "Manage" : "Create") << " Fire Spirit" << endl;
        cout << " The Fire Spirit is energetic and restless. It needs to blow off steam often to stay happy." << endl;
        cout << "3) " << (pets[2] ? "Manage" : "Create") << " Earth Spirit" << endl;
        cout << "   The Earth Spirit is shy and loves resting. It feels safest when it's grounded and calm." << endl;
        cout << "4) " << (pets[3] ? "Manage" : "Create") << " Air Spirit\n";
        cout << "   The Air Spirit is playful and curious. It loves attention but gets bored easily." << endl;
        cout << "5) Exit\nEnter choice (1-5): ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number 1–5." << endl;
            continue;
        }
        if (choice == 5) {
            saveAll(pets);
            cout << "Game saved. Goodbye!\n";
            break;
        }
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice.\n";
            continue;
        }
        int idx = choice - 1;
        if (!pets[idx]) {
            cout << "Name your new ";
            switch(idx) {
              case 0: cout<<"Water"; break;
              case 1: cout<<"Fire";  break;
              case 2: cout<<"Earth"; break;
              default: cout<<"Air";   break;
            }
            cout << " Spirit: ";
            string name; cin>>name;
            switch(idx) {
              case 0: pets[0] = make_unique<WaterSpirit>(name); break;
              case 1: pets[1] = make_unique<FireSpirit>(name);  break;
              case 2: pets[2] = make_unique<EarthSpirit>(name); break;
              case 3: pets[3] = make_unique<AirSpirit>(name);   break;
            }
        }
        petLoop(pets[idx]);
        
    }
    return 0;
}
/* How to run: 
1) Press CTRL + ` to open the terminal.
2) Paste this into the terminal: g++ -o Tamagotchi.exe main.cpp Spirit.cpp
3) Type ./Tamagotchi.exe in the terminal. Press enter.
*/
