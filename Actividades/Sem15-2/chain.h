//Andrea Catalina Fernández Mena
//Actividad individual semana 15-02

#include <list>

class chain {
private:
// vector contenedor para hacer una cantidad expansible de lista dependiendo del núemro de datos
    list<string> *docker; 
    int size;
    int hashMethod(string mat);
public:
    chain(); //COnstrusctor por default
    chain(vector<string> hashChain);
    void add(string b);
    void print();
};
//COnstrusctor por default
chain::chain(){
    this->size = 10;
}
//Cosntructor con parámetros
chain::chain(vector<string> hashChain){
    this->size = hashChain.size();
    //Un contenedor con base al tamaño de la hash table
    docker = new list<string>[size]; 
    //For para que el inicio de la lista de se puedan añadir valores como lista 
    for (auto mat : hashChain){
        add(mat);
    }
}

//Método individual para hashing
int chain::hashMethod(string b){
    return stoi(b.substr(1,8)) % size;
}

void chain::add(string b){
    int index = hashMethod(b);
    //Añadir posiciones al contenedor 
    docker[index].push_front(b); 
}
//Imprimir hasing hecho con método chain
void chain::print(){
    for (int i = 0; i < size; i++){
        cout << i << ": ";
        for (auto mat : docker[i]) {
            cout << mat << " ";
        }
        cout << endl;
    }
}