#include "Restaurant.h"

Restaurant::Restaurant() {
    note = name = "";
    flavor = "酸0甜0苦0辣0咸0油0肉0菜0量0";
    est_cost = distance = priority = times = 0;
    last_change = 0;
    distance = avecost = 0;
}

void Restaurant::setname(string name) {
    if(name != "") { this->name = name; }
    else { cout <<"I am afraid I can't do this, my lord" << endl; }
}

string Restaurant::getname() { return name; }

void Restaurant::setest(int est) { est_cost = est; }

int Restaurant::getest() { return est_cost; }

void Restaurant::setpri(int i) { priority = i; }

int Restaurant::getpri() { return priority; }

void Restaurant::setflavor(string f) { flavor = f; }

string Restaurant::getflavor() { return flavor; }

void Restaurant::setdis(double dis) { distance = dis; }

double Restaurant::getdis() { return distance; }

void Restaurant::setnote(string j) { note = j; }

string Restaurant::getnote() { return note; }

void Restaurant::update() { last_change = time(0); }

int Restaurant::gettimes() { return times; }

void Restaurant::print(int mode) {
    cout << "Name: " << name << endl;

    if(mode % 2) {
        std::cout << std::setprecision(2) << std::fixed;
        cout << "Estimate cost: " << est_cost << "$    Distance: " << distance << " mile(s)" << endl;
        cout << "Flaver: " << endl;
    }

    mode /= 2;
    if(mode % 2) {
        cout << "Last time edited at: " << ctime(&last_change) << endl;
    }

    mode /= 2;
    if(mode % 2) {
        cout << "Visited here " << times << " times, evarage cost is: " << avecost << "$" <<  endl;
        if(history.size()) {
            cout << "History:" << endl;
            for(record i : history) {
                cout << ctime(&i.date) << " Cost: " << i.cost << "$" << endl;
            }
        }
    }

    mode /= 2;
    if(mode % 2) {
        cout << "Note: " << note << endl;
    }

    cout << endl;
}

void Restaurant::addhistory(time_t date, double cost) {
    record i;
    i.cost = cost;
    i.date = date;
    history.push_back(i);
}
