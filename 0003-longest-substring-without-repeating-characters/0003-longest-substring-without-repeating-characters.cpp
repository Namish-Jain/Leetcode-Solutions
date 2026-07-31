class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, left = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++) {
            if (!charSet.contains(s[right])) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            }
            else {
                while (charSet.contains(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLength;
    }
};