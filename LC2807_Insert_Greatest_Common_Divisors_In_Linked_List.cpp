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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    /*{
        if(!head || !head -> next) return head;

        ListNode* curr = head;
        ListNode* nextNode = head -> next;

        while(nextNode)
        {
            ListNode* temp = new ListNode(__gcd(curr -> val, nextNode -> val));

            curr -> next = temp;
            temp -> next = nextNode;

            curr = nextNode;
            nextNode = nextNode -> next;

        }

        return head; 
    }*/

    {
        if(!head || !head -> next) return head;
        
        ListNode* temp = insertGreatestCommonDivisors(head -> next);

        ListNode* gcdNode = new ListNode(__gcd(head -> val, head -> next -> val));

        gcdNode -> next = temp;
        head -> next = gcdNode;


        return head;
    }
};