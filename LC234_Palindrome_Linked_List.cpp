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


/*class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        if(head == NULL || head -> next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast -> next)
        {
            fast = fast -> next -> next;

            ListNode* temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }

        if(fast) slow = slow -> next;  // ODD length 

        while(prev && slow)
        {
            if(prev -> val != slow -> val) return false;

            prev = prev -> next;
            slow = slow -> next;
        }

        return true;
    }
};*/

class Solution
{
public:

    ListNode* curr;
    bool recur(ListNode* head)
    {
        if(head == NULL) return true;

        bool ans = recur(head -> next);

        if(head -> val != curr -> val) return false;

        curr = curr -> next;
        return ans;
    }

    bool isPalindrome(ListNode* head)
    {
        curr = head;
        return recur(head);
    }
};






