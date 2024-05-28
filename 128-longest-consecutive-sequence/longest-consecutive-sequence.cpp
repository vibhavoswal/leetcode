class Solution {
private:
    map<int, int> m;
    map<int, int> len;
    //len will store the len starting from num

public:
    int dfs(int u) {
        if(len[u] != 0) {
            return len[u];
        }

        if(m[u+1] != 0) {
            len[u+1] = 1 + dfs(u+1);
            return len[u+1];
        }

        return 1;
    }

    int longestConsecutive(vector<int>& nums) {
  
        for(auto num: nums) {
            m[num] = 1;
        }
        
        int ans = 0;

        for(auto num: nums) { 
            len[num] = dfs(num);
            ans = max(ans, len[num]);
        }

        return ans;
    }
};