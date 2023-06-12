/*
 ID: kvnwng11
 LANG: C++
 TASK: skidesign
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
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    
    int N = 0;
    fin >> N;
    
    int heights[N];
    int small = INT_MAX, big = INT_MIN;
    for (int i = 0; i < N; ++i) {
        fin >> heights[i];
        if (heights[i] < small) small = heights[i];
        if (heights[i] > big) big = heights[i];
    }
    
    int top = small+17, ans = INT_MAX;
    while (top <= big) {
        int curr_cost = 0;
        
        for (int i = 0; i < N; ++i) {
            if (heights[i] < small) curr_cost += (small-heights[i]) * (small-heights[i]);
            else if (heights[i] > top) curr_cost += (heights[i]-top) * (heights[i]-top);
        }
        
        ans = min(ans, curr_cost);
        small++;
        top++;
    }
    
    fout << ans << "\n";
    
    return 0;
}
