class Solution {

private:
    vector<int> row = {0,1,0,-1};
    vector<int> col = {1,0,-1,0};
    vector<vector<int>> visited;
    int R;
    int C;

public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        
        visited[i][j] = 1;

        for(int k=0; k<4; ++k) {
            int new_i = i+row[k];
            int new_j = j+col[k];
            if(new_i >= 0 and new_i < R and new_j >= 0 and new_j < C
                and grid[new_i][new_j] == '1' and !visited[new_i][new_j]) {
                dfs(new_i, new_j, grid);
            }       
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        R = grid.size();
        C = grid[0].size();
        visited.assign(R, vector<int>(C, 0));

        int count = 0;

        for(int i=0; i<R; ++i) {
            for(int j=0; j<C; ++j) {
                if(grid[i][j] == '1' and !visited[i][j]) {
                    dfs(i,j, grid);
                    count++;
                }
            } 
        }
        
        return count;
    }
};