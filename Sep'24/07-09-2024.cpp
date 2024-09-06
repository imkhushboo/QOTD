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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* ptr = new ListNode(0);
        ListNode* ans = ptr;
        
        ListNode* trv = head;
        map<int,int>mp;
        for(auto x:nums) mp[x]++;
        
        
        while(trv)
        {
            if(mp.find(trv->val)== mp.end())
            {
                ptr->next = new ListNode(trv->val);
                // ptr->next->next= NULL;
                ptr = ptr->next;
            }
            trv = trv->next;
        }
        
        return ans->next;
        
    }
};
