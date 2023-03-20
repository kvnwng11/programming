/*
 ID: kvnwng11
 LANG: C++
 TASK: hamming
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    int N, B, D;

    fin >> N >> B >> D;
    fin.close();

    vector<int> passed;
    passed.reserve(500);
    passed.push_back(0);
    N--;

    int num=1;
    while (N > 0 and num < (int) pow(2, B)) {
        bool confirmed = true;
        for (int i=0; i<passed.size() ; ++i) {
            int diff = passed[i] ^ num;

            int count_ones = 0;
            while (diff > 0 and count_ones < D) {
                count_ones += diff & 1;
                diff = diff >> 1;
            }

            if (count_ones < D) {
                confirmed = false;
                break;
            }
        }

        if (confirmed) {
            passed.push_back(num);
            N--;
        }

        num++;
    }
    
    for (int i=0; i<passed.size(); i += 10) {
        fout << passed[i];
        for (int j=i+1; j < min(i+10, (int) passed.size()); ++j) {
            fout << " " << passed[j];
        }
        fout << "\n";
    }
    fout.close();
    return 0;
}