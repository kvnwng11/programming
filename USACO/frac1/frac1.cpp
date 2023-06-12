/*
 ID: kvnwng11
 LANG: C++
 TASK: frac1
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(int argc, const char * argv[]) {
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    fin >> N;
    
    unordered_map<double, string> found_fracs;
    vector<double> sorted_fractions;

    fout << "0/1\n";

    for (int i=2; i<=N; ++i) { // i is denominator
        for (int j=1; j<i; ++j) { // j is numerator
            double fraction = (double)j / (double)i;
            if (found_fracs.find(fraction) == found_fracs.end()) {
                double fraction = (double)j / (double)i;
                string s = to_string(j) + "/" + to_string(i);
                found_fracs[fraction] = s;
                sorted_fractions.push_back(fraction);
            }
        }
    }

    sort(sorted_fractions.begin(), sorted_fractions.end());

    for (int i=0; i<sorted_fractions.size(); ++i) {
        fout << found_fracs[sorted_fractions[i]] << "\n";
    }

    fout << "1/1\n";
}