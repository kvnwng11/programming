/*
 ID: kvnwng11
 LANG: C++
 TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <math.h>

using namespace std;

bool check(vector<int> &nums, int n) {
    string s = to_string(n);
    int found = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == s[i] - '0') {
                found++;
                continue;
            }
        }
    }
    
    return found == s.size();
}

int main(int argc, const char * argv[]) {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    
    int N = 0;
    fin >> N;
    
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        fin >> nums[i];
    }
    
    // generate all length 3 numbers
    vector<int> three;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                three.push_back(100 * nums[i] + 10 * nums[j] + nums[k]);
            }
        }
    }
    
    // generate all length 2 numbers
    vector<int> two;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            two.push_back(10 * nums[i] + nums[j]);
        }
    }
    
    // brute force possible answers
    int ans = 0;
    for (int i = 0; i < three.size(); ++i) {
        for (int j = 0; j < two.size(); ++j) {
            int lastd = two[j] % 10;
            int firstd = (two[j] - lastd)/10;
            if (three[i] * lastd >= 1000 or !check(nums, three[i] * lastd)) continue;
            if (three[i] * firstd >= 1000 or !check(nums, three[i] * firstd)) continue;
            if (!check(nums, three[i]*two[j])) continue;
            ans++;
        }
    }
    
    fout << ans << "\n";
    
    return 0;
}
