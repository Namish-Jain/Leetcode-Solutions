class Solution {
public:
    void sortColors(vector<int>& nums) {
        int temp = 0;
        for (int colour = 0; colour < 4; colour++) {
            int l = temp;
            for (int r = l + 1; r < nums.size(); r++) {
                if (nums[l] != colour && nums[r] == colour) swap(nums[l], nums[r]);
                if (nums[l] == colour) l++;
            }
            temp = l;
        }
    }
};