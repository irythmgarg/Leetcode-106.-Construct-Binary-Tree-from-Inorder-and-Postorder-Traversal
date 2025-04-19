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

    // Helper function to find the index of a node in inorder traversal
    int findindex(vector<int>& inorder, int value, int instart, int inend) {
        for (int i = instart; i <= inend; i++) {
            if (inorder[i] == value)
                return i;
        }
        return -1; // Not expected with valid input
    }

    // Recursive function to construct the tree
    TreeNode* maketree(vector<int>& postorder, vector<int>& inorder,
                       int poststart, int postend, int instart, int inend) {

        if (poststart > postend || instart > inend)
            return NULL;

        // The current root is the first element in reversed postorder
        TreeNode* node = new TreeNode(postorder[poststart]);

        // Find index of root in inorder to divide left and right subtree
        int ind = findindex(inorder, postorder[poststart], instart, inend);
        int index = inend - ind; // Number of nodes in right subtree

        // Build right subtree first (due to reversed postorder)
        node->right = maketree(postorder, inorder, poststart + 1, poststart + index, ind + 1, inend);

        // Build left subtree
        node->left = maketree(postorder, inorder, poststart + index + 1, postend, instart, ind - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        reverse(postorder.begin(), postorder.end());  // Reverse postorder to treat like "root-right-left"
        return maketree(postorder, inorder, 0, n - 1, 0, n - 1);
    }
};
