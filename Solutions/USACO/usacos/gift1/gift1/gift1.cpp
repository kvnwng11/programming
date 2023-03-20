/*
 ID: kvnwng11
 LANG: C++
 TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    
    int NP = 0;
    fin >> NP;
    
    string names[NP];
    map<string, int> balances;
    
    for (size_t i = 0; i < NP; ++i) {
        fin >> names[i];
        balances[names[i]] = 0;
    }
    
    string giver = "";
    string reciever = "";
    int giftamount = 0;
    int numrecievers = 0;
    for (size_t i = 0; i < NP; ++i) {
        fin >> giver >> giftamount >> numrecievers;
        
        if (numrecievers == 0 or giftamount == 0) continue;
        
        balances[giver] -= giftamount;
        int num_to_give = giftamount / numrecievers;
        
        balances[giver] += giftamount % (num_to_give * numrecievers);
        
        for (size_t j = 0; j < numrecievers; ++j) {
            fin >> reciever;
            balances[reciever] += num_to_give;
        }
    }
    
    for (size_t i = 0; i < NP; ++i) {
        fout << names[i] << " " << balances[names[i]] << "\n";
    }
    
    return 0;
}
