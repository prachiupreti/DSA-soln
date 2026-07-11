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
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParentMap(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            parent[root->left] = root;
            buildParentMap(root->left);
        }

        if (root->right) {
            parent[root->right] = root;
            buildParentMap(root->right);
        }
    }

    TreeNode* findStartNode(TreeNode* root, int start) {
        if (!root) return nullptr;

        if (root->val == start) return root;

        TreeNode* left = findStartNode(root->left, start);
        if (left) return left;

        return findStartNode(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {

        buildParentMap(root);

        TreeNode* startNode = findStartNode(root, start);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(startNode);
        visited.insert(startNode);

        int minutes = -1;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) &&
                    !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }

            minutes++;
        }

        return minutes;
    }
};