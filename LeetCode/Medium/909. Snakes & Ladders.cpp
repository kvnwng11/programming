class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // Create adj list
        int n = board.size();
        vector<pair<int, int>> cells(n*n+1);
        int square = 1, level = 0;
        for (int i=board.size()-1; i>=0; --i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (level % 2 == 0)
                    cells[square++] = {i, j};
                else
                    cells[square++] = {i, n-j-1};
            }
            level++;
        }

        // BFS
        deque<int> d;
        vector<int> dist(n*n + 1, -1);
        dist[1] = 0;
        d.push_back(1);
        while (!d.empty()) {
            int curr = d.front();
            d.pop_front();

            for (int next=curr+1; next <= min(curr+6, n*n); ++next) {
                auto [row, col] = cells[next];
                int dest = board[row][col] == -1? next: board[row][col];

                if (dist[dest] == -1) {
                    dist[dest] = dist[curr] + 1;
                    d.push_back(dest);
                }
            }
        }

        return dist[n*n];
    }
};