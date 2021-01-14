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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }

        queue<TreeNode*> myqueue;
        queue<int> heightqueue;
        int lastheight = -1;

        myqueue.push(root);
        heightqueue.push(0);
        while(!myqueue.empty()){
            TreeNode* cur = myqueue.front();
            myqueue.pop();
            int curheight = heightqueue.front();
            heightqueue.pop();

            if(cur->left != nullptr){
                myqueue.push(cur->left);
                heightqueue.push(curheight+1);
            }
            if(cur->right != nullptr){
                myqueue.push(cur->right);
                heightqueue.push(curheight+1);
            }

            if(lastheight != curheight){
                vector<int> newvec;
                result.push_back(newvec);
                lastheight = curheight;
            }
            result[curheight].push_back(cur->val);
        }
        return result;
    }
};
