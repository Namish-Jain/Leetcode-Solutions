class Solution {
public:
    int rob(vector<int>& nums) {
        int num1 = 0, num2 = 0;

        for (int num : nums) {
            int curr = max(num1 + num, num2);
            num1 = num2;
            num2 = curr;
        }

        return num2;
    }
};