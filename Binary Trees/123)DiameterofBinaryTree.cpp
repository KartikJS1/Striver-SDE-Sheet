/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int Height(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);
    return (max(leftHeight, rightHeight) + 1);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = Height(root->left);
    int rightHeight = Height(root->right);

    int currentDiameter = (leftHeight + rightHeight);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return max(max(leftDiameter, rightDiameter), currentDiameter);
}
