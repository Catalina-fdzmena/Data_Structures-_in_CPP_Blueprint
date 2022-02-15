#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "HashTable.h"

int main()
{

    vector<string> matriculas = {"A01197647","A00832188","A01284477","A01570751","A01720346","A00830052","A00831138","A01721540","A01197705","A01197782","A01283809","A00827269","A00830576","A01284179","A01383532","A00827461","A01731549","A01570748","A00829748","A00831719","A01351746","A01284469","A01025335","A01721299","A01197898","A01284329","A01721245","A01721208","A01197723","A01245418","A00829771","A01611427","A01384195","A01383057","A01655080"};
    HashTable hashTable(matriculas);
    hashTable.print();


    return 0;
}
