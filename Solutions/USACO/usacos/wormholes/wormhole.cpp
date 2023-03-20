/*
 ID: kvnwng11
 LANG: C++
 TASK: wormhole
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <math.h>

#define MAX_N 12

int N, X[MAX_N+1], Y[MAX_N+1];
int partner[MAX_N+1];
int next_on_right[MAX_N+1];

using namespace std;

bool cycle_exists() {
//    for (int i = 1; i <= N; ++i) {
//        cout << i << ": " << partner[i] << "\t";
//    }
//    cout << "\n";
    for (int start=1; start<=N; ++start) {
        // does there exist a cycle starting from start
        int pos = start;
        for (int count = 0; count < N; ++count) {
            pos = next_on_right[partner[pos]];
        }
        if (pos != 0) return 1;
    }
    
    return 0;
}

// count all solutions
int solve() {
    // find first unpaired wormhole
    int i, total = 0;
    for (i = 1; i <= N; ++i) {
        if (partner[i] == 0) break;
    }
    
    // base case: everyone paired
    if (i > N) {
        return cycle_exists();
    }
    
    // try pairing i with all possible wormholes
    for (int j = i+1; j <= N; ++j) {
        if (partner[j] == 0) {
            // try pairing i and j
            // generate the rest of the solution
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return total;
}

int main(int argc, const char * argv[]) {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    
    fin >> N;
    for (int i = 1; i <= N; ++i) {
        fin >> X[i] >> Y[i];
    }
    fin.close();
    
    // set next_on_right[i]
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (X[j] > X[i] and Y[i] == Y[j]) {
                if (next_on_right[i] == 0 or X[j]-X[i] < X[next_on_right[i]]-X[i]) {
                    next_on_right[i] = j;
                }
            }
        }
    }
    
    fout << solve() << "\n";
    fout.close();
    
    return 0;
}
