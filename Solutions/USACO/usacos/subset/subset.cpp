/*
 ID: kvnwng11
 LANG: C++
 TASK: subset
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N;

int main() {
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    fin >> N;

    int sum = (N + 1) * N / 2;

    if (sum % 2 == 1) {
        fout << 0 << "\n";
        fout.close();
        return 0;
    }

    int target = sum / 2;

    // initialize
    ll dp[N + 1][target + 1];
    for (int j = 0; j <= target; ++j) {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = 1;
    }

    // dp
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= target; ++j) {
            ll include = 0;
            ll exclude = dp[i - 1][j];

            if (j - i >= 0) {
                include = dp[i - 1][j - i];
            }

            dp[i][j] = include + exclude;
        }
    }

    fout << dp[N][target] / 2 << "\n";

    fout.close();
    return 0;
}