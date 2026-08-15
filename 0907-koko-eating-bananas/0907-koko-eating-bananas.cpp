class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, maxNum = 0;
        for (int num : piles) maxNum = max(maxNum, num);
        int r = maxNum;
        int ans = 0;

        while (l <= r) {
            int mid = l + ((r - l) / 2);

            long long totalTime = 0;
            for (int num : piles) totalTime += ceil(static_cast<double>(num) / mid);

            if (totalTime <= h) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};