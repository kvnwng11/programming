/*
 ID: kvnwng11
 LANG: C++
 TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    
    string s1 = "", s2 = "";
    fin >> s1 >> s2;
    
    int sum1 = 1, sum2 = 1;
    for (size_t i = 0; i < s1.size(); ++i) {
        sum1 *= s1[i] - 'A' + 1;
    }
    for (size_t i = 0; i < s2.size(); ++i) {
        sum2 *= s2[i] - 'A' + 1;
    }
    
    if (sum1 % 47 == sum2 % 47) fout << "GO\n";
    else fout << "STAY\n";
    
    return 0;
}
