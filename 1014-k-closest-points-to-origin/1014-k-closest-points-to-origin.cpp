class Solution {
private:

    priority_queue<pair<double,vector<int>>,
    vector<pair<double,vector<int>>>,
    greater<pair<double,vector<int>>>> minHeap;

    vector<vector<int>> ans;

    double calcSqrt(vector<int> point) {
        return sqrt((point[0]*point[0]) + (point[1]*point[1]));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (int i = 0; i < points.size(); i++) minHeap.push({calcSqrt(points[i]), points[i]});

        while (k > 0 && !minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }
        return ans;
    }
};