/*Given a binary tree, find its minimum 
depth.The minimum depth is the number of 
nodes along the shortest path from the 
root node down to the nearest leaf node.*/

/*
�ݹ飬��Ϊ��������0�� 
  ��������Ϊ�գ��򷵻�����������С���+1������1����ΪҪ���ϸ���һ�㣬��ͬ�� 
  ��������Ϊ�գ��򷵻�����������С���+1�� 
  ��������������Ϊ�գ���ȡ����������С��ȵĽ�Сֵ��+1�� 
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