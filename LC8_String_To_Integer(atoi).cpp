class Solution
{
public:
    int myAtoi(string s)
    {
        long res = 0;
        int i = 0, sign = 1;

        if(s.size() == 0) return res;

        while(i < s.size() && s[i] == ' ')
            i++;

        if(i < s.size() && (s[i] == '-' || s[i] == '+'))
        {   
            if(s[i] == '-')
                sign = -1;
            i++;
        }

        while(i < s.size() && isdigit(s[i]))
        {
            res = (res*10) + (s[i] - '0');
            if(sign == 1 && res > INT_MAX) return INT_MAX;
            if(sign == -1 && -res < INT_MIN) return INT_MIN;
            i++;
        }

        return (long)(res * sign);
    }
};