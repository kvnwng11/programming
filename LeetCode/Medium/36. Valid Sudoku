class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> boxes; 

        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                char num = board[i][j];

                if (num == '.')
                    continue;

                if (rows[i].find(num) != rows[i].end())
                    return 0;
                rows[i].insert(num);

                if (cols[j].find(num) != cols[j].end())
                    return 0;
                cols[j].insert(num);

                int box =  (i / 3) *3 + (j / 3);
                if (boxes[box].find(num) != boxes[box].end())
                    return 0;
                boxes[box].insert(num);
            }
        }

        return 1;
    }
};