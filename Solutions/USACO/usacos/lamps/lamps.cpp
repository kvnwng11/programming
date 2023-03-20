/*
 ID: kvnwng11
 LANG: C++
 TASK: lamps
*/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef bitset<101> bit;

int N;
int C;
bit off, on;
vector<bit> sols;

void switches(bit &lamps, int option) {
    switch (option) {
    case 1: {
        lamps = ~lamps;
        return;
    }
    case 2: {
        for (int i = 1; i <= 100; i += 2) lamps.flip(i);
        return;
    }
    case 3: {
        for (int i = 2; i <= 100; i += 2) lamps.flip(i);
        return;
    }
    case 4: {
        for (int i = 1; i <= 100; i += 3) lamps.flip(i);
        return;
    }
    }
}

bool final(bit lamps) {
    for (int i = 1; i <= 100; ++i) {
        if (on[i] and !lamps[i])
            return 0;
        if (off[i] and lamps[i])
            return 0;
    }
    return 1;
}

void search(bit lamps, int counter) {
    if (counter == C) {
        if (find(sols.begin(), sols.end(), lamps) == sols.end() and
            final(lamps)) {
            sols.push_back(lamps);
        }
        return;
    }

    for (int i = 1; i <= 4; ++i) {
        switches(lamps, i);
        search(lamps, counter + 1);
        switches(lamps, i);
    }
}

int main() {
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");

    fin >> N >> C;

    int input = -1;
    while (fin >> input and input != -1) on.set(input);
    while (fin >> input and input != -1) off.set(input);

    bit lamps;
    lamps = ~lamps;
    C = C > 4 ? 4 : C;
    search(lamps, 0);

    sort(sols.begin(), sols.end(), [](const auto &lhs, const auto &rhs) {
        for (int i = 1; i <= 100; ++i) {
            if (!lhs[i] and rhs[i])
                return 1;
            if (lhs[i] and !rhs[i])
                return 0;
        }
        return 1;
    });

    if (sols.size() == 0) {
        fout << "IMPOSSIBLE\n";
    }

    for (int i = 0; i < sols.size(); ++i) {
        for (int j = 1; j <= N; ++j) {
            fout << sols[i][j];
        }
        fout << "\n";
    }

    fout.close();
    return 0;
}