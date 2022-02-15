#ifndef HashTable_h
#define HashTable_h

// Hast Table para matrículas
class HashTable
{
private:
    vector<string> table;
    vector<char> status; // v: Vacía, b: Borrada, o: Ocupada
    int size;
    int occupied;
    int hashing(string data);
public:
    HashTable();
    HashTable(vector<string> list);
    int find(string data);
    void add(string data);
    bool remove(string data);
    void print();
};

HashTable::HashTable()
{
    table = vector<string>(110, "");
    status = vector<char>(110,'v');
    size = 110;
    occupied = 0;
}

HashTable::HashTable(vector<string> list)
{
    table = vector<string>(110, "");
    status = vector<char>(110,'v');
    size = 110;
    occupied = 0;
    for (auto data : list)
    {
        add(data);
    }
}

// Función hashing con método cuadrática
int HashTable::hashing(string data)
{
    long long int numMat = stoi(data.substr(1, 8));
    long long int quadMat = numMat * numMat;
    int d10, d11, d10d11;
    // 12345678 d2 = 2
    d10 = quadMat / 100000000 % 10;
    d11 = quadMat / 10000000 % 10;
    d10d11 = d10 * 10 + d11;
    return d10d11;
}

// Busca un elemento en la Hash Table
int HashTable::find(string data)
{
    // Obtener el índice que regresa la función hashing
    int index = hashing(data);
    // Buscar el elemento en la tabla hasta encontrarlo o encontrar una casilla vacía
    bool found = false;
    int auxIndex = index;
    int collisions = 1;
    while (status[auxIndex] != 'v' && !found && collisions <= size)
    {
        // Validamos si en la posición auxIndex se encuentra el dato buscado
        if (status[auxIndex] == 'o' && table[auxIndex] == data)
        {
            found = true;
        }
        else
        {
            // Actualizamos el índice a la siguiente posición
            auxIndex = (index + collisions * collisions) % size;
            collisions++;
        }
    }
    if (found)
    {
        return auxIndex;
    }
    else
    {
        return -1;
    }
}

void HashTable::add(string data)
{
    // Obtener el índice que regresa la función hashing
    cout << occupied << endl;
    if (occupied != size)
    {
        int index = hashing(data);
        int auxIndex = index;
        int collisions = 1;
        // Buscamoshasta encontrar una casilla vacía o borrada
        while (status[auxIndex] == 'o' && collisions <= size)
        {
            // Actualizamos el índice a la siguiente posición
            auxIndex = (index + collisions * collisions) % size;
            collisions++;
        }
        if (collisions <= size)
        {
            table[auxIndex] = data;
            status[auxIndex] = 'o';
            occupied++;
        }
        else
        {
            throw out_of_range("No se pudo insertar el dato: ");
        }
    } else {
        throw out_of_range("No se pudo insertar el dato");
    }
}

void HashTable::print() {
    for (auto data : table) {
        cout << data << endl;
    }
}

#endif