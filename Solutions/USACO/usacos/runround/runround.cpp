/*
 ID: kvnwng11
 LANG: C++
 TASK: runround
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long ul;

ul M;

bool is_runround(ul num) {
    // convert unsigned long to string
    string s = "";
    while (num > 0) {
        char c = (num % 10) + '0';
        s = c + s;
        num /= 10;
    }

    unordered_map<char, int> counts;
    for (char c : s) {
        counts[c] += 1;
        if (counts[c] > 1)
            return 0;
    }

    bool checked[s.size()];
    for (int i = 0; i < s.size(); ++i) checked[i] = 0;

    int counter = 0;
    int ptr = 0;
    while (counter < s.size()) {
        if (checked[ptr])
            return 0;

        checked[ptr] = 1;
        ptr = (ptr + (s[ptr] - '0')) % s.size();
        counter++;
    }

    return ptr == 0 ? 1 : 0;
}

int main() {
    ifstream fin("runround.in");
    ofstream fout("runround.out");

    fin >> M;

    bool found = 0;
    ul ans = M + 1;

    while (!found) {
        if (is_runround(ans)) {
            found = 1;
            break;
        }

        ans++;
    }

    fout << ans << "\n";

    fout.close();
    return 0;
}