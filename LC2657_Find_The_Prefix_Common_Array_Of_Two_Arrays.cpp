class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        vector<int> res;
        unordered_map<int, int> mp;

        int count = 0;
        for(int i = 0; i < A.size(); i++)
        {
            mp[A[i]] ++;
            if(mp[A[i]] == 2)
                count++;
            mp[B[i]] ++;
            if(mp[B[i]] == 2)
                count++;

            res.push_back(count);
        }
        return res;
    }

    /*
    {
        int n = A.size();
        vector<int> res;
        vector<bool> PresentA(n + 1, false);
        vector<bool> PresentB(n + 1, false);

        for(int i = 0; i < n; i++)
        {
            PresentA[A[i]] = true;
            PresentB[B[i]] = true;
            int count = 0;

            for(int j = 1; j <= n; j++)
                if(PresentA[j] == true && PresentB[j] == true)
                {
                    count++;
                }
            res.push_back(count);
        }
        return res;
    }
    */

    /*
    {
        int n = A.size();
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int x = 0; x <= i; x++)
            {
                for(int y = 0; y <= i; y++)
                {
                    if(B[y] == A[x])
                    {
                        count++;
                        break;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
    */
};