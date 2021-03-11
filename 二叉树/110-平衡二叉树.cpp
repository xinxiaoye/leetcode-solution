/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/***题解
    解法类似于求树的最大深度，但有两个不同的地方:
    一是我们需要先处理子树的深度再进行 比较，
    二是如果我们在处理子树时发现其已经不平衡了，则可以返回一个-1，使得所有其长辈节 点可以避免多余的判断(本题的判断比较简单，做差后取绝对值即可;
    但如果此处是一个开销较 大的比较过程，则避免重复判断可以节省大量的计算时间)。
***/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }

    int helper(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = helper(root->left), right = helper(root->right);
        if(left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return 1 + max(left, right);
    }
};