class Solution
{
public:
    int firstPosition(vector<int>& nums, int target)
    {
        int l = 0, h = nums.size() - 1, m, ans = -1;
        while(l <= h)
        {
            m = (l + h)/2;

            if(target == nums[m])
            {
                ans = m;
                h = m - 1;
            }
            
            if(target < nums[m])
                h = m - 1;
            
            if(target > nums[m])
                l = m + 1;
        }
        return ans;
    }

    int lastPosition(vector<int>& nums, int target)
    {
        int l = 0, h = nums.size() - 1, m, ans = -1;
        while(l <= h)
        {
            m = (l + h)/2;

            if(target == nums[m])
            {
                ans = m;
                l = m + 1;
            }
            
            if(target < nums[m])
                h = m - 1;
            
            if(target > nums[m])
                l = m + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        return {firstPosition(nums, target), lastPosition(nums, target)};
    }
};