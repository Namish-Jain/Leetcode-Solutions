class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int r = 1; r < nums.size(); r++) {
            if (nums[l] == 0 && nums[r] != 0) swap(nums[l], nums[r]);
            if (nums[l] != 0) l++;
        }
    }
};