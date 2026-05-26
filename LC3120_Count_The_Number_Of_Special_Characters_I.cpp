class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        set<int> s1;
        set<int> s2;

        for(char ch : word)
        {
            if(ch >= 'a' && ch <= 'z')
                s1.insert(ch - 'a');
            else
                s2.insert(ch - 'A');
        }
        int c = 0;
        for(auto i : s1)
            if(s2.find(i) != s2.end())
                c++;

        return c;
    }
};