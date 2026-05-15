class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size() - 1;
        int l = 0, h = n, m;
        int ans = INT_MAX;

        while(l <= h)
        {
            m = (l + h)/2;

            if(nums[l] <= nums[m])
            {
                ans = min(nums[l], ans);
                l = m + 1;
            }

            if(nums[m] <= nums[h])
            {
                ans = min(nums[m], ans);
                h = m - 1;
            }
        }
        return ans;
    }
};