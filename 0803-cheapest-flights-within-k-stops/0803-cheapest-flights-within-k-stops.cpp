class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // Use hash table to make adjacency list to create graph where (src node -> list of {dst node, price} pairs)
        unordered_map<int, vector<pair<int,int>>> adjacencyList;

        // populate adjacency list
        for (auto& edge : flights) adjacencyList[edge[0]].push_back({edge[1], edge[2]});

        vector<vector<int>> M(k + 2, vector<int>(n, INT_MAX));
        M[0][src] = 0;

        for (int i = 1; i <= k + 1; i++) {

            for (int v = 0; v < n; v++) M[i][v] = M[i - 1][v];
            
            for (int u = 0; u < n; u++) {
                if (M[i - 1][u] != INT_MAX) {
                    for (auto& neighbor : adjacencyList[u]) {
                    int w = neighbor.first;      
                    int cost = neighbor.second;  
                    M[i][w] = min(M[i][w], M[i - 1][u] + cost);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= k + 1; i++) {
            ans = min(ans, M[i][dst]);
        }

        if (ans == INT_MAX) return -1;
        else return ans;
    }
};