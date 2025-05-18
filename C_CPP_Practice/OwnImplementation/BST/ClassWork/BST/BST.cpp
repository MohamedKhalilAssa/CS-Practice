#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;
}

BST::node *BST::CreateLeaf(int key)
{
    node *n = new node;
    n->data = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void BST::AddNode(int key)
{
    AddNodePrivate(key, root);
}

void BST::AddNodePrivate(int key, node *ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if (key < ptr->data)
    {
        if (ptr->left == NULL)
        {
            ptr->left = CreateLeaf(key);
        }
        else
        {
            AddNodePrivate(key, ptr->left);
        }
    }
    else if (key > ptr->data)
    {
        if (ptr->right == NULL)
        {
            ptr->right = CreateLeaf(key);
        }
        else
        {
            AddNodePrivate(key, ptr->right);
        }
    }
    else
    {
        cout << "element exist deja !!!" << endl;
    }
}

void BST::PrintInorder()
{
    PrintInorderPrivate(root);
}

void BST::PrintInorderPrivate(node *ptr)
{
    if (root != NULL)
    {
        if (ptr->left != NULL)
        {
            PrintInorderPrivate(ptr->left);
        }
        cout << ptr->data << " :: "; // afficher elem gauche
        if (ptr->right != NULL)
        {
            PrintInorderPrivate(ptr->right);
        }
        // cout << ptr->data << endl; // afficher element droit
    }
    else
    {
        cout << "Arbre vide !!!" << endl;
    }
}

BST::node *BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node *BST::ReturnNodePrivate(int key, node *ptr)
{
    if (ptr != NULL)
    {
        if (ptr->data == key)
        {
            return ptr;
        }
        else
        {
            if (key < ptr->data)
            {
                return ReturnNodePrivate(key, ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

int BST::ReturnValRoot()
{
    if (root == NULL)
    {
        return -99999;
    }
    else
    {
        return root->data;
    }
}

void BST::PrintChildrens(int key)
{
    node *ptr = ReturnNode(key);
    if (ptr == NULL)
    {
        cout << " cle inexistante !!!" << endl;
    }
    else
    {
        if (ptr->left == NULL)
        {
            cout << "pas d 'enfant à gauche" << endl;
        }
        else
        {
            cout << " l enfant gauche est = " << ptr->left->data << endl;
        }
        if (ptr->right == NULL)
        {
            cout << "pas d 'enfant à droite" << endl;
        }
        else
        {
            cout << " l enfant droit est = " << ptr->right->data << endl;
        }
    }
}

int BST::FindSmallestItem()
{
    return FindSmallestItemPrivate(root);
}

int BST::FindSmallestItemPrivate(node *ptr)
{
    if (root == NULL)
    {
        cout << "Pas d arbre !!!" << endl;
        return -99;
    }
    else
    {
        if (ptr->left != NULL)
        {
            return FindSmallestItemPrivate(ptr->left);
        }
        else
        {
            return ptr->data;
        }
    }
}

void BST::DeleteNode(int key)
{
    root = BST::DeleteNodePrivate(key, root);
}
BST::node *BST::DeleteNodePrivate(int key, node *ptr)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    if (key < ptr->data)
        ptr->left = DeleteNodePrivate(key, ptr->left);
    else if (key > ptr->data)
        ptr->right = DeleteNodePrivate(key, ptr->right);
    else
    {
        if (ptr->right == NULL && ptr->left == NULL)
        {
            delete ptr;
            return NULL;
        }
        if (ptr->right == NULL)
        {
            node *temp = ptr->left;
            delete ptr;
            return temp;
        }
        else if (ptr->left == NULL)
        {
            node *temp = ptr->right;
            delete ptr;
            return temp;
        }
        else
        {
            node *temp = ReturnNode(FindSmallestItemPrivate(ptr->right));
            ptr->data = temp->data;
            ptr->right = DeleteNodePrivate(temp->data, ptr->right);
        }
    }
    return ptr;
}

void BST::InverseTree()
{
    return inverseTreePrivate(root);
}

void BST::inverseTreePrivate(node *ptr)
{
    if(ptr == NULL) return; 

    node *temp = ptr->left;
    ptr->left = ptr->right;
    ptr->right = temp;

    inverseTreePrivate(ptr->left);
    inverseTreePrivate(ptr->right);
}