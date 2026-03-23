class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    /*{
        unordered_set<char> Set;
        int l =  0 ;
        int length = 0;

        for(int r = 0; r < s.size(); r++)
        {
            while(Set.count(s[r]))
            {
                Set.erase(s[l]);
                l++;
            }
            Set.insert(s[r]);
            length = max(length, r - l + 1);
        }
        return length;
    }*/

    {
        unordered_map<char, int> LastSeen;
        int l = 0, length = 0;
        for(int r = 0; r < s.size(); r++)
        {
        if(LastSeen.count(s[r]) && LastSeen[s[r]] >= l)
            l = LastSeen[s[r]] + 1;
        LastSeen[s[r]] = r;
        length = max(length, r - l +1);
        }
        return length;
    }
};