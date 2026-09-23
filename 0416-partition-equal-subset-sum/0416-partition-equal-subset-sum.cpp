class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum{};
        for (int num : nums) sum += num;
        if ((sum & 1) == 1) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
        for (int i{}; i < nums.size(); ++i) dp[i][0] = true;

        for (int index{1}; index <= nums.size(); ++index) {
            for (int subTarget{1}; subTarget <= target; subTarget++) {
                int currNum{nums[index - 1]};
                if (currNum <= subTarget) {
                    dp[index][subTarget] = dp[index - 1][subTarget] || dp[index - 1][subTarget - currNum];
                }
                else dp[index][subTarget] = dp[index - 1][subTarget];
            }
        }
        return dp[nums.size()][target]; 
    }
};