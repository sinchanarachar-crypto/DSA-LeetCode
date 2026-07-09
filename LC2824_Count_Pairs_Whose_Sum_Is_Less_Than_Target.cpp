class Solution
{
public:
    int countPairs(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, count = 0;

        while(l < r)
        {
            if(nums[l] + nums[r] < target)
            {
                count += r - l;
                l++;
            }
            else r--;
        }
        return count;
    }
};