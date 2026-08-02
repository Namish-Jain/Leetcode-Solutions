class Solution {
    unordered_map<int,vector<int>> adjacencyList;
    unordered_set<int> seen;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            adjacencyList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) return false;
        }
        return true;
    }

    bool dfs(int course) {
        if (seen.contains(course)) return false;
        if (adjacencyList[course].empty()) return true;

        seen.insert(course);
        for (int crs : adjacencyList[course]) {
            if (!dfs(crs)) return false;
        }
        seen.erase(course);
        adjacencyList[course].clear();
        return true;
    }
};