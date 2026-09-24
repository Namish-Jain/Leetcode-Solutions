class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i{}; i < n; ++i) {
            vector<unsigned int> currRow(amount + 1, 0);
            currRow[0] = 1;
            int currCoin = coins[i];
            for (int j{1}; j <= amount; ++j) {
                if (currCoin <= j) currRow[j] = dp[j] + currRow[j - currCoin];
                else currRow[j] = dp[j];
            }
            dp = currRow;
        }
        
        return dp[amount];
    }
    
};