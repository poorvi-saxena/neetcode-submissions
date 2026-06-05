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
    bool validate(TreeNode* root, int minv, int maxv) {
        if(!root) return true;
        if(root->val <= minv || root->val >= maxv) return false;

        bool l = validate(root->left, minv, root->val);
        bool r = validate(root->right, root->val, maxv);
        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }
};
// 2 1 3 