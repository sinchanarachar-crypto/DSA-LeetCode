class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for(int num : numSet)
        {
            if(!numSet.count(num - 1))
            {
                int cur = num, length = 1;
                while(numSet.count(cur + 1))
                {
                    cur++;
                    length++;
                }
                maxLen = max(length, maxLen);
            }
        }
        return maxLen;
    }
};