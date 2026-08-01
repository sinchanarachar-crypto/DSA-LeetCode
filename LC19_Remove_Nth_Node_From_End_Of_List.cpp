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

    /*int getLengthOfList(ListNode* head)
    {
        int length = 0;
        while(head != NULL)
        {
            length++;
            head = head -> next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int L = getLengthOfList(head);

        if(L == n)
        {
            ListNode* temp = head -> next;
            delete(head);
            return temp;
        }

        int x = L - n;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(x--)
        {
            prev = temp;
            temp = temp -> next;
        }

        prev -> next = temp -> next;

        delete(temp);

        return head;

    }*/


    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* temp = head;

        for(int i = 1; i <= n; i++)
            temp = temp -> next;

        if(temp == NULL)
        {
            ListNode* result = head -> next;
            delete(head);
            return result;
        }

        ListNode* prev = head;

        while(temp != NULL && temp -> next != NULL)
        {
            prev = prev -> next;
            temp = temp -> next;
        }

        ListNode* de = prev -> next;
        prev -> next = prev -> next -> next;
        delete(de);

        return head;
    }
};