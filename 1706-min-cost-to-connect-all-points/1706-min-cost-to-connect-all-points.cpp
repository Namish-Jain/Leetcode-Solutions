class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // adjacency list to represent all the points as a connected, undirected graph
        // storing (src node -> list of {weight, dst node} pairs)
        unordered_map<int,vector<pair<int,int>>> adjacencyList; 

        // populate adjacency list
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adjacencyList[i].push_back({dist, j});
                adjacencyList[j].push_back({dist, i});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_set<int> seen;
        int minCost = 0;
        minHeap.push({0, 0});
        while(!minHeap.empty()) {
            auto curr = minHeap.top();
            int cost = curr.first;
            int dstNode = curr.second;
            minHeap.pop();
            if (!seen.contains(dstNode)) {
                minCost += cost;
                seen.insert(dstNode);
                for (auto& neighbors : adjacencyList[dstNode]) {
                    int neiCost = neighbors.first;
                    int neiNode = neighbors.second;
                    if (!seen.contains(neiNode)) minHeap.push({neiCost, neiNode});
                }
            }
        }

        return minCost;
    }
};