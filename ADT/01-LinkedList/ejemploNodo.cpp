
#include <iostream>
#include <vector>
using namespace std;
#include "Node.h"



int main()
{

    vector<int> list = {1,2,3,4,5,6,7,8,9,10};

    cout << list[5] << endl;
    list[5] = 16;
    cout << list[5] << endl;
    
    
    return 0;
}

