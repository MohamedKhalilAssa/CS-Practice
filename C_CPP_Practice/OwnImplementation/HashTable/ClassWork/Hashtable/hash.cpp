#include <cstdlib>
#include <string>
#include <iostream>
#include "hash.h"

using namespace std;

int hash1::Hash(string name)
{
    int index;
    // notre fonction de hashage
    int hashage = 0;

    for (int i = 0; i < name.length(); i++)
    {
        hashage += (int)name[i];
    }

    // hashage = (int) name[0];
    //  cout << "le hash de " << name << " est = " << hashage << endl;
    index = hashage % tablesize;
    // cout << "l'index de " << name << " = " << index << endl;
    return index;
}

hash1::hash1()
{
    for (int i = 0; i < tablesize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->nom = "vide";
        HashTable[i]->tel = "vide";
        HashTable[i]->next = NULL;
    }
}

void hash1::AddItem(string name, string tel)
{
    int index = Hash(name);
    if (HashTable[index]->nom == "vide")
    {
        HashTable[index]->nom = name;
        HashTable[index]->tel = tel;
        HashTable[index]->next = NULL;
    }
    else
    {
        item *ptr = HashTable[index];
        item *n = new item;
        n->nom = name;
        n->tel = tel;
        n->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
    cout << "element ajoute " << name << endl;
}

void hash1::ShowHashtable()
{
    cout << "-----------------AFFICHAGE DE LA HASHTABLE-----------------" << endl;
    int nbItemPlace = 0;
    for (int i = 0; i < tablesize; i++)
    {
        cout << "ELEMENT EN INDICE: " << i << endl;

        nbItemPlace = CombienItemInPlace(i); // todo

        if (nbItemPlace == 1)
        {
            cout << HashTable[i]->nom << " :: " << HashTable[i]->tel << endl;
            continue;
        }
        item *ptr = HashTable[i];
        while (ptr != NULL)
        {
            cout << ptr->nom << " :: " << ptr->tel << endl;
            ptr = ptr->next;
        }
    }
}
void hash1::ShowNonVideHashtable()
{
    int nbItemPlace = 0;
    cout << "-----------------AFFICHAGE DE LA HASHTABLE-----------------" << endl;
    for (int i = 0; i < tablesize; i++)
    {
        cout << "--------------------------ELEMENT EN INDICE: " << i << endl;
        nbItemPlace = CombienItemInPlace(i); // todo

        if (nbItemPlace == 1)
        {
            if (HashTable[i]->nom != "vide")
            {
                cout << HashTable[i]->nom << " :: " << HashTable[i]->tel << endl;
            }
            continue;
        }
        else
        {
            item *ptr = HashTable[i];
            while (ptr != NULL)
            {
                if (HashTable[i]->nom != "vide")
                    cout << ptr->nom << " :: " << ptr->tel << endl;
                ptr = ptr->next;
            }
        }
    }
}

void hash1::SearchByName(string nom)
{
    int index;
    string phone;
    bool nomTrouvee = false;
    index = Hash(nom);
    item *ptr = HashTable[index];
    while (ptr != NULL && nomTrouvee == false)
    {
        if (ptr->nom == nom)
        {
            nomTrouvee = true;
            phone = ptr->tel;
        }
        ptr = ptr->next;
    }
    if (nomTrouvee == true)
    {
        cout << "element trouve: " << nom << " telephone: " << phone << endl;
    }
    else
    {
        cout << "element n existe pas !!!!" << endl;
    }
}

int hash1::CombienItemInPlace(int i)
{
    int counter = 0;

    item *ptr = HashTable[i];

    if (ptr->nom != "vide")
    {
        while (ptr != NULL)
        {
            counter++;
            ptr = ptr->next;
        }
    }
    cout << "Le nombre d'Item sur " << i << " est: " << counter << endl;
    return counter;
}

void hash1::SupprimerItem(string name)
{
    int index = Hash(name);

    item *ptr = HashTable[index];
    item *prec = NULL;
    if (ptr->next == NULL)
    {
        ptr->nom = "vide";
        ptr->tel = "vide";
        ptr->next = NULL;
    }
    else
    {
        // it looks for the node before name
        while (ptr->next != NULL && ptr->nom != name)
        {
            prec = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            exit(99);

        if (prec == NULL)
        {
            HashTable[index] = ptr->next;
        }
        else
        {
            prec->next = ptr->next;
        }
        delete ptr;
    }
}
