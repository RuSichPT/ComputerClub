#include "FileParser.h"
#include <fstream>
#include <sstream>

FileParser::FileParser(const string &path) {
    ifstream fin;
    fin.open(path);

    if (fin.is_open()) {
        string line;
        while (getline(fin, line)) {
            strings.push_back(line);
        }
        fin.close();
        return;
    }

    fin.close();
    throw runtime_error("File open error");
}

const vector<string> &FileParser::getStrings() const {
    return strings;
}

void FileParser::split(const string &str, char delim, vector<string> &out) {
    stringstream ss(str);
    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}
