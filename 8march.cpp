class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // Naive approach

        int cnt_nodes = 0;

        ListNode *ptr = head;

        while (ptr != NULL)
        {
            ptr = ptr->next;
            cnt_nodes++;
        }

        int mid = cnt_nodes / 2 + 1;

        ptr = head;

        while (mid != 1)
        {
            ptr = ptr->next;
            mid--;
        }

        return ptr;

        // time complexity - O(N) + O(N/2);

        // optimal approach - (Hare and tortoise algorithm)

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};