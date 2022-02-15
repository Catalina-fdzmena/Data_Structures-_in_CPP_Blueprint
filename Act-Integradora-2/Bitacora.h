//Andrea Catalina Fernández Mena A01197705
//Resultado final 
#pragma once


//Definir la conversión de meses así como valores de la bitácora para así crear el key que nos ayudará a la organización de los datos despues

//Se define como un struct ya que todos los datos en cuestión se tratan como información pública 
struct bitacoraInformacion {
    string mes; //El valor de mes como string
    string horaTiempo;  //Valor de la hora como string 
    string IP;
    string notificacionAccess;
    string diaNumString;  //Dia dando la posibilidad de también cambair a string como prevensión de que se marque un error
    int day;  //El valor de día como número entero
    int hour;   //El valor de hora como número entero
    int minute;  //...
    int second;
    int key;   //Valor que se desarrolle al convertir valores de string
    int mesNum;
    //Funcciones que será aplicadas para conversion de valores int y string a un sólo string que ayudará a jerarquizar los valores de los datos
    
    bitacoraInformacion(); //Función constructor por default
    bitacoraInformacion(string mes, string diaNumString, string horaTiempo, string IP, string notificacionAccess);
    void convertionMonths(string mes); //Convertir meses de string a numero
    void convertionTime(string hora);  //Convertir tiempo de igual forma string a num
    void convertionDays(string dia);  
    int keyOrganizacionCronologica();
    void printBit();


    //Operadores booleanos para definir si el valor será mayor menor o igual que a los datos actuales 
    bool operator<(bitacoraInformacion Bitacora);
    bool operator>(bitacoraInformacion Bitacora);
    bool operator<=(bitacoraInformacion Bitacora);
    bool operator>=(bitacoraInformacion Bitacora);
    bool operator==(bitacoraInformacion Bitacora);
    friend ostream& operator << (ostream& salida, const bitacoraInformacion& b);
};

//Desarrollamo un constructor por default del mismo struct en caso de que no haya algún tipo de dato ingresado 

//Constructores
bitacoraInformacion::bitacoraInformacion() {
    mes = "Jan";
    diaNumString = "01";
    horaTiempo = "00:00:00";
    IP = " ";
    notificacionAccess = "";

    this->convertionMonths(mes);
    this->convertionDays(diaNumString);
    this->convertionTime(horaTiempo);

    this->key = this->keyOrganizacionCronologica();
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
    this->key = this->keyOrganizacionCronologica();
}

//Conversiones
void bitacoraInformacion::convertionMonths(string mes){
    int mesNumberMeaning=0;  //Desarrollamos una variable entrera para modificar el significado de cada mes por un valor numérico
    if (mes == "Jan"){
        mesNumberMeaning = 1;
    }
    else if (mes == "Feb"){
        mesNumberMeaning = 2;
    }
    else if (mes == "Mar"){
        mesNumberMeaning = 3;
    }
    else if (mes == "Apr"){
        mesNumberMeaning = 4;
    }
    else if (mes == "May"){
        mesNumberMeaning = 5;
    }
    else if (mes == "Jun"){
        mesNumberMeaning = 6;
    }
    else if (mes == "Jul"){
        mesNumberMeaning = 7;
    }
    else if (mes == "Aug"){
        mesNumberMeaning = 8;
    }
    else if (mes == "Sep"){
        mesNumberMeaning = 9;
    }
    else if (mes == "Oct"){
        mesNumberMeaning = 10;
    }
    else if (mes == "Nov"){
        mesNumberMeaning = 11;
    }
    else if (mes == "Dec"){
        mesNumberMeaning = 12;
    }
    mesNum=mesNumberMeaning;  //Los valores por los que se hace la igualación de guardan en la variable mesNum que convierte los meses a valores numéricos
}

void bitacoraInformacion::convertionTime(string hora){
/*    
    //Se realiza una función parecida para lograr la conversión del tiempo 
    string temp="00";

    //Hora
    temp = horaTiempo[0];
    temp += horaTiempo[1];
    hour = stoi(temp);

    //Minuto
    temp = "00";
    temp = horaTiempo[3];
    temp += horaTiempo[4];
    minute = stoi(temp);

    //Segundo
    temp = "00";
    temp = horaTiempo[6];
    temp += horaTiempo[7];
    second = stoi(temp);*/
 /*   int h, m, s;
    string h1, h2, m1, m2, s1, s2, hh, mm, ss;
    h1 = hora[0];
    h2 = hora[1];
    m1 = hora[3];
    m2 = hora[4];
    s1 = hora[6];
    s2 = hora[7];
    hh = h1 + h2;
    mm = m1 + m2;
    ss = s1 + s2;
    hour = stoi(hh);
    minute = stoi(mm);
    second = stoi(ss); */ 
    hour = stoi(hora.substr(0,2));
    minute = stoi(hora.substr(3,2));
    second = stoi(hora.substr(6,2));
}

void bitacoraInformacion::convertionDays(string dia){
    //De igual forma para los día se realiza una conversión de datos para lograr asegurarnos que también puedan convertirse en el sentido opuesto
    day = stoi(dia);
}


//Creación del key 
int bitacoraInformacion::keyOrganizacionCronologica(){
    int keytemp = ((mesNum*(pow(10,8)))+(day*(pow(10,6)))+(hour*(pow(10,4)))+(minute*(pow(10,2)))+second);
    return keytemp;
}

//Todos los valores se guardan a manera de apuntador para asegurarnos que se haga referencia de los mismos así como de la key al
//momento de mandarlos a llamar para que trabajen dentro de la función.

//Se desarrolla a manera de vector 


//Booleans con indicadores para que en cualquier caso diferente al constructor por default se puede llamar a la .h y realizar la lectura de los datos 
//dicha lectura de los datos se da por medio de la key que se empleará a manera numérica.


bool bitacoraInformacion::operator<(bitacoraInformacion Bitacora) {
    return this->key < Bitacora.key;
}

bool bitacoraInformacion::operator>(bitacoraInformacion Bitacora) {
    return this->key > Bitacora.key;
}

bool bitacoraInformacion::operator<=(bitacoraInformacion Bitacora) {
    return this->key <= Bitacora.key;
}

bool bitacoraInformacion::operator>=(bitacoraInformacion Bitacora) {
    return this->key >= Bitacora.key;
}

bool bitacoraInformacion::operator==(bitacoraInformacion Bitacora){
    return key == Bitacora.key;
}

void bitacoraInformacion::printBit(){
    cout<<mes<<" "<< day << " " << horaTiempo << " " << IP << " "<< notificacionAccess << endl;
}

ostream& operator << (ostream& salida, const bitacoraInformacion& b){
    salida << b.mes << " " << b.day << " " << b.horaTiempo << " " << b.IP << " " << b.notificacionAccess << endl;
    return salida;
}