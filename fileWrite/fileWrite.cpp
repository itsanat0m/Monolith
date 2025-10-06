#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fileWrite(string fileName) {
    string in = "";
    ofstream file(fileName);

    while (in.compare(":q") != 0) {
        file << in;
        getline(cin, in);
        
    }
}