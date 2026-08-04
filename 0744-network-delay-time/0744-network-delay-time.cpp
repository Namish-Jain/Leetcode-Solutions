class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // store nodes visited in hash set
        unordered_set<int> seen;

        // store (cost from k, node) pairs in minHeap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        // adjacency list of graph (source node -> {destination node, cost})
        unordered_map<int,vector<pair<int,int>>> adjacencyList;

        // populate adjacencyList 
        for (auto& edge : times) adjacencyList[edge[0]].push_back({edge[1], edge[2]});
        
        // Perform Dijkstra's algorithm on graph starting from node k and keeping count of min time
        int t = 0;
        minHeap.push({0, k});
        while (!minHeap.empty()) {
            int cost = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            if (!seen.contains(node)) {
                t = cost;
                seen.insert(node);
                for (auto& neighbor : adjacencyList[node]) {
                    int node2 = neighbor.first, cost2 = neighbor.second;
                    if (!seen.contains(node2)) minHeap.push({t + cost2, node2});
                }
            }
        }

        if (seen.size() == n) return t;
        else return -1;
    }
};