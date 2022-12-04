#include "BST.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "       БИНАРНОЕ ДЕРЕВО ПОИСКА      " << endl << endl;

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
        cout << "Найдено";
    else
        cout << "Не найдено";
    cout << endl;

    cout << "Минимум : " << tree->FindMin(node);
    cout << endl;
    cout << "Максимум : " << tree->FindMax(node);
    cout << endl;

    cout << "Следующий элемент : " << tree->Successor(node, 7);
    cout << endl;

    cout << "Предыдущий элемент : " << tree->Predecessor(node, 12);
    cout << endl;

    cout << "Удаление элемента '15': " << endl;
    tree->Remove(node, 15);
    cout << "Удаление элемента '53': " << endl;
    tree->Remove(node, 53);

    cout << "Дерево: ";
    tree->PrintTreeInOrder(node);
    cout << endl;

    cout << "Прямой обход: ";
    tree->printPreorder(node, size(keys));
    cout << endl;

    cout << "Центрированный обход: ";
    tree->printInorder(node, size(keys));
    cout << endl;

    cout << "Обратный обход: ";
    tree->printPostorder(node, size(keys));
    cout << endl;

    cout << "Обход в ширину: ";
    tree->printWidth(node);
    cout << endl << endl;


    cout << "Визуализация бинарного дерева: \n\n";
    printTree(node, nullptr, false);
    cout << endl << endl;

    
    int choice = 0;
    string inform, postfix;
    cout << "Выберите форму записи выражения: "
        << endl << "1 - инфиксная"
        << endl << "2 - постфиксная"
        << endl << "3 - префиксная"
        << endl << "Ввод: ";
    cin >> choice;

    cout << "Введите выражение: ";
    cin >> inform;
        

    switch (choice) {
    case 1:
    {
        string postfix = infixToPostfix(inform);
        Node* root = construct(postfix);
        printTree4Expression(root, nullptr, false);
        cout << "\nПостфиксное выражение: ";
        postorder(root);

        cout << "\nПрефиксное выражение: ";
        preorder(root);
    }
    case 2:
    {
        Node* root = construct(inform);
        printTree4Expression(root, nullptr, false);

        cout << "\nИнфиксное выражение: ";
        inorder(root);

        cout << "\nПрефиксное выражение: ";
        preorder(root);
    }
    case 3:
    {
        string prefix = preToPost(inform);
        Node* root = construct(prefix);
        printTree4Expression(root, nullptr, false);

        cout << "\nПостфиксное выражение: ";
        postorder(root);

        cout << "\nИнфиксное выражение: ";
        inorder(root);
    }
    }

    return 0;
}