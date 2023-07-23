class Solution {
private:
    int m, n;
    int add[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

    bool inBounds(vector<vector<char>>& board, int row, int col) {
        if (row < 0 or row >= board.size()) return 0;
        if (col < 0 or col >= board[0].size()) return 0;
        return 1;
    }

    void DFS(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] != 'O') return;

        board[row][col] = 'E';
        for (int i=0; i<4; ++i) {
            int newRow = row + add[i][0], newCol = col + add[i][1];
            if (inBounds(board, newRow, newCol))
                DFS(board, newRow, newCol);
        }
    }   

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        m = board.size(); n = board[0].size();

        // If an 'O' cell is not connected to a border, it is surrounded

        // Get border cells
        vector<pair<int, int>> borders;
        for (int r=0; r<m; ++r) {
            borders.push_back(make_pair(r, 0));
            borders.push_back(make_pair(r, n-1));
        }
        for (int c=0; c<n; ++c) {
            borders.push_back(make_pair(0, c));
            borders.push_back(make_pair(m-1, c));
        }

        // DFS
        for (int i=0; i<borders.size(); ++i) {
            DFS(board, borders[i].first, borders[i].second);
        }

        // Capture
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == 'E')
                    board[r][c] = 'O';
            }
        }
    }
};