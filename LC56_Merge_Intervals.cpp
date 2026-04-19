class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output = {intervals[0]};

        for(int i = 1; i < intervals.size(); i++)
        {
            int s = intervals[i][0], e = intervals[i][1];
            if(s <= output.back()[1])
            {
                output.back()[1] = max(output.back()[1], e);
            }
            else
            {
                output.push_back({s, e});
            }
        }
        return output;
    }
};