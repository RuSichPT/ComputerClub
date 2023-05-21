#include <iostream>
#include "FileParser/FileParser.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc >= 2) {
        string filename = argv[1];

        FileParser fileParser;
        if (fileParser.parse("../" + filename)) {
            for (auto &el:fileParser.getStrings()) {
                cout << el << endl;
            }
        } else {
            cout << "file open error";
        }
    } else {
        cout << "not enough arguments";
    }

    return 0;
}
