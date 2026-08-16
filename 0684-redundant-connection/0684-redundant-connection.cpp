class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 

        for (int i = n - 1; i >= 0; i--) {
            if (isValidTreeWithoutEdge(n, edges, i)) {
                return edges[i];
            }
        }
        return {};
    }

private:
    bool isValidTreeWithoutEdge(int n, vector<vector<int>>& edges, int skipIndex) {

        unordered_set<int> seen;
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            if (i == skipIndex) continue;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if (!dfs(edges[0][0], -1, seen, adj)) return false; 

        return seen.size() == edges.size();
    }

    bool dfs(int node, int parent, unordered_set<int>& seen, unordered_map<int, vector<int>>& adj) {
        if (seen.contains(node)) return false;
        seen.insert(node);

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (!dfs(neighbor, node, seen, adj)) return false;
        }
        return true;
    }
};