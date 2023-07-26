class Solution {
private:
    int add[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

    bool inBounds(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 or i >= grid.size()) return 0;
        if (j < 0 or j >= grid[0].size()) return 0;
        return 1;
    }

    void recurse(vector<vector<char>>& grid, int i, int j) {
        if (!inBounds(grid, i, j)) return;

        grid[i][j] = '2';
        for (int k=0; k<4; ++k) {
            int newRow = i+add[k][0], newCol = j+add[k][1];
            
            if (inBounds(grid, newRow, newCol) and grid[newRow][newCol] == '1')
                recurse(grid, newRow, newCol);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans=0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    recurse(grid, i, j);
                }
            }
        }
        return ans;
    }
};