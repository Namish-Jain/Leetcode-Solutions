class Solution {
private:
    int countOnes(int num) {
        int ans = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) if (num & (1 << i)) ans++;
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) ans[i] = countOnes(i);
        return ans;
    }
};
