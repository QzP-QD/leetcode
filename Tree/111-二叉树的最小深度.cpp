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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int height = 1;

        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty()){
            int len = myqueue.size();
            for(int i=0 ; i<len; i ++){
                TreeNode* cur = myqueue.front();
                myqueue.pop();
                if(cur->left == nullptr  && cur->right == nullptr){
                    return height;
                }
                if(cur->left != nullptr){
                    myqueue.push(cur->left);
                }
                if(cur->right != nullptr){
                    myqueue.push(cur->right);
                }
            }
            height ++;
        }
        return -1;  //不会在这退出程序
    }
};
