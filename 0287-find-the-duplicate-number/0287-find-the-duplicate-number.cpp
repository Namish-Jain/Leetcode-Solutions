class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + ((r - l) / 2), count{};
            for (int i{}; i < nums.size(); ++i) if (nums[i] <= mid) count++;

            if (count > mid) r = mid;
            else l = mid + 1;
        }

        return r;
    }
};