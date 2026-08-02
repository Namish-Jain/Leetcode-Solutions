class Solution {
    unordered_map<string, vector<string>> adjacencyList;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        bool endWordFound = false;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) endWordFound = true;
        }

        if (!endWordFound) return 0;

        for (int i = 0; i < wordList.size(); i++) {
            if (difference(beginWord, wordList[i]) == 1) adjacencyList[beginWord].push_back(wordList[i]);
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < wordList.size(); j++) {
                if (difference(wordList[i], wordList[j]) == 1) adjacencyList[wordList[i]].push_back(wordList[j]);
            }
        }

        queue<pair<string, int>> q; 
        unordered_set<string> seen;
        
        q.push({beginWord, 1}); 
        seen.insert(beginWord);

        while(!q.empty()) {
            string node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (node == endWord) return dist;
            for (string neighbor : adjacencyList[node]) {
                if (!seen.contains(neighbor)) {
                    seen.insert(neighbor);
                    q.push({neighbor, dist + 1});
                }
            }
        }
        return 0;
    }

    int difference(string s1, string s2) {
        int diff = 0;
        for (int left = 0; left < s1.length(); left++) {
            if (s1[left] != s2[left]) diff++;
        }
        return diff;
    }
};