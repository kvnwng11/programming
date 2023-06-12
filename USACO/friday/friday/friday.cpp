/*
 ID: kvnwng11
 LANG: C++
 TASK: friday
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 != 0 and year % 4 == 0) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    
    int numDays[12] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    
    // index 0 is saturday
    int occurences[7] = {0, 0, 0, 0, 0, 0, 0};
   
    int N = 0;
    fin >> N;
    int day = 0;
    
    for (size_t year = 1900; year < 1900 + N; ++year) {
        numDays[1] = 28;
        if (isLeapYear((int) year)) numDays[1] = 29;
        
        for (size_t month = 0; month < 12; ++month) {
            occurences[day] += 1;
            day += numDays[month];
            day %= 7;
        }
    }
    
    fout << occurences[0];
    for (size_t i = 1; i < 7; ++i) {
        fout << " " << occurences[i];
    }
    fout << "\n";
}
