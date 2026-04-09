class Solution
{
private:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int rows = grid.size(), cols = grid[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols)
            return;
        if(grid[r][c] != '1')
            return;

        grid[r][c] = '0';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        for(int r = 0; r < grid.size(); r++)
            for(int c = 0; c < grid[0].size(); c++)
                if(grid[r][c] == '1')
                {
                    count++;
                    dfs(grid, r, c);
                }
        return count;
    }
};