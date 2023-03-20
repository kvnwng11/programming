/*
 ID: kvnwng11
 LANG: C++
 TASK: numtri
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define MAX 20

int R;

int main(int argc, const char * argv[]) {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    
    fin >> R;
    
    vector<vector<int>> tri(R, vector<int>(R, 0));
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 0; j < i; ++j) {
            fin >> tri[i-1][j];
        }
    }
    
    vector<int> dp = tri[tri.size()-1];
    
    for (int i=R-2; i>=0; --i) {
        vector<int> temp(dp.size()-1, 0);
        for (int j=0; j<dp.size()-1; ++j) {
            temp[j] = tri[i][j] + max(dp[j], dp[j+1]);
        }
        dp = temp;
    }
    
    int ans = 0;
    for (int i:dp) {
        ans = max(ans, i);
    }
    
    fout << ans << "\n";
    
    return 0;
}
