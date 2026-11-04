class Solution {

    bool bfs(vector<vector<int>>& graph, int node, vector<int>& colour) {
        queue<int> q;
        
        colour[node] = 1;
        q.push(node);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbour : graph[curr]) {
                if (colour[curr] == colour[neighbour]) return false;

                if (colour[neighbour] == 0) {
                    if (colour[curr] == 1) colour[neighbour] = 2;
                    else colour[neighbour] = 1;
                    q.push(neighbour);
                }

            }   
        }
        return true;
    }



public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // blue if 1, red if 2, not coloured if 0
        vector<int> colour(n, 0);

        for (int i{}; i < graph.size(); ++i) {
            int node = i;
            if (colour[i] == 0) {
                if (!bfs(graph, i, colour)) return false;
            }
        }

        return true;
    }
};