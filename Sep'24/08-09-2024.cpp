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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* nptr=head;
        while(nptr!=NULL)
        {
            len++;
            nptr=nptr->next;
        }
        nptr=head;
        vector<ListNode*>vp(k);
        int cnt=0,le=0;
        int m=k;
       for(int i=0;i<k;i++)
       {
           int le=(len/m)+(len%m>0);
           // cout<<le<<" "<<k<<"\n";
           len-=le;
           m-=1;
           if(le>0) 
           {
               vp[i]=nptr;
           for(int j=1;j<le;j++)
           {
                nptr=nptr->next;
           }
           ListNode* ptr=nptr->next;
           nptr->next=NULL;
           nptr=ptr;
           // cout<<vp[i]->val<<"\n";
           }
         
       }
        return vp;
    }
};
