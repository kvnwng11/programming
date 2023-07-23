typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vector<double>> vvd;
typedef vector<vector<string>> vvs;

class Solution {
private:
    unordered_map<string, unordered_map<string, double>> adj;

    double traverse(string &curr, string &target, double val, unordered_set<string> checked) {
        checked.insert(curr);
        double ret = -1;

        unordered_map<string, double> neighbors = adj[curr];
        if (neighbors.find(target) != neighbors.end())
            ret = val * neighbors[target];
        else {
            for (auto pair : neighbors) {
                string next = pair.first;
                if (checked.find(next) != checked.end())
                    continue;
                ret = traverse(next, target, val * pair.second, checked);
                if (ret != -1)
                    break;
            }
        }

        checked.erase(curr);
        return ret;
    }

public:
    vector<double> calcEquation(vvs& equations, vd& values, vvs& queries) {
        // Build graph
        int n = 0;
        for (int i=0; i<equations.size(); ++i) {
            string &s1 = equations[i][0], &s2 = equations[i][1];
            double val = values[i];
            unordered_map<string, double> m;
            if (adj.find(s1) == adj.end())
                adj[s1] = m;
            if (adj.find(s2) == adj.end())
                adj[s2] = m;
            
            adj[s1][s2] = val;
            adj[s2][s1] = 1/val;
        }

        // Evaluate each query
        vd ans(queries.size());
        for (int i=0; i<queries.size(); ++i) {
            string s1 = queries[i][0], s2 = queries[i][1];

            if (adj.find(s1) == adj.end() or adj.find(s2) == adj.end())
                ans[i] = -1;
            else if (s1 == s2)
                ans[i] = 1;
            else {
                unordered_set<string> checked;
                ans[i] = traverse(s1, s2, 1, checked);
            }
        }

        return ans;
    }
};