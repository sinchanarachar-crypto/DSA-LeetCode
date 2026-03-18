class Solution
{
public:
    string minWindow(string s, string t)
    /*{
        if (t.empty())
            return "";

        unordered_map<char, int> countT, window;
        for (char c : t)
            countT[c]++;

        int have = 0, need = countT.size();
        int l = 0, minlen = INT_MAX, start = 0;

        for(int r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;
            //Check if this satisfies its requirement
            if (countT.count(c) && window[c] == countT[c])
                have++;

            while (have == need)
            {
                //Valid Window - try to shrink
                if(r - l + 1 < minlen)
                {
                    minlen = r - l + 1;
                    start = l;
                }
                //Shrink from left
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]])
                    have--;
                l++;
            }
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
        
    }*/

    {
            vector<int> count(128, 0);

        for(char c : t)
            count[c]++;

        int required = t.size();  // total characters needed
        int l = 0, minLen = INT_MAX, start = 0;

        for(int r = 0; r < s.size(); r++)
        {
            // include current character
            if(count[s[r]] > 0)
                required--;

            count[s[r]]--;

            // when all characters are matched
            while(required == 0)
            {
                // update answer
                if(r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    start = l;
                }

                // try to shrink
                count[s[l]]++;

                if(count[s[l]] > 0)
                    required++;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }

};