//Actividad integradora 3 
//Andrea Catalina Fernández Mena A01197705

#ifndef repeatedIP_h
#define repeatedIP_h

#include <iostream>
using namespace std; 


class repeatedIP{
    private:
        string IP;
        int numRepeticion;
    public:   
        repeatedIP(); //COnstructor por default 
        repeatedIP(string reflectedIP,int repeticion); //Constructor para hacer los datos de tipo privaod publicos
        //Se crea la sobrecarga de operadores 
        bool operator<(repeatedIP& sample);
        bool operator>(repeatedIP& sample);
        bool operator<=(repeatedIP& sample);
        bool operator>=(repeatedIP& sample);
        bool operator==(repeatedIP& sample);
        friend ostream& operator<<(ostream& os, const repeatedIP& dataRepeated);
};

//Se crea un constructor por default 
repeatedIP::repeatedIP(){
    IP = "";
    numRepeticion = 0; 
}

//Se genera un constructor para hacer un auxiliar público de los datos privados 
//Código podría optimizarse con el desarrollo de atributos de tipo protegidos

repeatedIP::repeatedIP(string reflectedIP,int repeticion){
    IP = reflectedIP;
    numRepeticion = repeticion;
}

//Se realiza la respectiva sobrecarga de operadores dependiendo y comparando si es mayor que menor que o igual

bool repeatedIP::operator<(repeatedIP& sample){
    return numRepeticion < sample.numRepeticion;
}
bool repeatedIP::operator>(repeatedIP& sample){
    return numRepeticion > sample.numRepeticion;
}
bool repeatedIP::operator<=(repeatedIP& sample){
    return numRepeticion <= sample.numRepeticion;
}
bool repeatedIP::operator>=(repeatedIP& sample){
    return numRepeticion >= sample.numRepeticion;
}
bool repeatedIP::operator==(repeatedIP& sample){
    return numRepeticion == sample.numRepeticion;
}

//Se imprime la cantidad de veces que un determinado IP se desarrolla 
ostream& operator<<(ostream& os, const repeatedIP& dataRepeated){
    os << dataRepeated.IP << "se repite" << dataRepeated.numRepeticion << "veces";  //String comillas doble, un caracter 1 comilla simple
    return os;  //Terminar "print"
}

#endif
