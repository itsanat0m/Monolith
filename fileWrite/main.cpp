#include <iostream>
#include <string>
#include "filewrite.h"
using namespace std;

int main() {
    string fileName = "";

    cout << "Enter file name: " << endl;
    cin >> fileName;
    fileName = fileName + ".md";

    fileWrite(fileName);

    return 0;

}