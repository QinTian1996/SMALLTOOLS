#include "res.h"

int main(int argc, char const *argv[]) {
    Restaurant alpha;
    alpha.setname("东方");
    alpha.setcar(2);
    alpha.setpriority(6);
    bool f[6] = {1,0,1,1,0,1};
    alpha.setflavor(f);
    alpha.setave(20);
    alpha.printpro();
    f[0] = 0;
    alpha.getflavor(f);
    cout << f[0];
    return 0;
}
