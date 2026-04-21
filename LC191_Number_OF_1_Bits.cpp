class Solution
{
public:
    /*int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n &= (n-1);
            count++;
        }
        return count;
    }*/

    int hammingWeight(uint32_t n)
    {
        return __builtin_popcount(n);
    }

    /*int hammingWeight(uint32_t n)
    {
        int count = 0;
        while(n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }*/   
};