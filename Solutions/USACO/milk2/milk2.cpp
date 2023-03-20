/*
 ID: kvnwng11
 LANG: C++
 TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <climits>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    
    int N = 0;
    
    fin >> N;
    
    unordered_map<int, int> starttimes;
    unordered_map<int, int> endtimes;
    
    int begin = INT_MAX;
    int end = INT_MIN;
    
    for (size_t i = 0; i < N; ++i) {
        int s, e;
        fin >> s >> e;
        starttimes[s] += 1;
        endtimes[e] += 1;
        
        if (s < begin) begin = s;
        if (e > end) end = e;
    }
    
    int ans1 = 0, ans2 = 0, numMilking = 0;
    int curr1 = 0, curr2 = 0;
    
    for (int time = begin; time <= end; ++time) {
        if (starttimes[time]) {
            numMilking += starttimes[time];
        }
        if (endtimes[time]) {
            numMilking -= endtimes[time];
        }
        
        if (numMilking == 0) {
            if (curr1 > ans1) ans1 = curr1;
            curr1 = 0;
            curr2++;
        }
        else {
            if (curr2 > ans2) ans2 = curr2;
            curr2 = 0;
            curr1++;
        }
    }
    
    fout << ans1 << " " << ans2 << "\n";
}
