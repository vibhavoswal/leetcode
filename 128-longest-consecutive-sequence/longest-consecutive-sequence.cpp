class Solution {
private:
    unordered_map<int, int> m;
    unordered_map<int, int> len;
    unordered_map<int, int> visited;
    //len will store the len starting from num

public:
    int dfs(int u) {

        visited[u] = 1;

        if(len[u] != 0) {
            return len[u];
        }

        if(visited[u] != 0 and m[u+1] != 0) {
            return 1 + dfs(u+1);
        }

        return 1;
    }

    int longestConsecutive(vector<int>& nums) {
  
        for(auto num: nums) {
            m[num] = 1;
        }
        
        int ans = 0;

        for(auto num: nums) { 
            if(visited[num] == 0) {
                len[num] = dfs(num);
                ans = max(ans, len[num]);
            }
        }

        return ans;
    }
};