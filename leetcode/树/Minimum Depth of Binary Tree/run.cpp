/*Given a binary tree, find its minimum 
depth.The minimum depth is the number of 
nodes along the shortest path from the 
root node down to the nearest leaf node.*/

/*
递归，若为空树返回0； 
  若左子树为空，则返回右子树的最小深度+1；（加1是因为要加上根这一层，下同） 
  若右子树为空，则返回左子树的最小深度+1； 
  若左右子树均不为空，则取左、右子树最小深度的较小值，+1； 
*/
class Solution {
public:
public:
    int run(TreeNode *root) {
        if (root == NULL) return 0;
        if (!root->left) return 1+run(root->right);
        if (!root->right) return 1+run(root->left);
        return (1 + min(run(root->left), run(root->right)));
    }
};