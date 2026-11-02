class Solution {

    void backtracking(int index, vector<int>& nums, vector<int>& currCombination, vector<vector<int>>& combinations, int k) {

        if (currCombination.size() == k) {
            combinations.push_back(currCombination);
            return;
        }

        if (index == nums.size()) return;

        currCombination.push_back(nums[index]);
        backtracking(index + 1, nums, currCombination, combinations, k);
        currCombination.pop_back();
        backtracking(index + 1, nums, currCombination, combinations, k);

    }

public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> nums;
        for (int i{1}; i <= n; ++i) nums.push_back(i);

        vector<vector<int>> combinations;
        vector<int> currCombination;

        backtracking(0, nums, currCombination, combinations, k);

        return combinations;
    }
};