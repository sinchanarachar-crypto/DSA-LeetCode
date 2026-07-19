class Solution
{
public:
    // vector<int> array;
    // Solution(ListNode* head)
    // {
    //     ListNode* temp = head;
    //     while(temp)
    //     {
    //         array.push_back(temp -> val);
    //         temp = temp -> next;
    //     }
    // }
    
    // int getRandom()
    // {
    //     int n = array.size();
    //     int x;
    //     x = rand() % n;

    //     return array[x];
    // }

    ListNode* Head;
    Solution(ListNode* head)
    {
        Head = head;
    }
    int getRandom()
    {
        int count = 1;
        int result = 0;
        ListNode* temp = Head;

        while(temp != NULL)
        {
            if(rand() % count < 1.0 / count)
                result = temp -> val;

            count++;
            temp = temp -> next;
        }
        return result;
    }
};
