#ifndef	RES
#define RES

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <random>
#include <unistd.h>
using namespace std;

class Restaurants {
  private:
    string name = "";
    unsigned date;
    int ave;
    int needcar;
    int priority;
    int times = 0;
    string[] distance = {"Walkable", "Tricky", "Drive"}
    void update() { date = chrono::system_clock::now().time_since_epoch().count(); }
    friend class YOLO;
  public:
    string getname() { return name; }
    void setname(string n) { if(name.compare("")) { cout <<"I am afraid I can't do this, my lord" << endl; return; } name = n; }
    unsigned date() { return date; }
    int getave() { return ave; }
    int getcar() { return needcar; }
    void setcar(int car) { times++; needcar = car; }
    int getpriority() { return priority; }
    void setpriority(int p) { times++; priority = p; }
    bool suan, la, you, cai, dan, xian;
    Restaurant();
    ~Restaurant();
    bool operator == (Restaurant other) { if(!name.compare(other.getname())) { return 1; } else { return 0; }}
    bool newer (Restaurant other) { if(date >= other.date()) return 1; else return 0; }
    void print() { cout << name << endl; }
    void printpro() {
        cout << name << "\nAverage cost: " << ave << "\nDistance: " << distance[needcar] << endl;
        cout << "Serve sour flavor: " << suan ? "YES" : "NO " << "    Serve spicy flavor: "  << la ? "YES" : "NO"  << endl;
        cout << "Serve lot of meat: " << you ? "YES" : "NO " << "    Serve OP vegetable: "  << cai ? "YES" : "NO"  << endl;
        cout << "Serve light taste: " << dan ? "YES" : "NO " << "    Serve salty flavor: "  << xian ? "YES" : "NO"  << endl;
    }

}

//In the pick.cpp.

//In the listmanage.cpp.

#endif
