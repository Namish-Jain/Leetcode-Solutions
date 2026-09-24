class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i{}; i < nums.size(); ++i) {
            int currNum = nums[i], sum{};
            while (currNum > 0) {
                sum += currNum % 10;
                currNum /= 10;
            }
            if (sum == i) return i;
        }
        return -1;
    }
};