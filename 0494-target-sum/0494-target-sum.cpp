class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // each index of the vector is a row in the dp table
        // hash map maps the sum -> no of ways to make that sum
        vector<unordered_map<int,int>> dp(nums.size() + 1);
        dp[0][0] = 1;

        for (int i{}; i < nums.size(); i++) {
            for (auto& pair : dp[i]) {
                int prevSum = pair.first, prevCount = pair.second;
                dp[i + 1][prevSum + nums[i]] += prevCount;
                dp[i + 1][prevSum - nums[i]] += prevCount;
            }
        }
        return dp[nums.size()][target];
    }
};