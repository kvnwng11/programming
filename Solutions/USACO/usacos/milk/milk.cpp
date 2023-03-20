/*
 ID: kvnwng11
 LANG: C++
 TASK: milk
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    
    struct p {
        int numUnits = 0;
        int cost = 0;
    };
    
    int N = 0, M = 0;
    fin >> N >> M;
    
    vector<p> costs(M);
    for (int i = 0; i < M; ++i) {
        fin >> costs[i].cost >> costs[i].numUnits;
    }
    
    int result = 0;
    while (N > 0) {
        int small = INT_MAX;
        int idx = -1;
        for (int i = 0; i < M; ++i) {
            if (costs[i].cost >= 0 and costs[i].cost < small) {
                small = costs[i].cost;
                idx = i;
            }
        }
        
        result += min(costs[idx].cost * costs[idx].numUnits, N * costs[idx].cost);
        N = max(N - costs[idx].numUnits, 0);
        
        costs[idx].cost = -1;
    }
    
    fout << result << "\n";
    
    return 0;
}
