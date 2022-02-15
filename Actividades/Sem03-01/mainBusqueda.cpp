#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Orden: O(n)
template<class T>
//Develop a template in order to create general information
int secuencialSearching(vector<T> list, T data) {
    for (int i = 0; i < list.size(); i++) {
        // Validates if data is equal than data list 
        if (list[i] == data) {
            // Return data position
            return i;
        }
    } //Since it is a template we take it as a template we get it back 
    throw out_of_range("ERROR DATATYPE NOT FOUND");
}

// Orden: O(log2(n))
template<class T>
//Values get organiza by themselves with library algorithm on main
int binarySearch(vector<T> list, T data) {
    int left = 0;
    int right = list.size() - 1;
    while (left <= right) {
        // We calculate the middle point through this formula 
        int middle = (left + right) / 2;
        // Validates if data chosen is the same than the data in the list in the middle
        if (list[middle] == data) {
            // Returns middle position
            return middle;
        } else {
            // We validate is the data in question chosen is minor that data on half chosen
            if (data < list[middle]) {
                // Changes to right limit depending on if the datavalue is bigger or smaller on the list 
                right = middle - 1;  //When value is smaller
            } else {
                left = middle + 1;  //When value is bigger.
            }
        }
    }
    throw out_of_range("ERROR DATATYPE NOT FOUND");
}

int main()
{
    vector<int> list = {84,74,82,45,65,99,19,83,90,39}; //In this case we develop one with an integer, but template allow us to run any datatype

    cout << "Type a natural number: ";
    int num;
    cin >> num;
    try {
        int index = secuencialSearching
    
(list, num);
        cout << "The data type" << num << " it is found on index " << index << endl;
    } catch(out_of_range& e) {
        cout << e.what() << endl;
    }
    // Ordenamos la lista
    sort(list.begin(), list.end());
    try {
        int index = binarySearch(list, num);
        cout << "El dato type " << num << " it is found on index " << index << endl;
    } catch(out_of_range& e) {
        cout << e.what() << endl;
    }

    
    
    return 0;
}