class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int num1 = 0, num2 = 0, num3 = 0, num4 = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int curr = max(num2, nums[i] + num1);
            num1 = num2;
            num2 = curr;
        }

        for (int i = 1; i < nums.size(); i++) {
            int curr = max(num4, nums[i] + num3);
            num3 = num4;
            num4 = curr;
        }

        return max(num2, num4);
    }
};