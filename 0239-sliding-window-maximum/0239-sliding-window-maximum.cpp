class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            // remove indices whose value is < than the current value
            while(!q.empty() && nums[q.back()] < nums[r]) q.pop_back();
            // add current index to deque
            q.push_back(r);
            // Remove elements that are out of window bounds form the front of the deque
            if (!q.empty() && q.front() < r - k + 1) q.pop_front();

            if (r >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};