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
int maxDia;
    int diameter(TreeNode* root) {
        if(!root) return 0;

        int l = diameter(root->left);
        int r = diameter(root->right);
        maxDia = max(l+r , maxDia);

        return max(l, r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxDia = 0;

        int noans = diameter(root);

        return maxDia;
    }
};
