class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 0)
            return 0;

        int l = 0, r = 1, unique = 1;

        while(r < n)
        {
            if(nums[r] == nums[r - 1])
                r++;
            else
            {
                nums[l + 1] = nums[r];
                r++; l++; unique++;
            }
        }
        return unique;
    }
};