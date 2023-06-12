/*
 ID: kvnwng11
 LANG: C++
 TASK: transform
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkOne(vector<vector<char>> &v1, vector<vector<char>> &v2) {
    int row2 = 0, col2 = (int) v2.size()-1;
    
    for (size_t row1 = 0; row1 < v1.size(); ++row1) {
        row2 = 0;
        for (size_t col1 = 0; col1 < v1.size(); ++col1) {
            char a = v1[row1][col1];
            char b = v2[row2][col2];
            if (a != b) return 0;
            
            row2++;
        }
        col2--;
    }
    
    return 1;
}

bool checkTwo(vector<vector<char>> &v1, vector<vector<char>> &v2) {
    int row2 = (int) v1.size()-1, col2 = (int) v2.size()-1;
    
    for (size_t row1 = 0; row1 < v1.size(); ++row1) {
        col2 = (int) v2.size()-1;
        for (size_t col1 = 0; col1 < v1.size(); ++col1) {
            if (v1[row1][col1] != v2[row2][col2]) return 0;
            
            col2--;
        }
        row2--;
    }
    
    return 1;
}

bool checkThree(vector<vector<char>> &v1, vector<vector<char>> &v2) {
    return checkOne(v2, v1);
}

bool checkFour(vector<vector<char>> &v1, vector<vector<char>> &v2) {
    int n = (int) v1.size();
    for (size_t row1 = 0; row1 < v1.size(); ++row1) {
        for (size_t col1 = 0; col1 < v1.size(); ++col1) {
            if (v1[row1][col1] != v2[row1][n - col1 - 1]) return 0;
        }
    }
    
    return 1;
}

bool checkFive(vector<vector<char>> &v1, vector<vector<char>> &v2) {
    int n = (int) v1.size();
    for (size_t row1 = 0; row1 < v1.size(); ++row1) {
        for (size_t col1 = 0; col1 < v1.size()/2; ++col1) {
            swap(v1[row1][col1], v1[row1][n - col1 - 1]);
        }
    }
    
    return checkOne(v1, v2) or checkTwo(v1, v2) or checkThree(v1, v2);
}

bool checkSix(vector<vector<char>> &v1, vector<vector<char>> &v2) {
    for (size_t row1 = 0; row1 < v1.size(); ++row1) {
        for (size_t col1 = 0; col1 < v1.size(); ++col1) {
            if (v1[row1][col1] != v2[row1][col1]) return 0;
        }
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    
    int N = 0;
    fin >> N;
    
    vector<vector<char>> orig(N, vector<char>(N, 0));
    vector<vector<char>> trans(N, vector<char>(N, 0));
    
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            fin >> orig[i][j];
        }
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            fin >> trans[i][j];
        }
    }
    
    if (checkOne(orig, trans)) {
        fout << "1\n";
        return 0;
    }
    else if (checkTwo(orig, trans)) {
        fout << "2\n";
        return 0;
    }
    else if (checkThree(orig, trans)) {
        fout << "3\n";
        return 0;
    }
    else if (checkFour(orig, trans)) {
        fout << "4\n";
        return 0;
    }
    else if (checkFive(orig, trans)) {
        fout << "5\n";
        return 0;
    }
    else if (checkSix(orig, trans)) {
        fout << "6\n";
        return 0;
    }
    
    fout << "7\n";
    return 0;
}
