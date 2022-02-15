//Andrea Catalina Fernández Mena A01197705
//Actividad Integradora 5

#pragma once
#include <iostream>
using namespace std;


template<class T>
struct Edge {
    T fuente;
    T clasificacion;
    Edge(T fuente, T clasificacion);
    //friend ostream& operator << (ostream& out, const Edge<T>& aux);
    string retirarPuerto(string IP);
    string newClave(string IP);
};


template<class T>
Edge<T>::Edge(T fuente, T clasificacion) {
    this->fuente = retirarPuerto(fuente);
    this->clasificacion = retirarPuerto(clasificacion);
}

/*template <class T>
ostream& operator << (ostream& out, const Edge<T>& aux){
    out << aux.fuente << " - " << aux.clasificacion;
    return out;
}*/

//Implementamos método previo de act integradora 3 para remover el IP 
//Desarrollar un for para omitir el puerto
//Lectura se detiene al detectar dos puntos 
string Edge<T>::retirarPuerto(){
    string timeIP;
    for(int i = 0; i< IP.size(); i++){
        if(IP[i] == ':'){
            break; //Se detiene la lectura y se almacena toda la parte del IP 
        }else{
            timeIP = timeIP + IP[i];  //Valor se acumula
            }
        }
return timeIP;         
}

//OPCIONAL DE AÑADIR PARA ENCONTRAR MÁS FÁCIL LOS ":"
//Se crea nueva variable para mostrar la nueva clave creada a partir de la omisión de ":"

/*
string Edge<T>::newClave(){
//     string timeIP; //Guardar IP a manera de string para 
//     int integerIP;  //Acumudalor de cada IP cada que se vuelva un valor de int 
//     for(int i = 0; i< IP.size() ; i++ ){
//         if(IP[1] == '.'){   //Si solo es el punto en el ip entonces se ignora
//         }else if(IP[i] == ':'){
//             break; //Se detiene la lectura
//         }else{
//             integerIP = integerIP + IP[i];  //De no reomperte, este valor se guarda y continua 
//         }    //Checar si cambiar valor 1 de index por otro 
//     }
// integerIP = stoi(timeIP);  //El valor entero que se genera 

return IP.substr(0,IP.find(":"));
}
*/  
