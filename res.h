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

class Restaurant {
  private:
    string name = "";
    unsigned date;
    int ave;
    int needcar;
    int priority;
    int times = 0;
    vector<string> distance;
    void update() { date = chrono::system_clock::now().time_since_epoch().count(); }
    bool flavor[6];
    friend class YOLO;
  public:
    string getname() { return name; }
    void setname(string n) { update(); if(name.compare("")) { cout <<"I am afraid I can't do this, my lord" << endl; return; } name = n; }
    unsigned getdate() { return date; }
    int getave() { return ave; }
    void setave(int a) { update(); ave = a; }
    int getcar() { return needcar; }
    void setcar(int car) { update(); times++; needcar = car; }
    int getpriority() { return priority; }
    void setpriority(int p) { update(); times++; priority = p; }
    Restaurant() {
        distance.push_back("Walk");
        distance.push_back("Tricky");
        distance.push_back("Drive");

    }
    bool operator == (Restaurant other) { if(!name.compare(other.getname())) { return 1; } else { return 0; }}
    bool newer (Restaurant other) { if(date >= other.getdate()) return 1; else return 0; }
    void print() { cout << name << endl; }
    void printpro() {
        cout << "Name: " << name << "\nAverage cost: " << ave << "\nDistance: " << distance[needcar] << endl;
        cout << "Serve sour flavor: " << (flavor[0] ? "YES" : "NO ") << "    Serve spicy flavor: "  << (flavor[1] ? "YES" : "NO" ) << endl;
        cout << "Serve lot of meat: " << (flavor[2] ? "YES" : "NO ") << "    Serve OP vegetable: "  << (flavor[3] ? "YES" : "NO")  << endl;
        cout << "Serve light taste: " << (flavor[4] ? "YES" : "NO ") << "    Serve salty flavor: "  << (flavor[5] ? "YES" : "NO")  << endl;
    }
    void setflavor(bool flavors[6]){
        for(int i = 0; i < 6; i++){
            flavor[i] = flavors[i];
        }
    }
    void getflavor(bool flavors[6]) {
        for(int i = 0; i < 6; i++){
            flavors[i] = flavor[i];
        }
    }

};

//In the pick.cpp.

//In the listmanage.cpp.

#endif
