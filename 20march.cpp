class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;

        int count = 0;

        while (count + 1 < a)
        {
            count += 1;
            temp1 = temp1->next;
        }
        ListNode *dummy = temp1->next;
        temp1->next = temp2;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        // cout<<dummy->val<<"\n";

        while (count + 1 < b)
        {
            dummy = dummy->next;
            // cout<<dummy->val<<"\n";
            count += 1;
        }

        // cout<<"--\n";

        temp2->next = dummy->next;

        ListNode *ptr = list1;
        while (ptr)
        {
            // cout<<ptr->val<<"\n";
            ptr = ptr->next;
        }
        return list1;
    }
};