class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, leftMax = height[l], rightMax = height[r], water = 0;

        while(l < r) {
            if (height[l] < height[r]) {
                l++;
                leftMax = max(height[l], leftMax);
                water += leftMax - height[l];
            }
            else {
                r--;
                rightMax = max(height[r], rightMax);
                water += rightMax - height[r];
            }
        }
        return water;
    }
};