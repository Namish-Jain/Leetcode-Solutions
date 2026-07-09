class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int res = 0; 

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int x = record.top(); 
                record.pop();
                int y = record.top();
                record.push(x); 
                record.push(x + y);
                res += record.top();
            }
            else if (operations[i] == "D") {
                record.push(record.top() * 2);
                res += record.top();
            }
            else if (operations[i] == "C") {
                res -= record.top();
                record.pop();
            }
            else {
                record.push(stoi(operations[i]));
                res += record.top();
            }
        }
        return res;
    } 
};