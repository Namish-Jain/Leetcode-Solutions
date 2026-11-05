class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map; 
        for (string word : strs) {
            string temp = word;
            sort(word.begin(), word.end());
            map[word].push_back(temp);
        }
        for (auto& [key,value] : map) ans.push_back(value);
        return ans;
    }
};