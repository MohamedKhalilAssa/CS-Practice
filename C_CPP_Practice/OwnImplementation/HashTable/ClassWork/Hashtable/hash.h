#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

class hash1{
    private:
        static const int tablesize=10;
        struct item{
            string nom;
            string tel;
            item* next;
        };
        item* HashTable[tablesize];
    public:
        hash1();
        //~hash1();
        int Hash(string name);
        void AddItem(string name, string tel);
        void ShowHashtable();
        void ShowNonVideHashtable();
        void SearchByName(string nom); // todo corriger erreur
        int CombienItemInPlace(int i);
        void SupprimerItem(string nom); // to do
};

#endif // HASH_H_INCLUDED
