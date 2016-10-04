#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <random>
#include <unistd.h>
using namespace std;
//Read file to get list of restaurants.
void readfile (vector<string>& l, string filename) {
    ifstream infile;
    infile.open(filename);//open the input file
    string line;
    while (getline(infile, line)){
        l.push_back(line);
    }
}
//Print every retaurant in the list.
void print_res (vector<string> l) {
    cout << "Here is the list of restaurant, sir." << endl;
    int i = 1;
    for(string n : l) {
        cout << i << ". " << n << endl;
        i++;
    }
}
//Pick a restaurant randomly.
void pick_res (vector<string> l){
    cout << "This is a random pick of retaurants, my lord.\n" << endl;
    int size = l.size();
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(1,size);
    int index = distribution(generator);
    cout<< l[index-1] << endl;
}
//Add a new restaurant to the reslist.
void add_res (){

}
int main(int argc, char const *argv[]) {
    vector<string> a;
    readfile(a, "reslist");
    string command = "";
    while(command.compare("withdraw")) {
        cout << "\nHow can I help you, my lord?\n" << endl;
        cin >> command;
        cout << endl;
        if(!command.compare("print")) { print_res(a); }
        else if (!command.compare("pick")) { pick_res(a); }
        else if (command.compare("withdraw")) {
            cout << "Sorry my lord, I can't hear you." << endl;
        }
    }
    cout << "Yes, my lord." << endl;
    usleep(500000);
    return 0;
}
