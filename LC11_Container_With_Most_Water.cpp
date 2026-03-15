class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int maxW = 0;
        int l = 0, r = n-1;

        while(l < r)
        {    
            if((min(height[l],height[r])*(r - l)) > maxW)
            {
                maxW =  min(height[l],height[r]) * (r - l);
            }

            if (height[l] <= height[r]) 
                l++;
            else
                r--;
        }

            
        return maxW;
        
    }
};