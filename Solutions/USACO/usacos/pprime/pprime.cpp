/*
 ID: kvnwng11
 LANG: C++
 TASK: pprime
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 20

int a, b;
int min_length, max_length;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

bool is_prime(int num) {
    if (num == 1) return 0;
    if (num % 2 == 0) return 0;
    for (int i=2; i<=sqrt(num); ++i) {
        if (num % i == 0) return 0;
    }
    return 1;
}

string gen_odd(string num) {
    string minus_one(num.begin(), num.begin()+(num.size()-1));
    string s(minus_one.rbegin(), minus_one.rend());
    return num + s;
}

string gen_even(string num) {
    string rev(num.rbegin(), num.rend());
    return num + rev;
}

void gen_palindromes(int length) {
    int small = pow(10, length/2);
    int big = pow(10, length/2+1);
    
    for (int i=small; i<big; ++i) {
        string s = length%2==0? gen_even(to_string(i)): gen_odd(to_string(i));
        if (s.size() > 9) return;
        int n = stoi(s);
        if (a <= n and n <= b and is_prime(n)) {
            fout << n << "\n";
        }
    }
}

int main(int argc, const char * argv[]) {
    fin >> a >> b;
    min_length = int(to_string(a).size());
    max_length = int(to_string(b).size());
    
    if (a <= 5 and 5 <= b) fout << 5 << "\n";
    if (a <= 7 and 7 <= b) fout << 7 << "\n";
    if (a <= 11 and 11 <= b) fout << 11 << "\n";
    
    for (int i=min_length; i<=max_length; ++i) {
        if (i > 1)
            gen_palindromes(i);
    }
    
    return 0;
}
