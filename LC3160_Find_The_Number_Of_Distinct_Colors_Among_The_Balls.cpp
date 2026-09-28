class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int, int> colormp;

        unordered_map<int, int> ball;

        for(int i = 0; i < n; i++)
        {
            int b = queries[i][0];
            int bc = queries[i][1];

            if(ball.find(b) != ball.end())
            {
                int prevColor = ball[b];
                colormp[prevColor]--;

                if(colormp[prevColor] == 0)
                {
                    colormp.erase(prevColor);
                }
            }

            ball[b] = bc;
            colormp[bc]++;

            result[i] = colormp.size();

        }

        return result;
    }
};