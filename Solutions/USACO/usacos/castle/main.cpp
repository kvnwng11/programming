/*
 ID: kvnwng11
 TASK: castle
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int> > grid;
    vector<vector<bool> > visited;
    vector<vector<int> > assignment;
    int room_sizes[100000];
    int M, N;
    int num_rooms;
    int largest_room_size;
    int remove_row;
    int remove_col;
    char remove_direction;
    int largest_removed_size;

    void assign_room_helper(int row, int col, int room_number) {
        // cout << row << " " << col << endl;
        if (M == 51 or N == 51) {
            cout << row << " " << col << endl;
            return;
        }
        //cout << M << " " << N << endl;
        // cout << (M <= col or col < 0) << endl;

        if (M <= col or col < 0) return;
        if (N <= row or row < 0) return;

        //cout << row << " " << col << " valid\n";
        if (visited[row][col]) return;
        visited[row][col] = 1;
        assignment[row][col] = room_number;
        room_sizes[room_number]++;
        int wall = grid[row][col];

        // check south
        if (wall >= 8) wall -= 8;
        else assign_room_helper(row+1, col, room_number);

        // check east
        if (wall >= 4) wall -= 4;
        else assign_room_helper(row, col+1, room_number);

        // check north
        if (wall >= 2) wall -= 2;
        else  assign_room_helper(row-1, col, room_number);

        // check west
        if (wall < 1) assign_room_helper(row, col-1, room_number);
    }

    void set_largest(char direction, int i, int j) {
        int curr_room = assignment[i][j];

        bool new_largest = false;
        int joined_room_size = 0;

        if (direction == 'S') {
            if (i+1 < N and assignment[i+1][j] != curr_room){
                joined_room_size = room_sizes[curr_room] + room_sizes[assignment[i+1][j]];
            }
        }
        else if (direction == 'N') {
            if (i-1 >=0 and assignment[i-1][j] != curr_room){
                joined_room_size = room_sizes[curr_room] + room_sizes[assignment[i-1][j]];
            }
        }
        else if (direction == 'E') {
            if (j+1 < M and assignment[i][j+1] != curr_room){
                joined_room_size = room_sizes[curr_room] + room_sizes[assignment[i][j+1]];
            }
        }
        else {
            if (j-1 >=0 and assignment[i][j-1] != curr_room){
                joined_room_size = room_sizes[curr_room] + room_sizes[assignment[i][j-1]];
            }
        }

        if (joined_room_size > largest_removed_size) {
            remove_row = i;
            remove_col = j;
            remove_direction = direction;
            largest_removed_size = joined_room_size;
        }
    }

public:
    Solution() :
     num_rooms(0), largest_room_size(0), largest_removed_size(0) {
        ifstream fin("castle.in");

        fin >> M >> N;
        remove_row = N-1;
        remove_col = M-1;

        grid.reserve(M);
        visited.reserve(M);
        assignment.reserve(M);

        for (int i=0; i<N; ++i) {
            vector<int> e(M, 0);
            vector<bool> t(M, 0);
            grid.push_back(e);
            visited.push_back(t);
            assignment.push_back(e);
            for (int j=0; j<M; ++j) {
                fin >> grid[i][j];
            }
        }

        for (int i=0; i<100; ++i) {
            room_sizes[i] = 0;
        }
    }

    void assign_rooms() {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (!visited[i][j]) {
                    assign_room_helper(i, j, num_rooms);
                    largest_room_size = max(largest_room_size, room_sizes[num_rooms]);
                    num_rooms++;
                }
            }
        }
    }

    void remove() {
        for (int j=0; j<M; ++j) {
            for (int i=N-1; i>=0; --i) {
                int wall = grid[i][j];

                // check south
                if (wall >= 8) {
                    if (i < N-1)
                        set_largest('S', i, j);
                    wall -= 8;
                }

                int tmp = wall;
                if (wall >= 4) {
                    tmp = wall-4;
                }

                // check north
                if (tmp >= 2) {
                    if (i > 0)
                        set_largest('N', i, j);
                    wall -= 2;
                }

                // check east
                if (wall >= 4) {
                    if (j < M-1)
                        set_largest('E', i, j);
                    wall -= 4;
                }

                // check west
                if (wall >= 1) {
                    if (j > 0)
                        set_largest('W', i, j);
                }
            }
        }
    }

    void print() {
        ofstream fout("castle.out");
        fout << num_rooms << endl;
        fout << largest_room_size << endl;
        fout << largest_removed_size << endl;
        fout << remove_row+1 << " " << remove_col+1 << " " << remove_direction << endl;
    }
};

int main() {
    Solution s;
    s.assign_rooms();
    s.remove();
    s.print();
    
    return 0;
}