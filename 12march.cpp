class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        if(head == NULL)
        {
            return NULL;
        }
        
        
        int sum = 0;
        
        ListNode* ptr = head;
        
        while(ptr)
        {
            sum += ptr->val;
            
            if(sum == 0)
            {
                head = ptr->next;
                sum = 0;
            }
            
            ptr = ptr->next;
        }
        
        if(head != NULL)
        {
            head->next = removeZeroSumSublists(head->next);
        }
        
        return head;
        
        
    }
};