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
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;   // Counter to keep track of visited nodes
        int result = -1; // Variable to store the kth smallest value

        inOrderTraversal(root, k, count, result);

        return result;
    }

    void inOrderTraversal(TreeNode *node, int k, int &count, int &result)
    {
        if (!node)
        {
            return;
        }

        inOrderTraversal(node->left, k, count, result);

        // Increment the counter and check if it's equal to k
        if (++count == k)
        {
            result = node->val;
            return;
        }

        inOrderTraversal(node->right, k, count, result);
    }
};