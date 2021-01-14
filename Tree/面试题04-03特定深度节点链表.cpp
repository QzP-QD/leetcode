/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> result;

        queue<TreeNode*> myqueue;
        //用来存放myqueue中每个节点对应的高度
        queue<int> height;
        //初始化
        myqueue.push(tree);
        height.push(0);
        //上一个节点所属的层数
        int lastindex = -1;

        while(!myqueue.empty()){
            TreeNode* cur = myqueue.front();
            int curheight = height.front();
            myqueue.pop();
            height.pop();

            if(cur->left != nullptr){
                myqueue.push(cur->left);
                height.push(curheight+1);
            }
            if(cur->right != nullptr){
                myqueue.push(cur->right);
                height.push(curheight+1);
            }

            ListNode* curlistnode = new ListNode(cur->val);
            if(lastindex != curheight){
                result.push_back(curlistnode);
                lastindex = curheight;
            }else{
                ListNode* p = result[curheight];
                while(p->next != nullptr){
                    p = p->next;
                }
                p->next = curlistnode;
            }
        }

        return result;
    }
};
