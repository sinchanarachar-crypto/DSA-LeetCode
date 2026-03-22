class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int m;
        int b = 0, e = nums.size() -1;

        while(e >= b)
        {
            m = (b + e)/2;
            if(target == nums[m])
            {
                return m;
                break;
            }
            else if(target > nums[m])
            {
                b = m + 1;
            }
            else if(target < nums[m])
            {
                e = m - 1;
            }
        }
        return -1;
    }
};