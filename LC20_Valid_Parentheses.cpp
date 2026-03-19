class Solution
{
public:
    bool isValid(string s)
    /*{
        stack<char> st;
        unordered_map<char,char> pairs = {{')','('},{'}','{'},{']','['}};

        for(char c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if (st.empty() || st.top() != pairs[c])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }*/
    {
        string st;

        for(char c : s)
        {
            if( c == '(' ||c == '[' || c == '{')
                st.push_back(c);
        
            else
            {
                if(st.empty())
                    return false;
                
                char top = st.back();
                st.pop_back();

                if (c == '}' && top != '{' ||
                    c == ')' && top != '(' ||
                    c == ']' && top != '['
                    )
                    return false;
            }
        }
        return st.empty();
    }
};