/*****************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

******************************************************/
bool checkTree(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
    if (left == NULL && right == NULL)
        return true;

    if (left == NULL || right == NULL)
        return false;

    bool first = checkTree(left->left, right->right);
    bool second = checkTree(left->right, right->left);

    if ((left->data == right->data) && first && second)
    {
        return true;
    }
    return false;
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    checkTree(root->left, root->right);
}