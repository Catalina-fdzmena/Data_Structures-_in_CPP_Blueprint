#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Quick Sort 
//Se selecciona el primer valor de la lista y se coloca como el punto medio 

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int separacionlistay(int list[], int low, int high)
{
	int pivot = list[high]; // pivoto o valor que se pone en medio 
	int i = (low - 1); // Ubicación elemento más chico

	for (int j = low; j <= high- 1; j++)
	{
		//Se compara si el elemnto es mayor o menor que el pivote 
		if (list[j] <= pivot)
		{
			i++; //si es menor incrementa un valor en su indice 
			swap(&list[i], &list[j]);
		}
	}
	swap(&list[i + 1], &list[high]);
	return (i + 1);
}

void quickSort(int list[], int low, int high)
{
	if (low < high)
	{
		int pi = separacionlistay(list, low, high); //Posicionamiento los valores más pequeños para la izq y los más grandes a la derecha
		quickSort(list, low, pi - 1);
		quickSort(list, pi + 1, high);
	}
}

//Function to print an listay 
void printlist(int list[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int list[] = {10, 13, 15, 60, 98, 7, 8, 9, 1, 5};
	int n = sizeof(list)/sizeof(list[0]);
	quickSort(list, 0, n-1);
	printf("Sorted array: \n");
	printlist(list, n);
	return 0;
}
