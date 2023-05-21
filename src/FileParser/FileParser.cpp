#include "FileParser.h"
#include <fstream>

bool FileParser::parse(const string &path) {
    ifstream fin;

    fin.open(path);

    string line;

    if (fin.is_open()) {
        while (getline(fin, line)) {
            strings.push_back(line);
        }
    } else {
        fin.close();
        return false;;
    }

    fin.close();
    return true;
}

const vector<string> &FileParser::getStrings() const {
    return strings;
}
