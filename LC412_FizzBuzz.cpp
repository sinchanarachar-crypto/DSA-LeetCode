class Solution
{
public:
    vector<string> fizzBuzz(int n)
    /*{
        vector<string> arr;

        for(int i = 1; i <= n; i++)
        {
            if(i % 15 == 0)
                arr.push_back("FizzBuzz");
            else if(i % 5 == 0)
                arr.push_back("Buzz");
            else if(i % 3 == 0)
                arr.push_back("Fizz");
            else
                arr.push_back(to_string(i));
        }
        return arr;
    }*/

    {
        vector<string> arr;
        int count3 = 0;
        int count5 = 0;

        for(int i = 1; i <= n; i++)
        {
            count3++;
            count5++;

            if(count3 == 3 && count5 == 5)
            {
                arr.push_back("FizzBuzz");
                count3 = 0;
                count5 = 0;
            }

            else if(count3 == 3)
            {
                arr.push_back("Fizz");
                count3 = 0;
            }

            else if(count5 == 5)
            {
                arr.push_back("Buzz");
                count5 = 0;
            }

            else
            {
                arr.push_back(to_string(i));
            }
        }
        return arr;
    }
};