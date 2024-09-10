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
class Solution {
public:
    
    int gcd(int a, int b) 
    { 
        // Find Minimum of a and b 
        int result = min(a, b); 
        while (result > 0) { 
            if (a % result == 0 && b % result == 0) { 
                break; 
            } 
            result--; 
        } 

        // Return gcd of a and b 
        return result; 
    } 
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        
        while(ptr1 and ptr2)
        {
            ListNode* temp = new ListNode(gcd(ptr1->val,ptr2->val));
            ptr1->next = temp;
            temp->next = ptr2;
            
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        
        return head;
    }
};
