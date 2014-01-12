#include <iostream>
using namespace std;

template <typename T>
struct TreeNode
{
    T value;
    TreeNode* left;
    TreeNode* right;
};

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : _treeRoot(NULL)
    {

    }

    void Insert(T value)
    {
        insertNode(&_treeRoot, value);
    }

    void Delete(T value)
    {
        TreeNode<T>* parent = NULL;
        auto node = search(_treeRoot, value, &parent);

        deleteNode(node, parent);
    }

    void deleteNode(TreeNode<T>* node, TreeNode<T>* parent)
    {
        auto getLink = [&]() -> void*
        {
            if (!parent)
                return NULL;

            if (parent->left == node)
                return &parent->left;
            else
                return &parent->right;
        };

        if (node->left == NULL && node->right == NULL) // Leaf
        {
            if (!parent)
            {
                _treeRoot = NULL;
                return;
            }
            else
            {
                auto link = (TreeNode<T>**)getLink();
                *link = NULL;

                delete node;
            }
        }
        else
            // Only one child
            if ((node->right == NULL && node->left != NULL) || (node->right != NULL && node->left == NULL))
            {
                if (!parent)
                {
                    _treeRoot = node->right == NULL ? node->left : node->right;
                }
                else
                {
                    auto link = (TreeNode<T>**)getLink();
                    *link = node->right == NULL ? node->left : node->right;
                }

                delete node;
            }
            else // Both children
            {
                TreeNode<T> *parent = node;
                auto minNode = minimum(node->right, &parent);

                node->value = minNode->value;

                deleteNode(minNode, parent);
            }
    }

    TreeNode<T>* Search(T value)
    {
        TreeNode<T>* parent = NULL;
        auto result = search(_treeRoot, value, &parent);

        if (parent)
            cout << "Parent value: " << parent->value << endl;

        return result;
    }

    T Minimum()
    {
        if (_treeRoot == NULL)
            throw std::exception();

        auto current = _treeRoot;

        while (current->left)
        {
            current = current->left;
        }

        return current->value;
    }

    void Print()
    {
        if (_treeRoot == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        auto printFunc = [](TreeNode<T>* node)
        {
            cout << node->value << " ";
        };

        traverseInOrderDo(_treeRoot, printFunc);
    }

private:
    TreeNode<T>* _treeRoot;

    void insertNode(TreeNode<T>** root, T value)
    {
        if (*root == NULL)
        {
            auto newNode = new TreeNode<T>();
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->value = value;

            *root = newNode;
        }
        else if (value < (*root)->value)
        {
            insertNode(&((*root)->left), value);
        }
        else if (value > (*root)->value)
        {
            insertNode(&((*root)->right), value);
        }
    }

    TreeNode<T>* search(TreeNode<T>* tree, T value, TreeNode<T>** parent = NULL)
    {
        if (tree == NULL)
        {
            *parent = NULL;
            return NULL;
        }

        if (value < tree->value)
        {
            *parent = tree;
            search(tree->left, value, parent);
        }
        else if (value > tree->value)
        {
            *parent = tree;
            search(tree->right, value, parent);
        }
        else
            return tree;
    }

    TreeNode<T>* minimum(TreeNode<T>* root, TreeNode<T>** parent)
    {
        if (_treeRoot == NULL)
        {
            *parent = NULL;
            return NULL;
        }

        auto current = root;

        while (current->left)
        {
            *parent = current;
            current = current->left;
        }

        return current;
    }

    template <typename Func>
    void traverseInOrderDo(TreeNode<T>* tree, Func action)
    {
        if (tree == NULL)
            return;

        traverseInOrderDo(tree->left, action);
        action(tree);
        traverseInOrderDo(tree->right, action);
    }

    template <typename Func>
    void traversePostOrderDo(TreeNode<T>* tree, Func action)
    {
        if (tree == NULL)
            return;

        traversePostOrderDo(tree->right, action);
        action(tree);
        traversePostOrderDo(tree->left, action);
    }
};
