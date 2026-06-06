class Solution
{
public:
    vector<int> leftRightDifference(vector<int>& nums)
    /*{
        vector<int> res;
        int l = 0, r = nums.size() - 1;

        for(int i = 0; i < nums.size(); i++)
        {
            int sum1 = 0, sum2 = 0;

            for(int j = 0; j < i; j++)
                sum1 += nums[j];
            
            for(int j = nums.size() - 1; j > i; j--)
                sum2 += nums[j];

            res.push_back(abs(sum1 - sum2));
        }
        return res;
    }*/

    /*
    {
        int n = nums.size();
        vector<int> res(n);
        vector<int> right(n,0);
        vector<int> left(n,0);

        for(int i = 1; i < n; i++)
            left[i] = left[i - 1] + nums[i - 1];      
        for(int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] + nums[i + 1];
        for(int i = 0; i < n; i++)
            res[i] = abs(left[i] - right[i]);

        return res;
    }
    */

    {
        int n = nums.size();
        vector<int> res(n);
        int rightsum = 0, leftsum = 0;

        for(int num : nums)
            rightsum += num;

        for(int i = 0; i < n; i++)
        {
            rightsum -= nums[i];

            res[i] = abs(rightsum - leftsum);

            leftsum += nums[i];
        }
        return res;
    }
};