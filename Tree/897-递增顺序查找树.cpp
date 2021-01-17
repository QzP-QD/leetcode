/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        vector<int> nums;
        inorder(nums, root);
        TreeNode* newroot = new TreeNode;
        TreeNode* p = newroot;
        for(int i = 0 ; i < nums.size(); i ++){
            newroot->val = nums[i];
            newroot->left = nullptr;
            if(i != nums.size()-1){
                newroot->right = new TreeNode;
                newroot = newroot->right;
            }
        }
        return p;
    }
    void inorder(vector<int>& nums, TreeNode* root){
        if(root == nullptr)
            return ;

        inorder(nums, root->left);
        nums.push_back(root->val);
        inorder(nums, root->right);

        return ;
    }
};
