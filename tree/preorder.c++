vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *curr = A;
    while(curr || !s.empty())
    {
        while(curr)
        {
            res.push_back(curr->val);
            s.push(curr);
            curr = curr -> left;
        }
    TreeNode *temp = s.top();
    s.pop();
    curr = temp -> right;
    }
    return res;
}
