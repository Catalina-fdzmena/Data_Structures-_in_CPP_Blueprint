#pragma once

template<class T>
struct Edge {
    T source;
    T target;
    int weight;
    Edge();
    Edge(T source, T target, int weight);
};

template<class T>
Edge<T>::Edge() {
    weight = 0;
}

template<class T>
Edge<T>::Edge(T source, T target, int weight) {
    this->source = source;
    this->target = target;
    this->weight = weight;
}
