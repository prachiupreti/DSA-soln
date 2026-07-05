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
    int ans = INT_MIN;

    void check(TreeNode* root, int &gain) {
        if (root == nullptr) {
            gain = 0;
            return;
        }

        int lg = 0, rg = 0;

        check(root->left, lg);
        check(root->right, rg);

        lg = max(0, lg);
        rg = max(0, rg);

        ans = max(ans, lg + rg + root->val);

        gain = max(lg, rg) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int gain = 0;
        check(root, gain);
        return ans;
    }
};