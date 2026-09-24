class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x = text1.size(), y = text2.size();
        vector<int> dp(y + 1, 0);

        for (int i{}; i < x; ++i) {
            vector<int> currRow(y + 1, 0);
            for (int j{}; j < y; ++j) {
                if (text1[i] == text2[j]) {
                    currRow[j + 1] = 1 + dp[j];
                }
                else {
                    currRow[j + 1] = max(currRow[j], dp[j + 1]);
                }
            }
            dp = currRow;
        }

        return dp[y];
    }
};