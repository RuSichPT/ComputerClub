#ifndef COMPUTERCLUB_FILEPARSER_H
#define COMPUTERCLUB_FILEPARSER_H

#include <vector>
#include <string>

using namespace std;

class FileParser {
public:
    explicit FileParser(const string &path);

    void split(const string &str, char delim, vector<string> &out);

    const vector<string> &getStrings() const;

private:
    vector<string> strings;

    void checkFormat(const string &str, int numberOfLine);
};


#endif //COMPUTERCLUB_FILEPARSER_H
