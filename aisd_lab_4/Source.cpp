#include "BST.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "       �������� ������ ������      " << endl << endl;

    BST* tree = new BST;
    BSTNode* node = new BSTNode;
    node = NULL;

    char keys[] = { 23, 12, 31, 3, 15, 7, 29, 88, 53 };

    for (int key : keys) {
        tree->Insert(node, key);
    }

    tree->PrintTreeInOrder(node);
    cout << endl;

    bool b = tree->Search(node, 31);
    if (b)
        cout << "�������";
    else
        cout << "�� �������";
    cout << endl;

    cout << "������� : " << tree->FindMin(node);
    cout << endl;
    cout << "�������� : " << tree->FindMax(node);
    cout << endl;

    cout << "��������� ������� : " << tree->Successor(node, 7);
    cout << endl;

    cout << "���������� ������� : " << tree->Predecessor(node, 12);
    cout << endl;

    cout << "�������� �������� '15': " << endl;
    tree->Remove(node, 15);
    cout << "�������� �������� '53': " << endl;
    tree->Remove(node, 53);

    cout << "������: ";
    tree->PrintTreeInOrder(node);
    cout << endl;

    cout << "������ �����: ";
    tree->printPreorder(node, size(keys));
    cout << endl;

    cout << "�������������� �����: ";
    tree->printInorder(node, size(keys));
    cout << endl;

    cout << "�������� �����: ";
    tree->printPostorder(node, size(keys));
    cout << endl;

    cout << "����� � ������: ";
    tree->printWidth(node);
    cout << endl << endl;


    cout << "������������ ��������� ������: \n\n";
    printTree(node, nullptr, false);
    cout << endl << endl;

    
    int choice = 0;
    string inform, postfix;
    cout << "�������� ����� ������ ���������: "
        << endl << "1 - ���������"
        << endl << "2 - �����������"
        << endl << "3 - ����������"
        << endl << "����: ";
    cin >> choice;

    cout << "������� ���������: ";
    cin >> inform;
        

    switch (choice) {
    case 1:
    {
        string postfix = infixToPostfix(inform);
        Node* root = construct(postfix);
        printTree4Expression(root, nullptr, false);
        cout << "\n����������� ���������: ";
        postorder(root);

        cout << "\n���������� ���������: ";
        preorder(root);
    }
    case 2:
    {
        Node* root = construct(inform);
        printTree4Expression(root, nullptr, false);

        cout << "\n��������� ���������: ";
        inorder(root);

        cout << "\n���������� ���������: ";
        preorder(root);
    }
    case 3:
    {
        string prefix = preToPost(inform);
        Node* root = construct(prefix);
        printTree4Expression(root, nullptr, false);

        cout << "\n����������� ���������: ";
        postorder(root);

        cout << "\n��������� ���������: ";
        inorder(root);
    }
    }

    return 0;
}