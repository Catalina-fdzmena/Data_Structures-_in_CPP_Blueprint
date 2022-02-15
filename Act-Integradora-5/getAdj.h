//Actividad Integradora 5
//Andrea Catalina Fernández Mena A01197705
#pragma once
#include <iostream>
using namespace std;

//Empleamos un struct para realizar una sobrecarga de las adyacencias mismas variendo con el IP 

struct getAdj{
  string IP;
  int adjacencies;
  getAdj(string IP, int adjacencies);
};

getAdj::getAdj(string IP, int adjacencies){
  this->IP = IP;
  this->adjacencies = adjacencies;
}

//Posible sobre carga de operadores (comentarizada ya que no se implementó)


/* bool getAdj::operator<(getAdj sample) {
    return this->key < sample.key;
}

bool getAdj::operator>(getAdj sample) {
    return this->key > sample.key;
}

bool getAdj::operator<=(getAdj sample) {
    return this->key <= sample.key;
}

bool getAdj::operator>=(getAdj sample) {
    return this->key >= sample.key;
}

bool getAdj::operator==(getAdj sample){
    return key == sample.key;
} */