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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* cur = new TreeNode(val);
            return cur;
        }

        //得到A数组和B数组
        vector<int> initvec;
        buildvec2(root,initvec);
        initvec.push_back(val);

        //用B构建最大树
        TreeNode* resultroot = getTree(initvec, 0, initvec.size()-1);
        return resultroot;
    }

    vector<int> buildvec(TreeNode* root){       //通过递归
        vector<int> result;
        if(root == nullptr){
            return result;
        }
        vector<int> leftvec =  buildvec(root->left);
        vector<int> rightvec =  buildvec(root->right);

        for(int i=0 ; i < leftvec.size() ; i ++){
            result.push_back(leftvec[i]);
        }
        result.push_back(root->val);
        for(int i=0 ; i < rightvec.size() ; i ++){
            result.push_back(rightvec[i]);
        }
        return result;
    }
    void buildvec2(TreeNode* root, vector<int>& result){    //通过中序遍历
        if(root == nullptr){
            return ;
        }
        buildvec2(root->left,result);
        result.push_back(root->val);
        buildvec2(root->right,result);

        return ;
    }


    TreeNode* getTree(vector<int> initvec, int begin, int end){
        if(begin > end){
            return nullptr;
        }
        int maxvalindex = begin;
        for(int i = begin ; i <= end; i ++){
            if(initvec[i] > initvec[maxvalindex]){
                maxvalindex = i;
            }
        }
        TreeNode* root = new TreeNode(initvec[maxvalindex]);
        root->left = getTree(initvec, begin, maxvalindex - 1);
        root->right = getTree(initvec, maxvalindex+1, end);

        return root;
    }
};
