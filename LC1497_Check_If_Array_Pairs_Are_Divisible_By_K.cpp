class Solution
{
public:
    bool canArrange(vector<int>& arr, int k)
    {
        vector<int> mp(k, 0);

        for(int &num : arr)
        {
            mp[((num % k + k) % k)]++; // handle -ve remainders
        }

        if(mp[0] % 2 != 0) return false;

        for(int rem = 1; rem <= k/2; rem++)
        {
            int otherHalf = k - rem;

            if(rem == otherHalf)
            {
                if(mp[rem] % 2 != 0) return false;
            }

            else if (mp[otherHalf] != mp[rem]) return false;
        }

        return true;
    }
};