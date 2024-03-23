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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *temp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    void reorderList(ListNode *head)
    {
        // find middle

        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *newList = reverseList(slow->next);
        slow->next = NULL;

        ListNode *ptr = head;

        while (ptr and newList)
        {

            // cout<<ptr->val<<" "<<newList->val<<"\n";
            ListNode *temp = ptr->next;
            ptr->next = newList;
            newList = newList->next;
            ptr->next->next = temp;
            ptr = temp;
        }
    }
};