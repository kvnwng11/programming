class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size();

        // Preprocess
        unordered_map<string, unordered_set<string>> combos;
        for (int i=0; i<wordList.size(); ++i) {
            for (int j=0; j<L; ++j) {
                string s = wordList[i];
                s[j] = '*';

                combos[s].insert(wordList[i]);
            }
        }

        // BFS
        deque<pair<string, int>> d;
        unordered_set<string> seen;
        d.push_back({beginWord, 1});
        seen.insert(beginWord);
        while (!d.empty()) {
            auto [word, dist] = d.front();
            d.pop_front();

            for (int i=0; i<L; ++i) {
                string s = word;
                s[i] = '*';

                for (string neighbor : combos[s]) {
                    if (neighbor == endWord) return dist+1;

                    if (!seen.count(neighbor)) {
                        d.push_back({neighbor, dist+1});
                        seen.insert(neighbor);
                    }
                }
            }
        }

        return 0;
    }
};