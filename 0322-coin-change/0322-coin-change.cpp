class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int i{}; i <= amount; ++i) {
            for (int j{}; j < coins.size(); ++j) {
                int currCoin{coins[j]};
                if (currCoin <= i) {
                    if (dp[i - currCoin] != numeric_limits<int>::max())
                        dp[i] = min(dp[i], 1 + dp[i - currCoin]);
                }
            }
        }
        if (dp[amount] == std::numeric_limits<int>::max()) return -1;
        else return dp[amount];
    }
};