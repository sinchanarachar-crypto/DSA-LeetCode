class Solution
{
private:
    int m, n;
    vector<vector<int>> dp;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(vector<vector<int>>& mat, int r, int c)
    {
        if(dp[r][c]) return dp[r][c];
        dp[r][c] = 1;
        for(auto& d : dirs)
        {
            int nr = r + d[0], nc = c + d[1];
            if(nr >= 0 && nr < m && nc < n && nc >= 0 && mat[nr][nc] > mat[r][c])
                dp[r][c] = max(dp[r][c], 1 + dfs(mat, nr, nc));
        }
        return dp[r][c];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));
        int res = 0;
        for(int r = 0; r < m; r++)
            for(int c = 0; c < n; c++)
                res = max(res, dfs(matrix, r, c));
        return res;
    }
    
};