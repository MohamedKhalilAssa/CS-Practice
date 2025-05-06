#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main()
{
    // cout << "Hello world! INPT" << endl;
    hash1 hashObj;
    int index;
    index = hashObj.Hash("Noureddine");
    cout << "le code du premier char = " << index;
    hashObj.AddItem("Noureddine", "06103333");
    hashObj.AddItem("Khadija", "06109999");
    hashObj.AddItem("Mehdi", "06103333");
    hashObj.AddItem("Hanane", "06109999");
    hashObj.AddItem("Taha", "06103333");
    hashObj.AddItem("Haanne", "06109999");
    hashObj.AddItem("Henana", "06103333");
    hashObj.AddItem("Aya", "06109999");

    // Afficher le contenu du Hashtable
    hashObj.ShowNonVideHashtable();
    hashObj.SupprimerItem("Noureddine");
    hashObj.ShowNonVideHashtable();

    return 0;
}
