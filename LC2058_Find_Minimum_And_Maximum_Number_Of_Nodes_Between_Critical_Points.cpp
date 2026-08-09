/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head -> next;
        int i = 1;
        int prevCritical = 0;
        int firstCritical = 0;
        int minDist = INT_MAX;
        int maxDist;

        while(curr -> next != NULL)
        {
            if((curr -> val > prev -> val && curr -> val > curr -> next -> val) ||
            (curr -> val < prev -> val && curr -> val < curr -> next -> val))
            {
                if(prevCritical == 0)
                {
                    prevCritical = i;
                    firstCritical = i;
                }
                else
                {
                    minDist = min(minDist, i - prevCritical);
                    prevCritical = i;
                }
            }

            i++;
            prev = curr;
            curr = curr -> next;
        }

        if(prevCritical == firstCritical) return {-1, -1};

        maxDist = prevCritical - firstCritical;
        return {minDist, maxDist};
    }
};