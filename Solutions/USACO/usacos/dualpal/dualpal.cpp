/*
 ID: kvnwng11
 LANG: C++
 TASK: dualpal
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

bool check(int S) {
    bool found = 0;
    for (int i = 2; i <= 10; ++i) {
        string num = converter(i, S);
        string rev = string(num.rbegin(), num.rend());
        if (num == rev) {
            if (found) return 1;
            found = 1;
        }
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    
    int N = 0, S = 0;
    fin >> N >> S;
    
    S++;
    while (N > 0) {
        if (check(S)) {
            fout << S << "\n";
            N--;
        }
        S++;
    }
    
    return 0;
}
