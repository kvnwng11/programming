/*
 ID: kvnwng11
 LANG: C++
 TASK: preface
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int N;

/*
        I   1     L   50    M  1000
        V   5     C  100
        X  10     D  500
*/

int main() {
    ifstream fin("preface.in");
    ofstream fout("preface.out");

    int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string letters[] = {"I",  "IV", "V",  "IX", "X",  "XL", "L",
                        "XC", "C",  "CD", "D",  "CM", "M"};

    fin >> N;

    int ans[7] = {0};
    char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    // go through all pages
    for (int i = 1; i <= N; ++i) {
        // convert to roman
        int ptr = 12;
        int num = i;
        while (num > 0) {
            while (num >= nums[ptr]) {
                num -= nums[ptr];

                for (char c : letters[ptr]) {
                    switch (c) {
                    case 'I': {
                        ans[0]++;
                        break;
                    }
                    case 'V': {
                        ans[1]++;
                        break;
                    }
                    case 'X': {
                        ans[2]++;
                        break;
                    }
                    case 'L': {
                        ans[3]++;
                        break;
                    }
                    case 'C': {
                        ans[4]++;
                        break;
                    }
                    case 'D': {
                        ans[5]++;
                        break;
                    }
                    case 'M': {
                        ans[6]++;
                        break;
                    }
                    }
                }
            }
            ptr--;
        }
    }

    for (int i = 0; i < 7; ++i) {
        if (ans[i] > 0) {
            fout << roman[i] << " " << ans[i] << "\n";
        }
    }

    fout.close();
    return 0;
}