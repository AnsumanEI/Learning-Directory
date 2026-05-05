#include <iostream>
#include "bst.h"
using namespace std;
int main()
{
    BST tree1;
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(8);
    tree1.insert(2);
    tree1.insert(4);
    tree1.insert(6);
    tree1.insert(9);

    vector<int> inorder = tree1.inorder();
    vector<int> preorder = tree1.preorder();
    vector<int> postorder = tree1.postorder();
    cout << "Traversal print: \n";
    cout << "Inorder\n";
    for (auto &p : inorder)
    {
        cout << p << " ";
    }
    cout << "\nPreorder\n";
    for (auto &p : preorder)
    {
        cout << p << " ";
    }
    cout << "\nPostorder\n";
    for (auto &p : postorder)
    {
        cout << p << " ";
    }
    cout << "\nSearch : ";
    cout << tree1.search(4) << endl;
    cout << tree1.search(7) << endl;

    tree1.del(2);
    inorder = tree1.inorder();
    cout << "\nInorder Delete 2\n";
    for (auto &p : inorder)
    {
        cout << p << " ";
    }

    tree1.del(3);
    inorder = tree1.inorder();
    cout << "\nInorder Delete 3\n";
    for (auto &p : inorder)
    {
        cout << p << " ";
    }

    tree1.del(5);
    inorder = tree1.inorder();
    cout << "\nInorder Delete 5\n";
    for (auto &p : inorder)
    {
        cout << p << " ";
    }

    cout << "\n";
    cout << "Height :" << tree1.height() << endl;
    Node *Lca = tree1.lca(3, 9);
    cout << "Lca -> " << Lca->Value;
    return 0;
}