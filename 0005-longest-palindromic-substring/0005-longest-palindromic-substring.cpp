class Solution {
public:
    string longestPalindrome(string s) {
        int ansIdx = 0, ansLen = 0;

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > ansLen) {
                    ansIdx = l;
                    ansLen = r - l + 1;
                }
                l--;
                r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > ansLen) {
                    ansIdx = l;
                    ansLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(ansIdx, ansLen);
    }
};