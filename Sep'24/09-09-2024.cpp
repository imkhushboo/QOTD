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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>a(m,vector<int>(n,-1));
        int k=0,l=0,i;
        ListNode* ptr=head;
        while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
            // if(ptr==NULL) break;
        for (i = l; i < n; ++i) {
            if(ptr==NULL) break;
             a[k][i]=ptr->val;
            ptr=ptr->next;
        }
        k++;
  
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            if(ptr==NULL) break;

             a[i][n - 1] =ptr->val;
            ptr=ptr->next;
        }
        n--;
  
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                if(ptr==NULL) break;
               a[m - 1][i] =ptr->val;
                ptr=ptr->next;
            }
            m--;
        }
  
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
            if(ptr==NULL) break;

                a[i][l] =ptr->val;
                ptr=ptr->next;
            }
            l++;
        }
    }
        return a;
        
    }
};
