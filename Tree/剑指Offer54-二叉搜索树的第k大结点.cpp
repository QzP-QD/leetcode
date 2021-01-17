/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if(root == nullptr)
            return -1;

        int result = -1;
        stack<TreeNode*> mystack;
        while(root != nullptr || !mystack.empty())
        {
            while(root != nullptr){
                mystack.push(root);
                root = root->right;
            }
            root = mystack.top();
            mystack.pop();
            k --;
            if(k == 0)
            {
                result = root->val;
                break;
            }
           root = root->left;
        }
        return result;
    }
};
