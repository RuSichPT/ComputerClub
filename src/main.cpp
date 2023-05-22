#include <iostream>
#include <string>
#include "ComputerClub/ComputerClub.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc >= 2) {
        string filename = argv[1];
        try {
            ComputerClub club("../" + filename);
            club.open();
        } catch (const exception &e) {
            cerr << e.what() << endl;
        }
    } else {
        cerr << "not enough arguments";
    }

    return 0;
}
