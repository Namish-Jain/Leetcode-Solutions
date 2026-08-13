class Solution {
public:
    bool isAnagram(string s, string t) {
        // hash map to store (letter -> frequency)
        unordered_map<char,int> freqMap;
        // populate hash map for string s
        for (char c : s) freqMap[c]++;

        // iterate through string t
        for (char c : t) {
            // return false if a letter in t is not in hash map 
            if (freqMap.find(c) == freqMap.end()) return false;
            // otherwise decrement frequency for that letter
            freqMap[c]--;
        }

        // iterate through every (letter -> frequency)
        // if the frequency != 0, then return false
        for (auto& [key, value] : freqMap) if ((value) != 0) return false;
        // otherwise return true
        return true;
        
    }
};