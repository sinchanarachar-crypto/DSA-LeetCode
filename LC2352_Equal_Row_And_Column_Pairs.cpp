class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    /*{
        int n = grid.size();
        int count = 0;

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
            {
                int is_equal = true;

                for(int i = 0; i < n; i++)
                {
                    if(grid[r][i] != grid[i][c])
                    {
                        is_equal = false;
                        break;
                    }
                }

                count += is_equal;
            }
        } 

        return count;   
    }*/

    {
        int count = 0;
        int n = grid.size();

        map<vector<int>, int> mp;

        //Creating map for rows
        for(int row = 0; row < n; row++)
        {
            mp[grid[row]]++;
        }

        //Pushing column value in an array
        for(int col = 0; col < n; col++)
        {
            vector<int> temp;

            for(int row = 0; row < n; row++)
            {
                temp.push_back(grid[row][col]);
            }

            count += mp[temp];
        }
        return count;
    }
};