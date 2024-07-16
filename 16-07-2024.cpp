class Solution {
private:
    TreeNode* helpmeLCS(TreeNode* root, int start, int end)
    {
        if (root == NULL)  return NULL;
        if (root -> val == start or root -> val == end)   return root;
        
        TreeNode* left = helpmeLCS(root->left, start, end);
        TreeNode* right = helpmeLCS(root->right, start, end);
        
        if (left == NULL)   return right;
        else if (right == NULL)   return left;
        else            return root;
    }
    
    bool Path(TreeNode* root, int start, string& s)
    {
        if (root == NULL)   return false;
        if (root->val == start)
        {
            return true;
        }
        
        s += 'L';
        if(Path(root->left, start, s))   return true;
        s.pop_back();
        
        s += 'R';
        if(Path(root->right, start, s))   return true;
        s.pop_back();
        
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* parent = helpmeLCS(root, startValue, destValue);
        //cout<<"PARENT"<<" "<<parent->val<<endl;
        string ans = "";
        
        string lefty = "";
        Path(parent, startValue, lefty);
        cout<<lefty<<endl;
        
        string righty = "";
        Path(parent, destValue, righty);
        //cout<<righty<<endl;
        
        for (auto& x:lefty) 
        {
            //cout<<x<<":";
            x = 'U';
            //cout<<x<<",";
        }
        //cout<<endl;
        //cout<<lefty<<endl;
        
        return lefty + righty; 
    }
};
