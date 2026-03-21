class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int maxArea = 0;
        stack<pair<int,int>> st;

        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while(!st.empty() && st.top().second > heights[i])
            {
                auto[s , h] = st.top();
                st.pop();
                maxArea = max(maxArea, h * (i - s));
                start = s;
            }
            st.push({start, heights[i]});
        }
        while(!st.empty())
        {
            auto[s , h] = st.top();
            st.pop();
            maxArea = max(maxArea, h * (int)(heights.size() - s));
        }
        return maxArea;
    }
};