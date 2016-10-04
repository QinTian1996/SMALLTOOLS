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

}

#endif
