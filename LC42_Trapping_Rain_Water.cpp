class Solution
{
public:
    int trap(vector<int>& height)
    {
        int l = 0 , r = height.size() - 1;
        int maxL = 0, maxR = 0;
        int water = 0;

        while(l < r)
        {   if(height[l] <= height[r])
            {
            maxL = max(maxL, height[l]);
            water += maxL - height[l];
            l++;
            }
            else
            {
                maxR = max(maxR, height[r]);
                water += maxR - height[r];
                r--;
            }
        }
        return water;
    }
};