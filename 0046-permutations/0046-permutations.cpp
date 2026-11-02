class Solution {

    void backtrack(vector<bool>& seen, vector<int>& currPerm, vector<vector<int>>& permuations, vector<int>& nums) {

        if (currPerm.size() == nums.size()) {
            permuations.push_back(currPerm);
            return;
        }

        for (int i{}; i < nums.size(); ++i) {
            if (!seen[i]) {
                currPerm.push_back(nums[i]);
                seen[i] = true;
                backtrack(seen, currPerm, permuations, nums);
                currPerm.pop_back();
                seen[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> permuations;
        vector<int> currPerm;
        vector<bool> seen(nums.size(), false);

        backtrack(seen, currPerm, permuations, nums);

        return permuations;
    }
};