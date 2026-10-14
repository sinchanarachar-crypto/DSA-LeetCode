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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;

        int carry = 0;
        int sum;
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;


        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            sum = carry;

            if(l1 != NULL)
            {
                sum += l1 -> val;
                l1 = l1 -> next;
            }

            if(l2 != NULL)
            {
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);

            tail -> next = newNode;
            tail = tail -> next;
        }
        ListNode* res = dummyHead -> next;
        delete dummyHead;
        return res;        
        
    }
};