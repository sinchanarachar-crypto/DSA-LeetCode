class Solution
{
public:
    bool uniqueOccurrences(vector<int>& arr)
    /*{
        unordered_map<int, int> mp;

        for(int &x : arr) mp[x]++;

        unordered_set<int> st;

        for(auto &it : mp)
        {
            int freq = it.second;

            if(st.find(freq) != st.end()) return false;

            st.insert(freq);
        }

        return true;
    }*/

    {
        vector<int> vec(2001, 0);

        for(auto &it : arr) vec[it + 1000]++;

        sort(begin(vec), end(vec));

        for(int i = 1; i < 2001; i++)
        {
            if(vec[i] != 0 && vec[i] == vec [i - 1]) return false;
        }

        return true;
    }
};