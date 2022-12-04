#include "Expressions.h"


class BSTNode
{
public:
    int data;
    BSTNode* Left;
    BSTNode* Right;
    BSTNode* Parent;
};

class BST
{
public:
    BST();

    BSTNode* Insert(BSTNode*& node, int key) {
        if (node == NULL)
        {
            node = new BSTNode;
            node->data = key;
            node->Left = NULL;
            node->Right = NULL;
            node->Parent = NULL;
        }
        else if (node->data < key)
        {
            node->Right = Insert(node->Right, key);
            node->Right->Parent = node;
        }

        else
        {
            node->Left = Insert(node->Left, key);
            node->Left->Parent = node;
        }
        return node;
    };
    void PrintTreeInOrder(BSTNode* node) {
        {
            if (node == NULL)
                return;

            PrintTreeInOrder(node->Left);

            std::cout << node->data << " ";
            PrintTreeInOrder(node->Right);
        }
    };
    BSTNode* Search(BSTNode* node, int key) {
        if (node == NULL)
            return NULL;
        else if (node->data == key)
            return node;
        else if (node->data < key)
            return Search(node->Right, key);
        else
            return Search(node->Left, key);
    };

    int FindMax(BSTNode* node)
    {
        if (node == NULL)
            return -1;
        else if (node->Right == NULL)
            return node->data;
        else
            return FindMax(node->Right);
    }

    int FindMin(BSTNode* node)
    {
        if (node == NULL)
            return -1;
        else if (node->Left == NULL)
            return node->data;
        else
            return FindMin(node->Left);
    }

    int Successor(BSTNode* node, int key)
    {
        BSTNode* keyNode = Search(node, key);

        if (keyNode == NULL) {
            return -1;
        }
        if (keyNode->Right != NULL)
        {
            return FindMin(keyNode->Right);
        }
        else
        {
            BSTNode* parentNode = keyNode->Parent;
            BSTNode* currentNode = keyNode;

            while ((parentNode != NULL) &&
                (currentNode == parentNode->Right))
            {
                currentNode = parentNode;
                parentNode = currentNode->Parent;
            }

            return parentNode == NULL ?
                -1 :
                parentNode->data;
        }
    }

    int Predecessor(BSTNode* node, int key)
    {
        BSTNode* keyNode = Search(node, key);

        if (keyNode == NULL) {
            return -1;
        }
        if (keyNode->Left != NULL)
        {
            return FindMax(keyNode->Left);
        }
        else
        {
            BSTNode* parentNode = keyNode->Parent;
            BSTNode* currentNode = keyNode;

            while ((parentNode != NULL) &&
                (currentNode == parentNode->Left))
            {
                currentNode = parentNode;
                parentNode = currentNode->Parent;
            }
            return parentNode == NULL ?
                -1 :
                parentNode->data;
        }
    }
    BSTNode* Remove(BSTNode* node, int key)
    {
        if (node == NULL)
            return NULL;

        if (node->data == key)
        {
            if (node->Left == NULL && node->Right == NULL)
                node = NULL;
            else if (node->Left == NULL && node->Right != NULL)
            {
                node->Right->Parent = node->Parent;
                node = node->Right;
            }
            else if (node->Left != NULL && node->Right == NULL)
            {
                node->Left->Parent = node->Parent;
                node = node->Left;
            }
            else
            {
                int successorKey = Successor(node, key);

                node->data = successorKey;

                node->Right = Remove(node->Right, successorKey);
            }
        }
        else if (node->data < key)
            node->Right = Remove(node->Right, key);
        else
            node->Left = Remove(node->Left, key);
        return node;
    }

    void printPreorder(BSTNode* node, int length)
    {
        if (node == NULL) return;
        cout << node->data << " ";
        length--;
        printPreorder(node->Left, ++length);
        printPreorder(node->Right, ++length);
    }

    void printInorder(BSTNode* node, int length)
    {
        if (node == NULL) return;
        printInorder(node->Left, ++length);
        cout << node->data << " ";
        length--;
        printInorder(node->Right, ++length);
    }

    void printPostorder(BSTNode* node, int length)
    {
        if (node == NULL) return;
        printPostorder(node->Left, ++length);
        printPostorder(node->Right, ++length);
        cout << node->data << " ";
        length--;
    }

    void printWidth(BSTNode* node)
    {
        if (node == NULL) return;
        queue<BSTNode*> t;
        t.push(node);

        while (!t.empty())
        {
            BSTNode* temp = t.front();
            t.pop();
            cout << temp->data << " ";

            if (temp->Left != NULL)
                t.push(temp->Left);

            if (temp->Right != NULL)
                t.push(temp->Right);
        }
    }

};


BST::BST()
{
}

void printTree(BSTNode* root, Trunk* prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->Right, trunk, true);

    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << " " << root->data << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";

    printTree(root->Left, trunk, false);
}