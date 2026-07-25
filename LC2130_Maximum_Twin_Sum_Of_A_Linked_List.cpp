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
    int pairSum(ListNode* head)
    /*{
        vector<int> arr;
        int result = 0;
        while(head != NULL)
        {
            arr.push_back(head -> val);
            head = head -> next;
        }
        int i = 0;
        int j = arr.size() - 1;

        while(i < j)
        {
            result = max(result, (arr[i] + arr[j]));
            i++;
            j--;
        }
        return result;

    }*/

    /*{
        stack<int> st;
        ListNode* curr = head;
        while(curr != NULL)
        {
            st.push(curr -> val);
            curr = curr -> next;
        }
        int result = 0, i = 1;
        int n = st.size()/2;

        curr = head;

        while(i <= n)
        {
            result = max(result,(curr->val + st.top()));
            i++;
            curr = curr -> next;
            st.pop();
        }
        return result;
    }*/

    {
        //Finiding Mid
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* mid = slow;

        //Reversing 2nd Half
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while(mid != NULL)
        {
            nextNode = mid -> next;
            mid -> next = prev;
            prev = mid;
            mid = nextNode;
        }

        //Maximum Sum
        int result = 0;

        ListNode* curr = head;

        while(prev != NULL)
        {
            result = max(result, curr->val + prev -> val);
            curr = curr -> next;
            prev = prev -> next;
        }
        return result;
    }
};