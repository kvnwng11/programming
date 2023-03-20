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
typedef vector<string> vs;

// Checks if p can appear in s while ending at index idx
bool can_add_primitive(string &s, string &p, size_t idx) {
    size_t prim_length = p.size();
    if (prim_length > idx + 1)
        return 0;
    size_t counter = 0;
    for (size_t i = idx + 1 - prim_length; i <= idx; ++i) {
        if (s[i] != p[counter++])
            return 0;
    }
    return 1;
}

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    // Read in
    vs primitives;
    string buf;
    while (fin >> buf and buf != ".") primitives.push_back(buf);
    string S;
    fin >> S;

    // Initialize
    int dp[primitives.size()][S.size()];
    for (size_t i = 0; i < primitives.size(); ++i) {
        for (size_t j = 0; j < S.size(); ++j) {
            dp[i][j] = 0;
        }
    }

    // DP
    for (size_t i = 0; i < primitives.size(); ++i) {
        size_t prim_length = primitives[i].size();
        for (size_t j = 0; j < S.size(); ++j) {
            // Check if can add primitive
            if (can_add_primitive(S, primitives[i], j)) {
                // Find longest previous prefix
                int biggest = dp[0][j + 1 - prim_length];
                for (size_t row = 1; row < i; ++row) {
                    biggest = max(dp[row][j - prim_length], biggest);
                }
                dp[i][j] = biggest + 1;
            }
        }
    }

    int biggest = dp[0][S.size()];
    for (size_t row = 1; row < primitives.size(); ++row) {
        biggest = max(dp[row][S.size()], biggest);
    }
    fout << biggest << endl;

    fout.close();
    return 0;
}