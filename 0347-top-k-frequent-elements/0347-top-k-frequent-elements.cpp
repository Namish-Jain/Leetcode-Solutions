class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<
        pair<int, int>, 
        vector<std::pair<int, int>>, 
        greater<std::pair<int, int>>
        > minHeap;

        vector<int> ans;

        unordered_map<int,int> map;
        for (int num: nums) map[num]++;

        for (auto& [val, freq]: map) {
            minHeap.push({freq, val});
            if (minHeap.size() > k) minHeap.pop();
        }

        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};