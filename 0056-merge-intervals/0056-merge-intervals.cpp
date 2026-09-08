class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> currInterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            // not overlapping
            if (currInterval[1] < intervals[i][0]) {
                ans.push_back(currInterval);
                currInterval[0] = intervals[i][0];
                currInterval[1] = intervals[i][1];
            }
            // otherwise overlapping
            else {
                currInterval[0] = min(currInterval[0], intervals[i][0]);
                currInterval[1] = max(currInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(currInterval);
        return ans;
    }
};