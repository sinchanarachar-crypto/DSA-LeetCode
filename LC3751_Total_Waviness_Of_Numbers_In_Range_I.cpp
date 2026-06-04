class Solution
{
public:
    /*int isWave(int n)
        {
            vector<int> wave;
            while(n > 0)
            {
                wave.push_back(n % 10);
                n /= 10;
            }
            if(wave.size() < 3)
                return 0;

            int ans = 0;

            for(int i = 1; i < wave.size() - 1; i++)
            {
                if((wave[i] > wave[i - 1] && wave[i + 1] < wave[i]) ||
                    (wave[i] < wave[i - 1] && wave [i + 1] > wave[i]))
                    ans++;
            }

            return ans;
        }
    int totalWaviness(int num1, int num2)
    {
        int count = 0;
        for(int i = num1; i <= num2; i++)
            count += isWave(i);
        return count;    
    }*/

    int isWave(int n)
    {
        string s = to_string(n);
        if(s.size() < 3)
            return 0;

        int wave = 0;
        for(int i = 1; i < s.size() - 1; i++)
        {
            int a = s[i - 1] - '0';
            int b = s[i] - '0';
            int c = s[i + 1] - '0';
            if((a < b && b > c) || (a > b && b < c))
                wave++;
        }
        return wave;
    }

    int totalWaviness(int num1, int num2)
    {
        int count = 0;
        for(int i = num1; i <= num2; i++)
            count += isWave(i);
        return count;    
    }
};