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

    bool isPalindrome(ListNode *head)
    {
        ListNode *ptr1 = head;

        // find middle using slow and fast pointer

        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast and fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *ptr2 = reverseList(slow->next);
        slow->next = NULL;

        while (ptr1 and ptr2)
        {
            if (ptr1->val != ptr2->val)
                return false;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return true;
    }
};