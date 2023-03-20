

#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;

bool single(vb &s, size_t col, bitset<3> vals) {
    // cout << "Cond: " << (s[col] == vals[0]) << endl;
    if (s[col] == vals[0])
        return vals[1];
    else
        return vals[2];
}

bool d(vb &s, size_t col1, size_t col2, bitset<5> &vals) {
    if (s[col1] == vals[0])
        return vals[1];
    else if (s[col2] == vals[2])
        return vals[3];
    else
        return vals[4];
}

void solve() {
    size_t N, M;
    cin >> N >> M;

    vvb bins(M, vb(N));
    vb res(M);

    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        // cout << s << " ";
        vb temp;
        for (auto a : s) temp.push_back(a == '1');

        bins[i] = temp;
        bool b;
        cin >> b;
        // cout << b << endl;
        res[i] = b;
    }

    // brute force

    // single if
    for (int i = 0; i < 8; ++i) {
        bitset<3> vals(i);
        int num_right = 0;
        // cout << "Vals: " << vals << endl;
        for (int col = 0; col < N; ++col) {
            // cout << "New cond\n";
            for (int row = 0; row < M; ++row) {
                if (single(bins[row], col, vals) == res[row]) {
                    num_right++;
                } else {
                    break;
                }
            }

            if (num_right == M) {
                cout << "OK\n";
                return;
            }
        }
    }

    // double if
    for (int i = 0; i < 32; ++i) {
        bitset<5> vals(i);
        int num_right = 0;
        for (int col1 = 0; col1 < N; ++col1) {
            for (int col2 = col1 + 1; col2 < N; ++col2) {
                for (int row = 0; row < M; ++row) {
                    if (d(bins[row], col1, col2, vals) == res[row]) {
                        num_right++;
                    } else {
                        break;
                    }
                }

                if (num_right == M) {
                    cout << "OK\n";
                    return;
                }
            }
        }
    }

    cout << "LIE\n";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}