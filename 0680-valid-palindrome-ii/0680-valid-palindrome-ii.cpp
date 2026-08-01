class Solution {
private: 
    bool isPalindrome(int left, int right, string s) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
}

public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) return isPalindrome(left + 1, right, s) || isPalindrome(left, right - 1, s);
            left++;
            right--;
        }

        return true;
    }
};