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
    TreeNode* inOrderPred(TreeNode* curr) {
        TreeNode* pred = curr -> left;
        while (pred -> right != nullptr && pred -> right != curr) 
            pred = pred -> right;
        return pred;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int ans = 0;

        while (curr != nullptr) {
            if (curr -> left == nullptr) {
                k--;
                if (k == 0) ans = curr -> val;
                curr = curr -> right;
            }
            else {
                TreeNode* pred = inOrderPred(curr);
                if (pred -> right == nullptr) {
                    pred -> right = curr;
                    curr = curr -> left;
                }
                else {
                    pred -> right = nullptr;
                    k--;
                    if (k == 0) ans = curr -> val;
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }        
};