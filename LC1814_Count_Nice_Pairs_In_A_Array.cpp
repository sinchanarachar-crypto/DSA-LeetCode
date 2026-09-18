class Solution
{
public:

    int reverse(int x)
    {
        int sum = 0;
        while(x > 0)
        {
            sum = (sum * 10) + (x % 10);
            x /= 10;
        }
        return sum;
    }
    int countNicePairs(vector<int>& nums)
    {
        long long M = 1e9+7;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            nums[i] = nums[i] - reverse(nums[i]);
        }

        unordered_map<int, int> mp;
        long long result = 0;

        for(auto &i : nums)
        {
            result = (result + mp[i]) % M;
            mp[i]++;
        }

        return result;
    }
};