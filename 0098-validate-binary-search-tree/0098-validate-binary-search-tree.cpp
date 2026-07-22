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
private: 
    bool inOrderTraversal(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr) return true;
        if (!inOrderTraversal(node -> left, prev)) return false;
        if (prev != nullptr && prev -> val >= node -> val) return false;
        prev = node;
        return inOrderTraversal(node -> right, prev);
    }


public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inOrderTraversal(root, prev);
    }
};