//Andrea Catalina Fernández Mena A01197705
//Actividad Integradora 4

#pragma once
#include <iostream>
using namespace std;

/* 
struct bitacoraInformacion {
    string mes; //El valor de mes como string
    string horaTiempo;  //Valor de la hora como string 
    string IP;
    string newOrderIP;
    string newIPWithoutPort;  //. 
    string notificacionAccess;
    string diaNumString;  //Dia dando la posibilidad de también cambair a string como prevensión de que se marque un error
    int day;  //El valor de día como número entero
    int hour;   //El valor de hora como número entero
    int minute;  //...
    int second;
    string key;   //Valor que se desarrolle al convertir valores de string
    int mesNum;
    //Funcciones que será aplicadas para conversion de valores int y string a un sólo string que ayudará a jerarquizar los valores de los datos
    
    bitacoraInformacion(); //Función constructor por default
    bitacoraInformacion(string mes, string diaNumString, string horaTiempo, string IP, string notificacionAccess);
    void convertionMonths(string mes); //Convertir meses de string a numero
    void convertionTime(string hora);  //Convertir tiempo de igual forma string a num
    void convertionDays(string dia);  
    //int keyOrganizacionCronologica();
    void printBit();
    string retirarPuerto();
    string newClave();


    //Operadores booleanos para definir si el valor será mayor menor o igual que a los datos actuales 
    bool operator<(bitacoraInformacion sample);
    bool operator>(bitacoraInformacion sample);
    bool operator<=(bitacoraInformacion sample);
    bool operator>=(bitacoraInformacion sample);
    bool operator==(bitacoraInformacion sample);
    friend ostream& operator << (ostream& salida, const bitacoraInformacion& dataRepeated);
};

//Desarrollamo un constructor por default del mismo struct en caso de que no haya algún tipo de dato ingresado 

//Constructores
bitacoraInformacion::bitacoraInformacion() {
    mes = "Jan";
    diaNumString = "01";
    horaTiempo = "00:00:00";
    IP = " ";
    notificacionAccess = "";
    newOrderIP = "";
    newIPWithoutPort = "";

    this->convertionMonths(mes);
    this->convertionDays(diaNumString);
    this->convertionTime(horaTiempo);

    this->key = "";
}



bitacoraInformacion::bitacoraInformacion(string mes, string diaNumString, string horaTiempo, string IP, string notificacionAccess) {
    this->mes = mes;
    this->diaNumString = diaNumString;
    this->horaTiempo = horaTiempo;
    this->IP = IP;
    this->notificacionAccess = notificacionAccess;
    
    this->convertionMonths(mes);
    this->convertionDays(diaNumString);
    this->convertionTime(horaTiempo);

    this->key = IP.substr(0,IP.find(":"));   //Como los datos de organización de IP no señalan al mismo apuntados entonces
    //Es posible generar una simple igualdad en donde se mande a llamar a las funciones
    //--------------------------------------------------------------------
    newOrderIP = IP.substr(0,IP.find(":")); 
    newIPWithoutPort = IP.substr(0,IP.find(":"));    
} */

/* 
//Desarrollar un for para omitir el puerto

string bitacoraInformacion::retirarPuerto(){
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

//Cuando se llegue al puesto detener el código y detener la lectura del mismo después de los dos puntos

string bitacoraInformacion::newClave(){
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

struct IP{
    string ip;
    int count;
    IP();
    IP(string ip, int count);
    bool operator< (IP &ip) { return count < ip.count; }
    bool operator<= (IP &ip) { return count <= ip.count; }
    bool operator> (IP &ip) { return count > ip.count; }
    bool operator>= (IP &ip) { return count >= ip.count; }
    bool operator== (IP &ip) { return count == ip.count; }
    friend ostream& operator<< (ostream& out, const IP &ip);
};

IP::IP(string ip,int count){
    this->count = count;
    this->ip = ip;
}

ostream& operator<< (ostream& out, const IP &ip){
    out << ip.ip << " -> " << ip.count;
    return out;
}