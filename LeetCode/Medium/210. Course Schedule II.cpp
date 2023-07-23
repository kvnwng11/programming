class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        unordered_map<int, unordered_set<int>> adj;

        for (int i=0; i<prerequisites.size(); ++i) {
            int to = prerequisites[i][0], from = prerequisites[i][1];
            adj[from].insert(to);
            indegree[to]++;
        }

        deque<int> d;
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0)
                d.push_back(i);
        }

        int nodesVisited = 0;
        vector<int> ans;
        ans.reserve(numCourses);
        while (!d.empty()) {
            int curr = d.front();
            d.pop_front();
            nodesVisited++;
            ans.push_back(curr);

            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    d.push_back(neighbor);
            }
        }

        if (nodesVisited == numCourses)
            return ans;
        
        vector<int> empty;
        return empty;
    }
};