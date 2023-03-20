/*
 ID: kvnwng11
 LANG: C++
 TASK: combo
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <math.h>

using namespace std;

class Solution {
private:
    vector<int> fj;
    vector<int> master;
    vector<int> v;
    int ans = 0;
    int N = 0;
    
    int dist(int num1, int num2) {
        if (num1 == N and num2 <= 2) return num2;
        else if (num1 == N-1 and num2 == 1) return 2;
        else if (num2 == N and num1 <= 2) return num1;
        else if (num2 == N-1 and num1 == 1) return 2;
        return abs(num1 - num2) % N;
    }
    
    bool check() {
        bool broken = 0;
        // check fj
        for (int i = 0; i < v.size(); ++i) {
            if (dist(v[i], fj[i]) > 2) {
                broken = 1;
                break;
            }
        }
        if (!broken) return 1;
        
        // check master
        broken = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (dist(v[i], master[i]) > 2) {
                broken = 1;
                break;
            }
        }
        if (!broken) return 1;
        return 0;
    }
    
public:
    Solution(int num, vector<int> &f, vector<int> &m): N(num) {
        v.resize(3);
        for (int i = 0; i < f.size(); ++i) {
            fj.push_back(f[i]);
            master.push_back(m[i]);
        }
    }
    
    void count() {
        for (int i = 1; i <= N; ++i) {
            v[0] = i;
            for (int j = 1; j <= N; ++j) {
                v[1] = j;
                for (int k = 1; k <= N; ++k) {
                    v[2] = k;
                    if (check()) {
                        //cout << v[0] << " " << v[1] << " " << v[2] << endl;
                        ans++;
                    }
                }
            }
        }
    }
    
    int getAns() const { return ans; }
    
    ~Solution() {}
};

int main(int argc, const char * argv[]) {
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    
    int N = 0;
    fin >> N;
    
    vector<int> f(3);
    for (int i = 0; i < 3; ++i) {
        fin >> f[i];
    }
    vector<int> m(3);
    for (int i = 0; i < 3; ++i) {
        fin >> m[i];
    }
    
    Solution ans(N, f, m);
    ans.count();
    fout << ans.getAns() << "\n";
    
    return 0;
}
