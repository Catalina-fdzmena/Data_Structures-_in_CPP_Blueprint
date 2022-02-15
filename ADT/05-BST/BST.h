#ifndef BST_h
#define BST_h

#include "NodoD.h"
#include "Queue.h"
#include "Stack.h"

template<class T>
class BST {
private:
    Nodo<T>* root;
    void printTree(Nodo<T>* aux, int level);
    int numChildren(Nodo<T>* aux);
    void preOrder(Nodo<T>* aux);
    void inOrder(Nodo<T>* aux);
    void postOrder(Nodo<T>* aux);
    void levelByLevel();
    int heightR(Nodo<T>* aux);
public:
    BST();
    void add(T data);
    bool find(T data);
    void remove(T data);
    void visit(int order);
    int height();
    void ancestors(T data);
    int whatLevelAmI(T data);
    void print();
    bool isEmpty();
};

template<class T>
BST<T>::BST() {
    root = nullptr;
}

template<class T>
void BST<T>::add(T data) {
    //Validamos si el arbol está vacío
    if (isEmpty()) {
        // apuntamos root a un nodo nuevo
        root = new Nodo<T>(data);
    } else {
        // creamos un apuntador auxliar que apunte a root
        Nodo<T>* aux = root;
        // Recorrer el arbol hasta encontrar donde insertar el nodo nuevo
        while (aux != nullptr) {
            // comparamos el valor del dato nuevo con el valor del nodo auxiliar
            if (data < aux->data) {
                // Verificamos si el apuntador left es igual a nulo
                if (aux->left == nullptr) {
                    // agregamos el nodo nuevo en al apuntador left de aux
                    aux->left = new Nodo<T>(data);
                    // nos salimos del ciclo
                    aux = nullptr;
                } else {
                    // asignamos a aux a aux->left
                    aux = aux->left;
                }
            } else {
                // Verificamos si el apuntador right es igual a nulo
                if (aux->right == nullptr) {
                    // agregamos el nodo nuevo en al apuntador left de aux
                    aux->right = new Nodo<T>(data);
                    // nos salimos del ciclo
                    aux = nullptr;
                } else {
                    // asignamos a aux a aux->right
                    aux = aux->right;
                }
            }
        }
    }
}

// find
template<class T>
bool BST<T>::find(T data) {
    // Creamos un nodo auxiliara que apunte a root
    Nodo<T>* aux = root;
    // Recorremos el arbol hasta encontrar el dato
    while (aux != nullptr) {
        // Validamos si el dato a buscar es igual al dato de auxiliar
        if (data == aux->data) {
            // regresamos true para decir que si lo encontramos
            return true;
        } else {
            // if (data < aux->data) {
            //     // Recorremos el auxiliar a la izquierda
            //     aux = aux->left;
            // } else {
            //     // Recorremos el auxiliar a la derecho
            //     aux = aux->right;
            // }
            // Vamos a hacerlos de otra forma más sencilla
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    // No encontré el dato en el BST
    return false;
}

// numero de hijos
template<class T>
int BST<T>::numChildren(Nodo<T>* aux) {
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0; // 0 hijos
    } else {
        if (aux->left != nullptr && aux->right != nullptr) {
            return 2; // 2 hijos
        } else {
            return 1; // 1 hijo
        }
    }
}

// remove
template<class T>
void BST<T>::remove(T data) {
    // Creamos apuntador auxiliar que apunta a root
    Nodo<T>* aux = root;
    // Validamos si el dato que vamos a borrar esta en root
    if (data == aux->data) {
        // Revisamos cuantos hijos tiene
        switch (numChildren(aux)) {
        case 0:
            // root apuntamos a nulo
            root = nullptr;
            // borramos aux
            delete aux;
            break;
        case 1: 
            // apuntamos root al hijo correspondiente
            aux->left != nullptr ? root = aux->left : root = aux->right;
            // borramos aux
            delete aux;
            break;
        case 2:
         
            // Creamos un apuntador auxiliar 2 que apunta al hijo del lado izquierdo de aux
            Nodo<T>* aux2 = aux->left;
            // Validamos si el lado derecho del hijo del lado izquierdo apunta a nulo
            if (aux2->right == nullptr) {
                // aux2 es el hijo más grandel del laso izquierdo
                // Cambiamos el valor de aux al valor de aux 2
                aux->data = aux2->data;
                // Apuntamos aux->left a aux2->left sin importar que no tenga hijos
                aux->left = aux2->left;
                // Borramos aux2
                delete aux2;
            } else {
                // Buscamos el hijo mayor del lado izquierdo
                // creamos un apuntador auxiliar apuntando a aux2;
                Nodo<T>* father = aux2;
                // recorremos aux2 
                aux2 = aux2->right;
                while (aux2->right != nullptr) {
                    // Recorremos los apuntadores
                    father = aux2;
                    aux2 = aux2->right;
                }
                // Cambiamos el valor de aux por el valor de aux2
                aux->data = aux2->data; 
                // Apntamos el apuntador del lado derecho del papá al lado izquierdo de aux2
                father->right = aux2->left;
                // borramos aux2
                delete aux2;
            }
            break;
        }
    } else { 
        // Vamos a buscar el nodo a borrar
        // Creamos un apuntador auxiliar que apunte al papa de aux
        Nodo<T>* father = aux;
        // Recorremos aux
        data < aux->data ? aux = aux->left : aux = aux->right;
        // Recorremos el arbol para buscar el data
        while (aux != nullptr) {
            // Validamos si el dato a borrar es aux->data
            if (data == aux->data) {
                // Borramos aux
                switch (numChildren(aux)) {
                case 0:
                    // apuntamos el lado correspondiente de aux a nulo
                    data < father->data ? father->left = nullptr : father->right = nullptr;
                    // Borramos aux
                    delete aux;
                    break;
                case 1:
                    // apuntamos el lado correspondiente de aux al hijo
                    if (aux->left != nullptr) {
                        data < father->data ? father->left = aux->left : father->right = aux->left;
                    } else {
                        data < father->data ? father->left = aux->right : father->right = aux->right;
                    }
                    // borramos aux
                    delete aux;
                    break;
                case 2:
                    // Creamos un apuntador auxiliar 2 que apunta al hijo del lado izquierdo de aux
                    Nodo<T>* aux2 = aux->left;
                    // Validamos si el lado derecho del hijo del lado izquierdo apunta a nulo
                    if (aux2->right == nullptr) {
                        // aux2 es el hijo más grandel del laso izquierdo
                        // Cambiamos el valor de aux al valor de aux 2
                        aux->data = aux2->data;
                        // Apuntamos aux->left a aux2->left sin importar que no tenga hijos
                        aux->left = aux2->left;
                        // Borramos aux2
                        delete aux2;
                    } else {
                        // Buscamos el hijo mayor del lado izquierdo
                        // creamos un apuntador auxiliar apuntando a aux2;
                        Nodo<T>* father = aux2;
                        // recorremos aux2 
                        aux2 = aux2->right;
                        while (aux2->right != nullptr) {
                            // Recorremos los apuntadores
                            father = aux2;
                            aux2 = aux2->right;
                        }
                        // Cambiamos el valor de aux por el valor de aux2
                        aux->data = aux2->data; 
                        // Apntamos el apuntador del lado derecho del papá al lado izquierdo de aux2
                        father->right = aux2->left;
                        // borramos aux2
                        delete aux2;
                    }
                    break;
                }
                aux = nullptr;
            } else {
                // Recorremos los apuntadores
                father = aux;
                data < aux->data ? aux = aux->left : aux = aux->right;
            }
        }
    }
}

template<class T>
void BST<T>::preOrder(Nodo<T>* aux) {
    if (aux != nullptr) {
        cout << aux->data << " ";
        preOrder(aux->left);
        preOrder(aux->right);
    }
}

template<class T>
void BST<T>::inOrder(Nodo<T>* aux) {
    if (aux != nullptr) {
        inOrder(aux->left);
        cout << aux->data << " ";
        inOrder(aux->right);
    }
}

template<class T>
void BST<T>::postOrder(Nodo<T>* aux) {
    if (aux != nullptr) {
        postOrder(aux->left);
        postOrder(aux->right);
        cout << aux->data << " ";
    }
}

template<class T>
void BST<T>::levelByLevel() {
    if (!isEmpty()) {
        Queue<Nodo<T>*> queue;
        // metemos el nodo raíz a la fila
        queue.push(root);
        // recorremos la fila hasta que se vacíe
        while (!queue.isEmpty()) {
            // Sacamos el primer elemento de la fila
            Nodo<T>* aux = queue.pop();
            // imprimos el elemento
            cout << aux->data << " ";
            if (aux->left != nullptr) {
                queue.push(aux->left);
            }
            if (aux->right != nullptr) {
                queue.push(aux->right);
            }
        }
    }
}

template<class T>
void BST<T>::visit(int order) {
    switch (order) {
    case 1:
        // PreOreder
        cout << "PreOrder" << endl;
        preOrder(root);
        cout << endl;
        break;
    case 2:
        // InOreder
        cout << "InOrder" << endl;
        inOrder(root);
        cout << endl;
        break;
    case 3:
        // PostOreder
        cout << "PostOrder" << endl;
        postOrder(root);
        cout << endl;
        break;
    case 4:
        // Level by Level
        cout << "Level by Level" << endl;
        levelByLevel();
        cout << endl;
        break;
    
    default:
        break;
    }
}

template<class T>
int BST<T>::heightR(Nodo<T>* aux) {
    if (aux != nullptr) {
        int left = heightR(aux->left);
        int right = heightR(aux->right);
        return left >= right ? left + 1 : right + 1;
    } else {
        return 0;
    }
}

template<class T>
int BST<T>::height() {
    if (!isEmpty()) {
        return heightR(root);
    } else {
        return 0;
    }
}

template<class T>
void BST<T>::ancestors(T data) {
    // Creamos un nodo auxiliar que apunte a root
    Nodo<T>* aux = root;
    // creamos un stack de tipo de dato T
    Stack<T> stack;
    // Creamos una variable boolena que indique si encontramos el dato
    bool found = false;
    // Recorremos el arbol hasta encontrar el dato
    while (aux != nullptr && !found) {
        // Validamos si el dato a buscar es igual al dato de auxiliar
        if (data == aux->data) {
            // cambiamos el valor de found para decir que si lo encontramos
            found = true;
        } else {
            // Agregamos el dato al satck
            stack.push(aux->data);
            // Recorremos aux al lado correspondiente
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    if (found) {
        // recorremos cada uno de los valores del stack
        while (!stack.isEmpty()) {
            cout << stack.pop() << " ";
        }
        cout << endl;
    }
}


template<class T>
int BST<T>::whatLevelAmI(T data) {
    // Creamos un nodo auxiliar que apunte a root
    Nodo<T>* aux = root;
    // creamos un contador de niveles
    int levels = 0;
    // Creamos una variable boolena que indique si encontramos el dato
    bool found = false;
    // Recorremos el arbol hasta encontrar el dato
    while (aux != nullptr && !found) {
        // Validamos si el dato a buscar es igual al dato de auxiliar
        if (data == aux->data) {
            // cambiamos el valor de found para decir que si lo encontramos
            found = true;
        } else {
            // Incrementamos el nivel
            levels++;
            // Recorremos aux al lado correspondiente
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    if (found) {
        return levels + 1;
    } else {
        return -1;
    }
}

template<class T>
void BST<T>::printTree(Nodo<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
}

template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

#endif