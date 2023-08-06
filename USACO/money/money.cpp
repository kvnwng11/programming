/*
 ID: kvnwng11
 LANG: C++
 TASK: money
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
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<int>> vvb;
typedef vector<vector<long long>> vvll;
typedef bitset<101> bit;
typedef vector<string> vs;

#define MODULO 9901;

int main() {
    ifstream fin("money.in");
    ofstream fout("money.out");

    // Read in
    int V, N;
    fin >> V >> N;
    vi coins(V, 0);
    for (int i = 0; i < V; ++i) fin >> coins[i];

    // DP
    vvll dp(V, vll(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j - coins[i] >= 0)
                dp[i][j] += dp[i][j - coins[i]];
        }
    }

    fout << dp[V - 1][N] << endl;

    fout.close();
    return 0;
}