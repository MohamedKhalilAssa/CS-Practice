#include <iostream>
#include <cstdlib>
#include "BST.cpp"

using namespace std;

int main()
{
    int keys[16] = {52, 77, 22, 7, 33, 65, 16, 53, 15, 101, 84, 3, 4, 71, 88, 81};
    BST ObjTree;
    for (int i = 0; i < 16; i++)
    {
        ObjTree.AddNode(keys[i]);
    }

    ObjTree.PrintInorder();
    cout << "la racine est = " << ObjTree.ReturnValRoot() << endl;

    ObjTree.DeleteNode(52);
    ObjTree.PrintInorder();
    cout << "la racine est = " << ObjTree.ReturnValRoot() << endl;

    ObjTree.InverseTree();
    ObjTree.PrintInorder();

    return 0;
}