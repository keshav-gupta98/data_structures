vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode *>s;
    vector<int> res;
    TreeNode *curr = A;
    while(curr || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr = curr -> left;
        }
        TreeNode *temp  = s.top();
        if( temp ->right == NULL)
        {
            res.push_back(temp -> val);
            s.pop();
            while( !s.empty() && s.top() -> right == temp)
            {
                temp = s.top();
                s.pop();
                res.push_back(temp -> val);
            }
            curr = !s.empty() ? s.top() -> right : curr;
        }
        else
        {
            curr = temp -> right;
        }
    }
    return res;
}

