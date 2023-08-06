/*
 ID: kvnwng11
 LANG: C++
 TASK: prefix
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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<int>> vvb;
typedef bitset<101> bit;
typedef vector<string> vs;

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    // Read in
    vs primitives;
    string buf, S = "";
    while (fin >> buf and buf != ".") primitives.push_back(buf);
    while (fin >> buf) S += buf;

    // cout << S << endl;

    // DP
    vb dp(S.size(), 0);
    int ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        // Can place primitive starting at i
        for (auto p : primitives) {
            if (i + p.size() > S.size())
                continue;

            if (i == 9) {
                // cout << "Check: " << p << endl;
            }

            // Match
            bool diff = 0;
            for (int j = 0; j < p.size(); ++j) {
                if (i == 9) {
                    // cout << p[j] << " " << S[i + j] << endl;
                }
                if (p[j] != S[i + j]) {
                    diff = 1;
                    break;
                }
            }

            // Remember
            if (!diff) {
                int idx = i + p.size() - 1;

                dp[idx] = i == 0 ? 1 : dp[idx] || dp[i - 1];
                if (i == 9) {
                    // cout << "idx: " << idx << endl;
                    // cout << "dp[idx]: " << dp[idx] << endl;
                }
                if (dp[idx]) {
                    ans = max(ans, idx);
                }
            }
        }
    }

    // for (int i = 0; i < S.size(); ++i) cout << dp[i] << " ";
    // cout << endl;

    ans = ans == 0 ? -1 : ans;
    fout << ans + 1 << endl;

    fout.close();
    return 0;
}