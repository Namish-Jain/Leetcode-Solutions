class Solution {

    int sum(vector<int> arr) {
        int total{};
        for (int num : arr) total += num;
        return total;
    }

    void backtracking(int index, vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& currCombination, int target) {

        if (sum(currCombination) > target) return;

        if (sum(currCombination) == target) {
            combinations.push_back(currCombination);
            return;
        }

        if (index == candidates.size()) return;

        currCombination.push_back(candidates[index]);
        backtracking(index, candidates, combinations, currCombination, target);
        currCombination.pop_back();
        backtracking(index + 1, candidates, combinations, currCombination, target);

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> combinations;
        vector<int> currCombination;
        backtracking(0, candidates, combinations, currCombination, target);

        return combinations;
    }
};