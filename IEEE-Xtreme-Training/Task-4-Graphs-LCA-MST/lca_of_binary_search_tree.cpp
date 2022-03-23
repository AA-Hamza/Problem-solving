/*
 * Problem Link https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {          //Assume that p < q
        if (p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }
        if (p == q)
            return p;
        
        while (root != nullptr) {
            if (root->val < p->val)
                return lowestCommonAncestor(root->right, p, q);
            else if (root->val > q->val)
                return lowestCommonAncestor(root->left, p, q);
            else
                return root;
        }
        return root;
    }
};
