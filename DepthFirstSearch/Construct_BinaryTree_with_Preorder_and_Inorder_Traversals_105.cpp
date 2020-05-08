// Given preorder and inorder traversal of a tree, construct the binary tree.

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
    int find(vector<int> v, int target){
        for(int i =0 ;i<v.size();i++) {
            if(v[i] == target) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps ,int pe, int is,int ie){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int target = find(inorder,preorder[ps]);
        root->left = build(preorder,inorder,ps+1, ps+target-is,is,target-1);
        root->right = build(preorder,inorder,ps+target-is+1,pe,target+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};