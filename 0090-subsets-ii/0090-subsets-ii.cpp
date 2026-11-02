class Solution {

    void backtracking(int index, vector<int>& nums, vector<vector<int>>& subSets, vector<int>& currSet) {

        if (index >= nums.size()) {
            subSets.push_back(currSet);
            return;
        }

        currSet.push_back(nums[index]);
        backtracking(index + 1, nums, subSets, currSet);
        currSet.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) ++index;

        backtracking(index + 1, nums, subSets, currSet);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> subSets;
        vector<int> currSet;

        backtracking(0, nums, subSets, currSet);
        return subSets;
    }
};