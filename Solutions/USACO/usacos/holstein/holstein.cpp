/*
 ID: kvnwng11
 LANG: C++
 TASK: holstein
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > feeds;
vector<vector<int> > candidate_ans;
vector<int> vit_req;
vector<int> ans;
int num_vitamins=0;
int num_feeds=0;
int sol_feeds=0;

bool my_less(vector<int> &v1, vector<int> &v2) {
    if (v1.size() < v2.size()) return 1;
    if (v1.size() > v2.size()) return 0;

    for (int i=0; i<v1.size(); ++i) {
        if (v1[i] < v2[i]) return 1;
        else if (v2[i] > v2[i]) return 0;
    }
    return 0;
}

// checks whether the current solution works
bool found_solution() {
    // sum up vitamin counts from current solution
    vector<int> curr(num_vitamins, 0);
    for (int j=0; j<ans.size(); ++j) {
        int idx = ans[j];
        for (int i=0; i<curr.size(); ++i) {
            curr[i] += feeds[idx][i];
        }
    }

    // check if sum exceeds requirements
    for (int i=0; i<num_vitamins; ++i) {
        if (vit_req[i] > curr[i]) return false;
    }

    return true;
}

// try all combinations of feeds
// there are 2 options for each feed: include or exclude
void include_exclude(int feed_idx) {
    // end of recursion
    // found solution
    if (feed_idx == num_feeds and found_solution()) {
        candidate_ans.push_back(ans);
        return;
    }
    else if (feed_idx == num_feeds) return;

    // include current feed
    ans.push_back(feed_idx);
    sol_feeds++;
    include_exclude(feed_idx+1);
    ans.pop_back();
    sol_feeds--;

    // exclude current feed
    include_exclude(feed_idx+1);
}

int main() {
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    fin >> num_vitamins;

    vit_req.resize(num_vitamins);

    for (int i=0; i<num_vitamins; ++i) {
        fin >> vit_req[i];
    }

    fin >> num_feeds;
    feeds.resize(num_feeds, vector<int>(num_vitamins));
    ans.reserve(num_feeds);
    for (int i=0; i<num_feeds; ++i) {
        for (int j=0; j<num_vitamins; ++j) {
            fin >> feeds[i][j];
        }
    }

    include_exclude(0);

    // cout << "Before sorting:\n";
    // for (int i=0; i<num_feeds; ++i) {
    //     for (int j=0; j<num_vitamins; ++j) {
    //         cout << candidate_ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    sort(candidate_ans.begin(), candidate_ans.end(), my_less);

    // cout << "After sorting:\n";
    // for (int i=0; i<num_feeds; ++i) {
    //     for (int j=0; j<num_vitamins; ++j) {
    //         cout << candidate_ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    fout << candidate_ans[0].size();
    for (int i=0; i<candidate_ans[0].size(); ++i) {
        fout << " " << (candidate_ans[0][i]+1);
    }
    fout << endl;
    return 0;
}