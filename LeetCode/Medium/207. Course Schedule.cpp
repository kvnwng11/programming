class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while (!d.empty()) {
            int curr = d.front();
            d.pop_front();
            nodesVisited++;

            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    d.push_back(neighbor);
            }
        }

        return nodesVisited == numCourses;
    }
};