/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

/*
[1,1,0,0]
[0,0,1,1]
[1,1,0,0]
[0,0,1,1]
*/

class Solution {
public:
    bool check(vector<vector<int>>& grid, int startRow, int endRow, int startCol, int endCol) {
        if (startRow+1 == endRow and startCol+1 == endCol)
            return 1;
        
        int num = 0;
        int sum = 0;
        for (int i=startRow; i<endRow; ++i) {
            for (int j=startCol; j<endCol; ++j) {
                num += grid[i][j];
                sum++;
            }
        }
        return num == 0 or num == sum;
    }

    Node* divide(vector<vector<int>>& grid, int startRow, int endRow, int startCol, int endCol) {
        if(check(grid, startRow, endRow, startCol, endCol)) {
            return new Node(grid[startRow][startCol], true);
        }
        
        Node* curr = new Node(1, false);
        int colMid = startCol + (endCol - startCol)/2;
        int rowMid = startRow + (endRow - startRow)/2;
        curr->topLeft = divide(grid, startRow, rowMid, startCol, colMid);
        curr->topRight = divide(grid, startRow, rowMid, colMid, endCol);
        curr->bottomLeft = divide(grid, rowMid, endRow, startCol, colMid);
        curr->bottomRight = divide(grid, rowMid, endRow, colMid, endCol);
        return curr;
    }

    Node* construct(vector<vector<int>>& grid) {
        return divide(grid, 0, grid.size(), 0, grid.size());
    }
};