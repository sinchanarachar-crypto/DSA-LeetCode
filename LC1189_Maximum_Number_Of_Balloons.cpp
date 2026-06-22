class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int b = 0, a = 0, l = 0, o = 0, n = 0, ans = 0;
        for(char x : text)
        {
            if(x == 'b')
                b++;
            if(x == 'a')
                a++;
            if(x == 'l')
                l++;
            if(x == 'o')
                o++;
            if(x == 'n')
                n++;
        }

        while(b > 0 && a > 0 && l > 1 && o > 1 && n > 0)
        {
            ans++;
            b--;
            a--;
            n--;
            l -= 2;
            o -= 2;
        }

        return ans;
    }
};