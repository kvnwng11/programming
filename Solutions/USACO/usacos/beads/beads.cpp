/*
 ID: kvnwng11
 LANG: C++
 TASK: beads
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    
    int N = 0;
    string necklace = "";
    
    fin >> N >> necklace;
    
    int left = 0, right = 0, ans = 0;
    
    for (int i = 0; i < necklace.size()-1; ++i) {
        if (necklace[i] != necklace[i+1]) {
            left = i;
            right = i+1;
            int leftcount = 0;
            int rightcount = 0;
            
            char leftc = necklace[left];
            char rightc = necklace[right];
            
            if (leftc == 'b') rightc = 'r';
            if (leftc == 'r') rightc = 'b';
            if (rightc == 'b') leftc = 'r';
            if (rightc == 'r') leftc = 'b';
            
            while (leftcount < necklace.length() and necklace[left] != rightc) {
                leftcount++;
                left = (left-1 + (int) necklace.length()) % (int) necklace.length();
            }
            while (rightcount < necklace.length() and necklace[right] != leftc) {
                rightcount++;
                right = (right+1) % necklace.length();
            }
            
            if (leftcount+rightcount > ans) ans = leftcount+rightcount;
        }
    }
    
    if (ans > necklace.length() or ans == 0) fout << necklace.length() << "\n";
    else fout << ans << "\n";
    return 0;
}
