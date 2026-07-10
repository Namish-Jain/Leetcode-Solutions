class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> map;
        for (char c: text) map[c]++;
        int b = map['b'];
        int a = map['a'];
        int l = map['l'] / 2;
        int o = map['o'] / 2;
        int n = map['n'];
        return min({b, a, l, o, n});
    }
};