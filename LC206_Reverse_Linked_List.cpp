/**
 * Definition for singly-linked list.
 * struct ListNode
 *{
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* nextNode = curr->next;  //Save Next
            curr->next = prev;                //reverse arr
            prev = curr;                      //advance prev
            curr = nextNode;                  //advance curr
        }
        return prev;                          //New head
    }

    /*{
        if(!head || !head->next)
            return head;                       // base case

        ListNode* newHead = reverseList(head->next);       //reverse the arrow
        head->next->next = head;                          //cut old forward link
        head->next = nullptr;
        return newHead;
    }*/
};