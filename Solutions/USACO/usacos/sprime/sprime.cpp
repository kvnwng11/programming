/*
 ID: kvnwng11
 LANG: C++
 TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX_N 8

int nums[6] = {1, 2, 3, 5, 7, 9};
int a, b, N;
vector<int> checked;
ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool is_prime(int num) {
    if (num == 1) return 0;
    if (num == 2) return 1;
    if (num%2 == 0) return 0;
    
    for (int i=3; i<=sqrt(num); ++i) {
        if (num%i == 0) {
            return 0;
        }
    }
    return 1;
}

void gen_nums(int num, int idx) {
    if (idx == N) {
        int tmp = num;
        while (tmp > 0) {
            if (!is_prime(tmp)) {
                return;
            }
            tmp /= 10;
        }
        
        fout << num << "\n";
        return;
    }
    
    num *= 10;
    for (int i=0; i<6; ++i) {
        int tmp = num + nums[i];
        if (is_prime(tmp)) gen_nums(tmp, idx+1);
    }
}

int main(int argc, const char * argv[]) {
    fin >> N;
    
    a=pow(10, N-1);
    b=pow(10, N)-1;
    
    gen_nums(0, 0);
    
    
    return 0;
}
