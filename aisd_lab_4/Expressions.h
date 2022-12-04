#include <iostream>
#include <stack>
#include <string>
#include <queue> 

using namespace std;

class Node
{
public:
    char data;
    Node* left, * right;

    Node(char data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    };

    Node(char data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    };
};
struct Trunk
{
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk* p)
{
    if (p == nullptr) {
        return;
    }

    showTrunks(p->prev);
    cout << p->str;
}

void printTree4Expression(Node* root, Trunk* prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree4Expression(root->right, trunk, true);

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

    printTree4Expression(root->left, trunk, false);
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int prec(char c)
{
    if (c == '*' || c == '/') {
        return 3;
    }

    if (c == '+' || c == '-') {
        return 4;
    }

    if (c == '&') {
        return 8;
    }

    if (c == '^') {
        return 9;
    }

    if (c == '|') {
        return 10;
    }

    return INT_MAX;
}


string infixToPostfix(string infix)
{
    stack<char> s;

    string postfix;

    for (char c : infix)
    {
        if (c == '(') {
            s.push(c);
        }

        else if (c == ')')
        {
            while (s.top() != '(')
            {
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }

        else if (isOperand(c)) {
            postfix.push_back(c);
        }

        else {

            while (!s.empty() && prec(c) >= prec(s.top()))
            {
                postfix.push_back(s.top());
                s.pop();
            }

            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }

    return postfix;
}

string preToPost(string prefix)
{

    stack<string> s;

    int length = prefix.size();

    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(prefix[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = op1 + op2 + prefix[i];

            s.push(temp);
        }

        else {

            s.push(string(1, prefix[i]));
        }
    }

    return s.top();
}

Node* construct(string postfix)
{
    if (postfix.length() == 0) {
        return nullptr;
    }

    stack<Node*> s;

    for (char c : postfix)
    {
        if (isOperator(c))
        {
            Node* x = s.top();
            s.pop();

            Node* y = s.top();
            s.pop();

            Node* node = new Node(c, y, x);

            s.push(node);
        }

        else {
            s.push(new Node(c));
        }
    }

    return s.top();
}

void preorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }

    if (isOperator(root->data)) {
        cout << "(";
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);

    if (isOperator(root->data)) {
        cout << ")";
    }
}