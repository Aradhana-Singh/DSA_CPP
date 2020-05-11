/* Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.*/

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
    // Tail recursion
    int maxDepthHelper(TreeNode* root, int depth){
        if(root == NULL) return depth;
        return max(maxDepthHelper(root->left , depth+1) , maxDepthHelper(root->right, depth+1));
    }
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root,0);
    }
};