//Andrea Catalina Fernández Mena A01197705 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//BLUEPRINT CÓDIGO PRIMER DESARROLLO DEL MISMO 
/*
//Se crea una función para encontrar el caracter que no tenga un par o bien que no se encuntre repetido ddentro de una lista de pruebe
//Dentro de la función misma se relizan funciones de desplamiento de iz o derecha para así encontrar el caracter y comparar 
void caracterUnico(string character, char &binaryCharacter, int &index){
    int l = 0, r = character.size()-1, count = 0, medio, desfaceIzq, desfaceDerecho;

    //Para poder hacer la búsqueda binaria debe de existir por lo menos tres caracteres en caso de hacer menos se regresara como error

    if(character.size() == 3){
        if(character[0] == character[1]){ //Si los primeros dos caracteres son iguales entonces el único es el tercero
            binaryCharacter = character[2];
            //index = 1;
        }
        //Si no es así entonces se regresa el primer valor 
        binaryCharacter = character[0];
        //index = 1;
    }
    //Para asegurarnos de que la busque binaria se cumpla hay que revisar que nuestro string tenga mas de 3 caracteres y al menos un par
    else if(character.size() < 3){  //En caso que es string sea menor que tres 
        cout << "CRITICAL ERROR String must contain more than 2 characters as well as 1 pair in order to star with our binary search" << endl;
        //index = -1;

    }

    //Una vez realizando condiciones para evitar que se comentan errores al igresar datos a analizar 
    //Se comienza la búsqueda binaria 
    while(l<=r){  //l representa izquierda y r derecha 
        medio = (l+r)/2;  //Para conocer el punto medio y saber si se trata de algo impar o par
        desfaceIzq = (medio-l);
        desfaceDerecho = (r-medio);
        count++;

        //Confirma que si el número de caracteres es par entonces existe un desfase de binary search a la derecha 
        if(character[medio] == character[medio+1]){
            desfaceDerecho--;
        }         //Confirma que si el número de caracteres es impar entonces existe un desfase de binary search a la izquierda
        else if(character[medio] == character[medio-1]){
            desfaceIzq--;
        }

        //Checa si los datos restantes de ambos lados, son pares o nones
        if(desfaceIzq == desfaceDerecho){
            if((desfaceIzq%2 == 0) && (desfaceDerecho%2 == 0)){
                binaryCharacter = character[medio];
                index = count;
                break;
            }
        }
        //Checa hacia que lado debe moverse
        else if(desfaceIzq%2 != 0){
            //Cuando desface debe realizar si es par o impar
            //Si el lado derecho es el lado non, pero tiene un par de ese lado con el valor de enmedio
            //Salta 2 para evitar que se repita con el mismo
            if(character[medio-1] == character[medio]){
                r = medio-2;
            }
            else{
                //Si no, salta 1
                r = medio-1;
            }
        }   //En caso se desfasa al lado dónde no está el par sólo se desfasa uno ya que no es necesario evitar la repetición del caracter medio
        else if(desfaceDerecho%2 != 0){
            if(character[medio+1] == character[medio]){
                l = medio+2;
            }
            else{
                l = medio+1;
            }
        }
    }
}


//Se desarrolla la función para el caracter único y definición que como expresar cuando se ha encontrado el caracter único
//Complejidad: O(n)
int caracterUnicoElaboration(string character, char &caracterSecuencialSearchPrint){
    int limiteCaracterUnico = character.size() - 2, first = 0, second = 1, count = 0;  //Se manda a llamar las funciones y variabes para desplazamiento y busqueda 

    //Mientras queden mas de 3 datos por checar, recorre y checa los pares.
    while(second < limiteCaracterUnico){
        count++;
        if(character[second] != character[first]){
            if(character[second] == character[second+1]){
                caracterSecuencialSearchPrint = character[first];
                return count;
            }
            else if(character[first] == character[first-1]){
                caracterSecuencialSearchPrint = character[second];
                return count;
            }
        }

        first += 2;
        second += 2;
    }

    //En caso de que sea un caracter con tres valores 
    //Sólo se añade un valor al ciclo completado 
    count++;

    //Compara si el un caracter es igual al otro, entonces hay desfasamiento en uno de ellos 
    if(character[first] == character[second]){
        caracterSecuencialSearchPrint = character[second + 1];
    }
    else{  //Si no son iguales entonces se revisa con el primero a analizar
        caracterSecuencialSearchPrint = character[first];
    }
    //Y regresa valor al counter
    return count;
}
*/
//---

//Comprar los valores de cada linea de dos en dos 
//Se crea una función que guardará cada uno de los caracteres como valores en un vector para posteriormente en busqueda binaria realizar un ordenamiento
void busquedaSecuencial(vector<char> palabras){
    int cont = 1;
    for(int i=0; i != palabras.size(); i++){
        if(palabras[i+1] == palabras[i]){ //BUSQUEDA PAR A PAR
            i++;
            cont++;
        }
        else if(i+1 == palabras.size()) //ya es el ultimo valor, no suma mas
            cout << palabras[i]<< " " << cont-1 <<"    ";  //Se resta si se desfasa 
        else
            cout << palabras[i]<< " " << cont <<"    ";
    }
}
//Desarrollamos un vector para buscar 
//Impar va hacie el lado donde el valor es distinto
//Par va hacia donde el valor es igual 
void busquedaBinaria(vector<char> list){
    int left=0; 
    int cont=0;
    int right=list.size()-1;
    int mid=(right+left)/2;
    bool valid=true;
    while(left<=right){
        if((list[mid]!=list[mid-1]) && (list[mid]!=list[mid+1])){
            cout<<list[mid]<<" "<<cont<<endl;
            break;
        } else if (mid%2==0){
            if (list[mid]==list[mid+1]){
                left = mid+1;
            } else if (list[mid]==list[mid-1]){
                right = mid-1;
            } else {
                cout<<list[mid]<<" "<<cont<<endl;
                break;
            }
        }else{
            if (list[mid]==list[mid+1]){
                right = mid-1;
            } else if (list[mid]==list[mid-1]){
                left = mid+1;
            } else {
                cout<<list[mid]<<" "<<cont<<endl;
                break;
            }
        }
        mid = (right+left)/2;
        cont++;
    }
    if(valid==false)
        cout << "CRITICAL ERROR " << endl;
}
//---


//En el main realizamos la respectiva únificación de las secciones de nuestra función para mostrar 
int main(){
    
    //Pedir archivo de prueba
    ifstream archivo;
    string nombre_archivo;  //Se crea string para pedir nombre del archivo 
    cout << "Call out the document you would like to read (name.in): ";
    cin >> nombre_archivo;
    archivo.open(nombre_archivo);

    //Crear vector de renglones 
    vector<string> renglones;
    int n; //Numero de renglones
    archivo >> n;
    string renglon;
    for(int i=0; i < n ; i++){
        archivo >> renglon;
        renglones.push_back(renglon);
    }
    archivo.close();
    //Una vez realizada lectura se elabora búsqueda binaria 
    
    for(int i=0; i < n ; i++){
        //Desarrollar vector para organizar cada uno de los caracteres y ordenarlos
        vector<char> caracteres(renglones[i].begin(), renglones[i].end());
        busquedaSecuencial(caracteres);
        sort(caracteres.begin(), caracteres.end());
        busquedaBinaria(caracteres);
    }
    return 0;
}
