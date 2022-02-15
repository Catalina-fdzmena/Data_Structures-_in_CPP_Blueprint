//Andrea Catalina Fernández Mena A01197705
//Actividad Integradora 4

#pragma once
#include <iostream>
using namespace std;


template<class T>
struct Edge {
    T source;
    T target;
    Edge(T source, T target);
    string createKey(string ip);
};


template<class T>
Edge<T>::Edge(T source, T target) {
    this->source = createKey(source);
    this->target = createKey(target);
}

template <class T>
string Edge<T>::createKey(string ip){
    string key = ""; 
    for(int i =0; i< ip.size(); i++){
        if (ip[i] == ':'){
            break;
        } else {
            key = key + ip[i];
        } 
    }
    return key;
}