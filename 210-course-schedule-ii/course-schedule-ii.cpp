class Solution {
public:
    void dfs(int u, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& order) {
          
        visited[u] = 1;

        for(auto v:adjList[u]) {
            if(visited[v] == 1) {
                return;
            }
            else if(visited[v] == 0) {
                dfs(v, adjList, visited, order);
            }

        }
        visited[u] = 2;
        order.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
              
        vector<vector<int>> adjList(numCourses);
        vector<int> visited(numCourses, 0);

        for(auto val: prerequisites) {
            adjList[val[1]].emplace_back(val[0]);
        }

        vector<int> order;
        for(int i=0; i<numCourses; ++i) {

            if(visited[i] == 0) {
                dfs(i, adjList, visited, order);
            }

            if(visited[i] != 2) {
                return vector<int>();
            }
        }
        reverse(order.begin(), order.end());
        return order;     
    }
};