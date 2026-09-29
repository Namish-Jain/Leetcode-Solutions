class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // key idea:
        // base cases:
        // {1}, {1,1}
        // recursive case:
        // pascal[i][j] = pascal[i−1][j−1] + pascal[i−1][j]

        vector<vector<int>> pascal;
        for(int i{}; i < numRows; i++){
            vector<int> row(i+1, 1);
            // inner loop only activates after base cases 
            for(int j{1}; j < i; j++){
                row[j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};