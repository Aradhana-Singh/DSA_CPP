//Given inorder and postorder traversal of a tree, construct the binary tree.

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
    int find(vector <int> v, int start,int end, int target){
        for(int i = start; i<=end; i++) 
            if(v[i] == target) return i;
        return -1;
    }
    TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int postS, int postE){
        if(inS > inE) return NULL;
        TreeNode* root = new TreeNode(postorder[postE]);
        int target = find(inorder,inS,inE,postorder[postE]);
        root->left = buildHelper(inorder,postorder, inS, target-1, postS, postS+target-inS-1);
        root->right = buildHelper(inorder,postorder, target+1, inE, postS+target-inS, postE-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildHelper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};