class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             unordered_map<int, int>& visited) {

        if (visited[node] == 1) return false; 
        if (visited[node] == 2) return true;  

        visited[node] = 1;

        for (int nei : adj[node]) {
            if (!dfs(nei, adj, visited))
                return false;
        }

        visited[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();

        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_map<int, int> visited;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj, visited))
                return false;
        }

        return true;
    }
};