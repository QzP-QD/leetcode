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
class Solution1 {           //递归
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){
            return result;
        }

        inorder(root, result);
        return result;
    }

    void inorder(TreeNode* root, vector<int>& result){
        if(root == nullptr){
            return ;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);

        return ;
    }
};

class Solution2 {       //迭代法1（超出时间限制）
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr){
            return result;
        }

        stack<TreeNode*> mystack;
        mystack.push(root);
        while(!mystack.empty()){
            TreeNode* cur = mystack.top();
            if(cur->left != nullptr){
                mystack.push(cur->left);
            }else{
                cur = mystack.top();
                mystack.pop();
                result.push_back(cur->val);
                if(cur->right != nullptr){
                    mystack.push(cur->right);
                }
            }
        }

        return result;
    }
};

class Solution3 {       //迭代法2（官方正解）
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> mystack;

        while(root != nullptr || !mystack.empty()){
            while(root != nullptr){
                mystack.push(root);
                root = root->left;
            }
            root = mystack.top();
            mystack.pop();
            result.push_back(root->val);
            root = root->right;
        }

        return result;
    }
};


