vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *curr = A;
    while(curr || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr = curr -> left;
        }
    TreeNode *temp = s.top();
    res.push_back(temp->val);
    s.pop();
    curr = temp -> right;
    }
    return res;
}
