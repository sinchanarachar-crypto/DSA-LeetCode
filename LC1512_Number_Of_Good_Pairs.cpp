class Solution
{
public:
    int numIdenticalPairs(vector<int>& nums)
    /*{
        int result = 0;
        int n = nums.size();

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(nums[i] == nums[j])
                {
                    result++;
                }
            }
        }

        return result;
    }*/

    /*{
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int &num : nums)
        {
            mp[num]++;
        }

        int result = 0;

        for(auto &it : mp)
        {
            int count = it.second;

            result += count*(count - 1) / 2;
        }

        return  result;
    }*/

    {
        int n = nums.size();
        int result = 0;
        unordered_map<int, int> mp;

        for(int &num : nums)
        {
            result += mp[num];
            mp[num]++;
        }

        return result;
    }
};