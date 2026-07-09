class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int length = arr.size();
        vector<int> ans(length);
        int highest = -1;
        for (int i = length - 1; i >= 0; i--) {
            ans[i] = highest;
            highest = max(highest, arr[i]);
        }
        return ans;
    }
};