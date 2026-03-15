class Solution
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        /*unordered_set <int> seen;
        for (int x : nums)
        {
            if (seen.count(x))
            {
                return true;
            }
            seen.insert(x);
        }
        return false;*/
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            return true;
        }
        return false;
    }
};