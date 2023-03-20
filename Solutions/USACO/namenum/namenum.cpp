/*
 ID: kvnwng11
 LANG: C++
 TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<char>> m;

bool check(string &serial, string &name) {
    if (serial.length() != name.length()) return 0;
    
//    if (name == "ADONIA") {
//        cout << "here\n";
//    }
    
    int match = 0;
    for (size_t i = 0; i < serial.length(); ++i) {
        char c1 = name[i];
        for (size_t j = 0; j < m[serial[i]].size(); ++j) {
            char c2 = m[serial[i]][j];
            if (c1 == c2) {
                match++;
                break;
            }
        }
    }
    
    return match == serial.length();
}

int main(int argc, const char * argv[]) {
    ifstream fin("namenum.in");
    ifstream fin2("dict.txt");
    ofstream fout("namenum.out");
    
    string serial = "";
    fin >> serial;
    
    m['2'] = {'A', 'B', 'C'};
    m['3'] = {'D', 'E', 'F'};
    m['4'] = {'G', 'H', 'I'};
    m['5'] = {'J', 'K', 'L'};
    m['6'] = {'M', 'N', 'O'};
    m['7'] = {'P', 'R', 'S'};
    m['8'] = {'T', 'U', 'V'};
    m['9'] = {'W', 'X', 'Y'};
    
    string name = "";
    bool found = 0;
    
    while (fin2 >> name) {
        if (check(serial, name)) {
            fout << name << "\n";
            found = 1;
        }
    }
    
    if (!found) fout << "NONE\n";
}
