class Solution {
private:
    vector<bool> rows;
    vector<bool> diagLR;
    vector<bool> diagRL;
    int ans = 0;
    int N = 0;

public:
    bool canPlace(int i, int j) {
        if (rows[i]) return 0;
        if (diagRL[i+j]) return 0;

        int idx = i - j + N;
        if (diagLR[idx]) return 0;

        return 1;
    }

    void recurse(int j) {
        //cout << j << endl;

        // Check if N queens are placed
        if (j >= N) {
            ans++;
            return;
        }

        // loop through rows
        for (int i=0; i < N; ++i) {
            if (canPlace(i, j)) {
                cout << i << " " << j << endl;

                // place queen
                rows[i] = 1;
                diagRL[i+j] = 1;
                int idx = i - j + N;
                diagLR[idx] = 1;

                // try next column
                recurse(j+1);

                // unplace queen
                rows[i] = 0;
                diagRL[i+j] = 0;
                diagLR[idx] = 0;
            }
        }
    }


    int totalNQueens(int n) {
        rows.resize(n);
        diagLR.resize(2*n);
        diagRL.resize(2*n);
        N = n;
        recurse(0);
        return ans;
    }
};