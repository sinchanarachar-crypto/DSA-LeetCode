class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {

        int n = grid.size();
        vector<string> row;
        vector<string> col;
        for (int i = 0; i < n; i++)
        {
            string result;
            for (int j = 0; j < n; j++)
            {
                result += to_string(grid[i][j]) + '_';
            }
            result.pop_back(); 
            row.push_back(result);
        }
        for (int i = 0; i < n; i++)
        {
            string result;
            for (int j = 0; j < n; j++)
            {
                result += to_string(grid[j][i]) + '_';
            }
            result.pop_back(); 
            col.push_back(result);
        }
        
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] == col[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

