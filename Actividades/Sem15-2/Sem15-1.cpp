//Andrea Catalina Fernández Mena
//Actividad individual semana 15-02

#include <iostream>
#include <vector>
using namespace std;

#include "chain.h" //Función o método chain empleado desde una clase externa debido al tamaño de la función 

// Dígitos d2, d4 y d6
int selDigitos(int a) {
    int d7, d8, d7d8;
    // 12345678 d2 = 2
    d7 = a / 10 % 10;
    d8 = a / 1 % 10;
    d7d8 = d7 * 10 + d8;
    return d7d8;
}

int residual(int a) {
    return a % 101; 
}

int cuadratica(long long int a) {
    long long int c = a * a;
    int d10, d11, d10d11;
    // 12345678 d2 = 2
    d10 = c / 100000000 % 10;
    d11 = c / 10000000 % 10;
    d10d11 = d10 * 10 + d11;
    return d10d11;
}

int folding(int a) {
    int d1,d2,d3,d4,d5,d6,d7,d8;
    d1 = a / 10000000;
    d2 = a / 1000000 % 10;
    d3 = a / 100000 % 10;
    d4 = a / 10000 % 10;
    d5 = a / 1000 % 10;
    d6 = a / 100 % 10;
    d7 = a / 10 % 10;
    d8 = a / 1 % 10;
    return d8 + d4 + d5 + d5 + d6 + d7 + d8;
}

int main()
{

    vector<string> matriculas = {"A01197647", "A01197705","A00832188","A01284477","A01570751","A01720346","A00830052","A00831138","A01721540","A01197705","A01197782","A01283809","A00827269","A00830576","A01284179","A01383532","A00827461","A01731549","A01570748","A00829748","A00831719","A01351746","A01284469","A01025335","A01721299","A01197898","A01284329","A01721245","A01721208","A01197723","A01245418","A00829771","A01611427","A01384195","A01383057","A01655080"};
    vector<string> hashDigitos(100," ");
    vector<string> hashResidual(101," ");    
    vector<string> hashCuadratica(100," ");    
    vector<string> hashFolding(64," ");        
    
    for (auto mat : matriculas) {
    
        int a = stoi(mat.substr(1,8));
        // cout << "número: " << a << endl;
        // selección de dígitos
        // cout << "Selección de dígitos" << endl;
        // cout << selDigitos(a) << endl;
        hashDigitos[selDigitos(a)] = mat;
        // residual
        // cout << "Residual" << endl;
        // cout << residual(a) << endl;
        hashResidual[residual(a)] = mat;
        // Cuadrática
        // cout << "Cuadrática" << endl;
        // cout << cuadratica(a) << endl;
        hashCuadratica[cuadratica(a)] = mat;
        // Folding
        // cout << "Folding" << endl;
        // cout << folding(a) << endl;
        hashFolding[folding(a)] = hashFolding[folding(a)] + " " + mat;

    }

    int digitosCount = 0;
    for (auto mat : hashDigitos) {
        if (mat != " ") {
            digitosCount++;
        }
    }

    int residualCount = 0;
    for (auto mat : hashResidual) {
        if (mat != " ") {
            residualCount++;
        }
    }

    int cuadCount = 0;
    for (auto mat : hashCuadratica) {
        if (mat != " ") {
            cuadCount++;
        }
    }

    int foldingCount = 0;
    for (auto mat : hashFolding) {
        cout << mat << endl;
        if (mat != " ") {
            foldingCount++;
        }
    }

    string chain = 0;
    for (auto datalist : hashChain) {
        cout << mat << endl;
        if (mat != " ") {
            chainCount++;
        }
    }

    // Matrículas almacenadas 
    cout << "Digitos: " << digitosCount << endl;
    cout << "Residual: " << residualCount << endl;
    cout << "Cuadratica: " << cuadCount << endl;
    cout << "Folding: " << foldingCount << endl;
    cout << "Chain: " << chainCount << endl;
    

    return 0;
}

