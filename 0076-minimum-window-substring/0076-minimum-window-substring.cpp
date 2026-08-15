class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0) return "";

        unordered_map<char,int> tMap, winMap;
        for (char c : t) tMap[c]++;

        int have = 0, need = tMap.size(), l = 0, minLength = INT_MAX;
        pair<int,int> indices;

        for (int r = 0; r < s.length(); r++) {
            winMap[s[r]]++;

            if (tMap.count(s[r]) && tMap[s[r]] == winMap[s[r]]) have++;

            while (have == need) {
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    indices = {l, r};
                }

                winMap[s[l]]--;
                if (tMap.count(s[l]) && tMap[s[l]] > winMap[s[l]]) have--;
                l++;
            }
        }
        if (minLength == INT_MAX) return "";
        else return s.substr(indices.first, minLength);
    }
};