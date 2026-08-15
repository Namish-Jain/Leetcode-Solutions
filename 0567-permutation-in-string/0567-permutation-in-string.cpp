class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) return false;

        unordered_map<char,int> s1Map;
        unordered_map<char, int> s2Map;
        int windowSize = s1.length(), l = 0; 

        for (char c : s1) s1Map[c]++;
        
        for(int r = 0; r < s2.length(); r++) {
            s2Map[s2[r]]++;

            while (r - l + 1 > windowSize) {
                s2Map[s2[l]]--;
                if (s2Map[s2[l]] == 0) {
                    s2Map.erase(s2[l]);
                }
                l++;
            }

            if (s1Map == s2Map) return true;
        }

        return false;
    }
};