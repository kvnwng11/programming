/*
 ID: kvnwng11
 LANG: C++
 TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    
    int numBoards = 0, numStalls = 0, numCows = 0;
    fin >> numBoards >> numStalls >> numCows;
    
    bool occupied[numStalls+1];
    for (int i = 0; i <= numStalls; ++i) {
        occupied[i] = 0;
    }
    
    int idx = 0;
    for (int i = 0; i < numCows; ++i) {
        fin >> idx;
        occupied[idx] = 1;
    }
    
    int result = numStalls;

    int leftidx = 1;
    while (!occupied[leftidx++]) result--;
    int rightidx = numStalls;
    while (!occupied[rightidx--]) result--;
    leftidx--;
    rightidx++;
    
    // find all stretches of unoccupied stalls
    vector<int> v;
    int curr = 0;
    for (int i = leftidx; i <= rightidx; ++i) {
        if (!occupied[i]) curr++;
        else {
            if (curr != 0) v.push_back(curr);
            curr = 0;
        }
    }
    
    sort(v.begin(), v.end());
    
    int end = numBoards-1 < v.size()? numBoards-1: v.size();
    for (size_t i = 0; i < end; ++i) {
        result -= v[v.size() - 1 - i];
    }
    
    fout << result << "\n";
    
    return 0;
}
