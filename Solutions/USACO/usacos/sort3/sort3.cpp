/*
 ID: kvnwng11
 LANG: C++
 TASK: sort3
*/

#include <iostream>
#include <fstream>
using namespace std;


int N;
int orig[1000];
int sorted[1000];
int wrong_places[3][3];
int counts[3] = {0, 0, 0};
int ans = 0;

// Returns the sorted array
void sort() {
    for (int i=0; i<counts[0]; ++i) {
        sorted[i] = 1;
    }
    for (int i=counts[0]; i<counts[0]+counts[1]; ++i) {
        sorted[i] = 2;
    }
    for (int i=counts[0]+counts[1]; i<counts[0]+counts[1]+counts[2]; ++i) {
        sorted[i] = 3;
    }
}

// num = 0, 1, 2
// Counts the out of place digits
// Ex. Counts 2's and 3's in the 1's place
void count() {
    for (int num=0; num<=2; ++num) {
        // initialize
        wrong_places[num][0] = wrong_places[num][1] = wrong_places[num][2] = 0;

        // start_idx is the beginning index of num in the sorted array
        // end_idx is the end index of num in the sorted array
        int start_idx = 0, end_idx = 0;
        for (int i=0; i<num; ++i) {
            start_idx += counts[i];
        }
        for (int i=0; i<=num; ++i) {
            end_idx += counts[i];
        }

        //cout << "idxs: " << start_idx << " " << end_idx << endl;

        // Counts the number of wrongly placed numbers
        for (int i=start_idx; i<end_idx; ++i) {
            int orig_num = orig[i]-1;
            if (orig_num != num) wrong_places[num][orig_num]++;
        }
    }
}


void swap_pairs() {
    for (int i=0; i<=2; ++i) {
        for (int j=0; j<=2; ++j) {
            if (i == j) continue;

            // In the correct section of two unique numbers, 
            // swap the pairs of numbers
            int i_in_j = wrong_places[i][j];
            int j_in_i = wrong_places[j][i];
            int smallest = min(j_in_i, i_in_j);
            // cout << "smallest: " << smallest << endl;
            // cout << i << " " << j << endl;

            ans += smallest;

            wrong_places[i][j] -= smallest;
            wrong_places[j][i] -= smallest;
        }
    }
}

void swap_cycles() {
    // for (int i=0; i<=2; ++i) {
    //     for (int j=0; j<=2; ++j) {
    //         cout << wrong_places[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int count=0;
    for (int i=0; i<=2; ++i) {
        count += wrong_places[0][i];
    }
    ans += 2*count;
}

int main(int argc, const char * argv[]) {
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    fin >> N;
    
    int raw_input;
    for (int i = 0; i < N; ++i) {
        fin >> raw_input;
        orig[i] = raw_input;
        switch(raw_input) {
            case 1:
                counts[0]++;
                break;
            case 2:
                counts[1]++;
                break;
            case 3:
                counts[2]++;
                break;
        }
    }
    
    //sort();
    count();
    swap_pairs();
    swap_cycles();
    
    
    // for (int i=0; i<N; ++i) {
    //     cout << orig[i] << " ";
    // }
    // cout << endl;
    // for (int i=0; i<N; ++i) {
    //     cout << sorted[i] << " ";
    // }
    // cout << endl;

    fout << ans << endl;
    
    return 0;
}