/*
 ID: kvnwng11
 LANG: C++
 TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
#include <math.h>
#include <unordered_set>

#define MAX_M 250

int N, M;
bool bisquares[MAX_M*MAX_M*2+1];

using namespace std;

struct my_pair {
    int a=0;
    int b=0;
};

int main(int argc, const char * argv[]) {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    
    fin >> N >> M;
    
    int upper_bound = M*M + M*M;
    
    for (int i=0; i<=M; ++i) {
        for (int j=0; j<=M; ++j) {
            bisquares[i*i + j*j] = 1;
        }
    }
    
    bool found = 0;
    for (int b=1; b<upper_bound; ++b) {
        for (int start=0; start<upper_bound; ++start) {
            if (start+(N-1)*b > upper_bound) break;
            bool e = 0;
            for (int count=0; count<N; ++count) {
                int num = start+count*b;
                if (!bisquares[num]) {
                    e = 1;
                    break;
                }
            }
            
            if (!e) {
                found = 1;
                fout << start << " " << b << "\n";
            }
        }
    }
    
    if (!found) fout << "NONE\n";
    
    return 0;
}
