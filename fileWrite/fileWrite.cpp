#include <iostream>
#include <fstream>
#include <string>
#include "filewrite.h"
using namespace std;

void fileWrite(string fileName) {
    string in = "";
    ofstream file;
    file.open(fileName, ofstream::out | ofstream::app);

    getline(cin, in);

    while (in.compare(":q") != 0) {
        file << in;
        file << "\n";
        in = "";
        getline(cin, in);
    }
    file.close();
}