class Solution {

    void backtracking(int index, vector<int>& nums, vector<vector<int>>& subSets, vector<int>& currSet) {

        if (index >= nums.size()) {
            subSets.push_back(currSet);
            return;
        }
        
        currSet.push_back(nums[index]);
        backtracking(index + 1, nums, subSets, currSet);
        currSet.pop_back();
        backtracking(index + 1, nums, subSets, currSet);

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> currSet;
        vector<vector<int>> subSets;

        backtracking(0, nums, subSets, currSet);

        return subSets;
    }



};