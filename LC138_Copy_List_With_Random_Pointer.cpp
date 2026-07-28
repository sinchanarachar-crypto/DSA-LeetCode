/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    /*{
        if(head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;

        while (curr)
        {
            Node* temp = new Node(curr -> val);

            mp[curr] = temp; //Storing

            if(newHead == NULL)
            {
                newHead = temp;
                prev = newHead;
            }
            else
            {
                prev -> next = temp;
                prev = temp;
            }

            curr = curr -> next;
        }

        //Fill Random Pointers

        curr = head;
        Node* newCurr= newHead;

        while(curr)
        {
            if(curr -> random == NULL)
            {
                newCurr -> random = NULL;
            }
            else
            {
                newCurr -> random = mp[curr -> random];
            }

            curr = curr -> next;
            newCurr= newCurr -> next;
        }

        return newHead;
    }*/

    {
        if (head == NULL) return NULL;

        // Step 1: Insert the new nodes in between original Linked List nodes
        Node* curr = head;
        while (curr) {
            Node* currNext = curr->next;
            
            curr->next = new Node(curr->val); 
            curr->next->next = currNext;
            curr = currNext;
        }

        // Step 2: Deep copy of Random Pointers
        curr = head;
        while (curr) 
        {
            if (curr->random == NULL) 
            {
                curr->next->random = NULL;
            }
            else
            {
                curr->next->random = curr->random->next;
            }
            // Advance by two steps to move to the next original node
            curr = curr->next->next; 
        }

        // Step 3: Separate the interleaved Linked Lists safely
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;

        while (curr)
        {
            curr->next = curr->next->next;
            newCurr->next = (newCurr->next) ? newCurr->next->next : NULL;
            
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }

};