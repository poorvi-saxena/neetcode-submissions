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
    int util(TreeNode* node) {
        int l = 0, r=0;
        if(node->left) l = max(0,util(node->left));
        if(node->right) r = max(0,util(node->right));

        ans = max(ans, l+r+node->val);
        return max(l, r)+node->val;
    }

    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        ans = max(util(root) , ans);
        return ans == INT_MIN ? 0 : ans;
    }
};
