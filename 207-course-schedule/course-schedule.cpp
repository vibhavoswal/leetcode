class Solution {
public:
    void dfs(int u, vector<vector<int>>& adjList, vector<int>& visited) {
          
        visited[u] = 1;

        for(auto v:adjList[u]) {
            if(visited[v] == 1) {
                return;
            }
            else if(visited[v] == 0) {
                dfs(v, adjList, visited);
            }

        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(!prerequisites.size()) return true;

        vector<vector<int>> adjList(numCourses);
        vector<int> visited(numCourses, 0);

        for(auto val: prerequisites) {
            adjList[val[1]].emplace_back(val[0]);
        }

        for(int i=0; i<numCourses; ++i) {

            if(visited[i] == 0) {
                dfs(i, adjList, visited);
            }

            if(visited[i] != 2) {
                return false;
            }
        }

        return true;    
    }
};