class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            // the new interval before the curr interval (not overlapping)
            if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
                return ans;
            }
            // the new interval is after the curr interval (not overlapping)
            else if (newInterval[0] > intervals[i][1]) ans.push_back(intervals[i]);
            // overlapping so we update the new merged interval
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] =  max(newInterval[1], intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};