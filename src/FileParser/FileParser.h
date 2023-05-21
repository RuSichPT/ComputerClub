#ifndef COMPUTERCLUB_FILEPARSER_H
#define COMPUTERCLUB_FILEPARSER_H

#include <vector>
#include <string>

using namespace std;

class FileParser {
public:
    bool parse(const string &path);

    const vector<string> &getStrings() const;

private:
    vector<string> strings;
};


#endif //COMPUTERCLUB_FILEPARSER_H
