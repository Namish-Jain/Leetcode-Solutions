class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freqMap;
        int l = 0, maxFreq = 0, ans = 0;

        for (int r = 0; r < s.length(); r++) {
            freqMap[s[r]]++;
            maxFreq = max(maxFreq, freqMap[s[r]]);

            while (r - l + 1 - maxFreq > k) {
                freqMap[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};