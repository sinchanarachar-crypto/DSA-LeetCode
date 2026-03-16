class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int MinPrice = INT_MAX;
        int profit = 0;

        for(int price : prices)
        {
            MinPrice = min(MinPrice, price);
            profit = max(profit, price - MinPrice );
        }
        return profit;
    }


    /*{
        int profit = 0; 
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            for(int j = n-1; j > i; j--)
            {
                if(prices[j] - prices[i] > profit)
                    profit = prices[j] - prices[i];
            }
        }
        return profit;
        
    }*/
};