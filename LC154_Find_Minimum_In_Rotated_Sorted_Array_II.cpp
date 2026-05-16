class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            ans = min(ans, nums[i]);
        }

        return ans;
    }
};

/*
class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1, m;
        int ans = INT_MAX;
        
        while(l <= r)
        {
            m = (l + r)/2;

            if(nums[m] < nums[r])
            {
                r = m;
            }
            else if(nums[l] < nums[m])
            {
                l = m + 1;
            }
            else
            {
                r--;
            }
        }
        return nums[l];
    }
};
*/