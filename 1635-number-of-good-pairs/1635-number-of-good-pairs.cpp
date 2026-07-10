class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> map;
        for (int num: nums) map[num]++;
        for (int num: nums) {
            map[num]--;
            count += map[num];
        }
        return count;
    }
};