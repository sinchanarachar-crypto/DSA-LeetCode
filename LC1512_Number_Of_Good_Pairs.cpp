class Solution
{
public:
    int numIdenticalPairs(vector<int>& nums)
    /*{
        int n = nums.size();
        int result = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
                if(nums[i] == nums[j]) result++;
        }

        return result;
        
    }*/

    /*{
        int n = nums.size();
        int result = 0;

        unordered_map<int, int> mp;

        for(auto &num : nums) mp[num]++;

        for(auto &it : mp)
        {
            int count = it.second;
            
            result += (count * (count - 1)) / 2;
        }
        return result;
    }*/

    {
        int n = nums.size();
        int result = 0;

        unordered_map<int, int> mp;

        for(auto &num : nums)
        {
            result += mp[num];

            mp[num]++;
        }
        return result;
    }
};