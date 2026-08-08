class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) if (n & (1 << i)) ans++;
        return ans;
    }
};