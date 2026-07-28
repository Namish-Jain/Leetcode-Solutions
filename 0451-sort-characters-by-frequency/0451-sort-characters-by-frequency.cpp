class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char,int> freqMap;
        string ans = "";

        for (char c: s) freqMap[c]++;

        for (auto& [val, freq]: freqMap) {
            maxHeap.push({freq,val});
        }

        while(!maxHeap.empty()) {
            pair<int, char> element;
            element = maxHeap.top();
            maxHeap.pop();
            char c = element.second;
            int times = element.first;
            while(times != 0) {
                ans += c;
                times--;
            }
        }

        return ans;
    }
};