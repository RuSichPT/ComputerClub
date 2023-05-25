#include "FileParser.h"
#include <fstream>
#include <sstream>
#include <regex>

FileParser::FileParser(const string &path) {
    ifstream fin;
    fin.open(path);

    if (fin.is_open()) {
        string line;
        while (getline(fin, line)) {
            checkFormat(line, strings.size());
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

void FileParser::checkFormat(const string &str, int numberOfLine) {
    static regex r;
    if (numberOfLine == 0 || numberOfLine == 2) {
        r.assign(R"(\d+)");
    } else if (numberOfLine == 1) {
        r.assign(R"(\d{2}[:]\d{2} \d{2}[:]\d{2})");
    } else {
        r.assign(R"(\d{2}[:]\d{2} \d{1} [a-z\d_-]+\s?\d*)");
    }

    if (!regex_match(str, r)) {
        throw runtime_error(str);
    }
}
