class Solution {
public:
    int MOD = 1e9+7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        long long dpp[n][m], dpn[n][m];

        dpp[0][0] = grid[0][0];
        dpn[0][0] = grid[0][0];
        
        for(int i = 1; i < n; i++){
            dpp[i][0] = dpp[i-1][0] * grid[i][0];
            dpn[i][0] = dpn[i-1][0] * grid[i][0];
        }
        
        for(int i = 1; i < m; i++){
            dpp[0][i] = dpp[0][i-1] * grid[0][i];
            dpn[0][i] = dpn[0][i-1] * grid[0][i];
        }
        int i, j;
        for( i = 1; i < n; i++){
            for( j = 1; j < m; j++){
                if(grid[i][j] >= 0){
                    dpp[i][j] = max(dpp[i-1][j], dpp[i][j-1])*grid[i][j];
                    dpn[i][j] = min(dpn[i-1][j], dpn[i][j-1])*grid[i][j];
                }
                else{
                    dpp[i][j] = min(dpn[i-1][j], dpn[i][j-1])*grid[i][j];
                    dpn[i][j] = max(dpp[i-1][j], dpp[i][j-1])*grid[i][j];
                }
                
            }
        }
        
        int ans = dpp[n-1][m-1] % MOD;
        if(ans < 0 )
            return -1;
        return ans;
    }
};
