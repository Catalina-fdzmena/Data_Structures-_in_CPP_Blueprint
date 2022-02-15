#include <iostream>
#include <vector>
using namespace std;

#include "Heap.h"

int main()
{
    
    vector<int> list = {5,14,53,47,8,56,39,22,18,1};
    Heap<int> heap(list);
    heap.print();

    return 0;
}

