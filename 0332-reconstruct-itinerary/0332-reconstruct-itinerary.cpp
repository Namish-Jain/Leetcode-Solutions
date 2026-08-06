class Solution {
public:
    map<string,list<string>>graph;
    vector<string>ans;
    void dfs(string src){
        
        while(!graph[src].empty()){
            string ngh = graph[src].front();
            graph[src].pop_front();
            dfs(ngh);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& edges) {
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        for(auto &ele:graph){
            ele.second.sort();
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};