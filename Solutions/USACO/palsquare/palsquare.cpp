/*
 ID: kvnwng11
 LANG: C++
 TASK: palsquare
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

string converter(int base, int num) {
    string output = "";
    int remainder = 0;
    const string store = "0123456789ABCDEFGHIJ";
    
    while (num > 0) {
        remainder = num%base;
        output = store[remainder] + output;
        num -= remainder;
        num /= base;
    }
    return output;
}


int main(int argc, const char * argv[]) {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    
    int base = 0;
    fin >> base;
    
    for (int i = 1; i <= 300; ++i) {
        string num = converter(base, i);
        string sqr = converter(base, i*i);
        string rev = string(sqr.rbegin(), sqr.rend());
        
        if (rev == sqr) {
            fout << num << " " << sqr << "\n";
        }
    }
    
    return 0;
}
