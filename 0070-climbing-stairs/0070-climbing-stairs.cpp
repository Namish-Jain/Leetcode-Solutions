class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> dp = {1,2};
        int i = 3;
        while (i <= n) {
            int temp = dp[1];
            dp[1] = dp[1] + dp[0];
            dp[0] = temp;
            i++;
        }
        return dp[1];
    }

};