class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> dp(nums.size(), 1);

        for (int i{n}; i >= 0; --i) {
            for (int j{i + 1}; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        int ans{};
        for (int num : dp) ans = max(ans, num);
        return ans; 
    }
};