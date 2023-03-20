/*
 ID: kvnwng11
 LANG: C++
 TASK: milk3
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define MAX 20

struct State {
    int amts[3];
};

int maxes[3];
vector<int> ans;
bool seen[MAX+1][MAX+1][MAX+1];

State pour(State s, int from, int to) {
    if (from == to or s.amts[from] == 0) return s;
    
    State r = s;
    int need_to_pour = min(s.amts[from], maxes[to] - s.amts[to]);
    r.amts[to] += need_to_pour;
    r.amts[from] -= need_to_pour;
    
    return r;
}

void solve(State s) {
    if (seen[s.amts[0]][s.amts[1]][s.amts[2]]) return;
    seen[s.amts[0]][s.amts[1]][s.amts[2]] = 1;
    
    if (s.amts[0] == 0) ans.push_back(s.amts[2]);
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            solve(pour(s, i, j));
        }
    }
}

int main(int argc, const char * argv[]) {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    
    fin >> maxes[0] >> maxes[1] >> maxes[2];
    
    State s;
    s.amts[0] = s.amts[1] = 0;
    s.amts[2] = maxes[2];
    
    solve(s);
    
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i=0; i<ans.size()-1; ++i) {
        fout << ans[i] << " ";
    }
    fout << ans[ans.size()-1] << "\n";
    
    return 0;
}
