class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        deque<string> d;
        unordered_set<string> seen;
        d.push_back(startGene);
        seen.insert(startGene);

        int ans = 0;
        while (!d.empty()) {
            int size = d.size();

            for (int i=0; i<size; ++i) {
                string curr = d.front();
                d.pop_front();

                if (curr == endGene)
                    return ans;

                for (char c : "ACGT") {
                    for (int j=0; j<curr.size(); ++j) {
                        string neighbor = curr;
                        neighbor[j] = c;

                        if (!seen.count(neighbor) and find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            d.push_back(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};