class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        unordered_set<int> set;
        for (int x : nums) set.insert(x);

        for (int x: set) {
            if (!set.count(x-1)) {
                int curCount = 1;
            
                while (set.count(x+1)) {
                    x++;
                    curCount++;
                }
            count = max(count, curCount);
            }
        }
        return count;
    }
};