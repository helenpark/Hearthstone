

#include "print.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void print(vector<string> display) {
    int a = display.size();
    for (int i=0; i<a; ++i) {
        string line = display[i];
        cout << line << endl;
    }
}
