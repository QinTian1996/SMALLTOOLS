#ifndef RESTAURANT
#define RESTAURANT

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <iomanip>

using namespace std;

class record {
private:
    double cost;
    time_t date;
    friend class Restaurant;
};
class Restaurant {

private:
    string name;
    time_t last_change;
    int est_cost, priority, times;
    string note, flavor;
    double distance, avecost;
    vector<record> history;

public:
    Restaurant();
    void setname(string name);
    void setest(int est);
    void update();
    void setpri(int p);
    void setflavor(string f);
    void setdis(double dis);
    void setnote(string j);
    int getest();
    int gettimes(), getpri();
    string getname(), getnote(), getflavor();
    double getdis();
    void print(int mode), addhistory(time_t date, double cost);

};

#endif
