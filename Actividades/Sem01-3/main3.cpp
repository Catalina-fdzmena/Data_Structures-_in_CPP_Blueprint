#include <iostream>
using namespace std;

//In the following activity we proceed to create the following functions and call them on the main, since this is not a class we 
//don't have to put a document as a .h file, 

//Iterative addition: Calculate addition from 1 to n with iterative method
//Iterative method consists to keep adding values until we get to the top one repeating on a loop

int iterativeAddition(int n) //Over the function we add incognite value that is going to be interpreted with the value is requested eith N on the main
{
    int add = 0; //We inicializa value to accumulate values for addition as a counter
    //We add values on a for loop in order to usethe iterative part
    for(int i=1; i<=n; i++){
        add += i; //In python this looks like add = add + 1 
    }
    return add;
}

//----------------------------------------------------------------------------------------------------------------------------
//Recursive Addition: Calculate addition from 1 to n with recursive method
//Recursive method consists to keep substracting/reducing values until we get to the bottom one repeating on a loop
int recursiveAddition(int n)
{
//In recursive addition we consider to accumulate going backwards until n becomes 1 that is the first element of the list 
    if (n>1){
        return n + recursiveAddition(n-1); //So every time it goes decreasing a value that is added making the addition from the largest to the tiniest number
    }else{
        return n; //Wheneever it becomes 1 
    }
}

//----------------------------------------------------------------------------------------------------------------------------
//Direct Addition:Addition from 1 to 10 with mathematical direct addition method 

int directAddition(int n)
{
    //We develop a function based on the formula for direct addition in consecutive numbers 
    return (n*(n+1))/2;
}

//----------------------------------------------------------------------------------------------------------------------------
//Factorial function: Calculate factorial of an integer number
//Factorial means the product of all natural numbers before or equal to it.

int factorialAdd(int n)
{
    if(n>1){
        return n * factorialAdd(n-1);
    }else{
        return 1;
    }
}

//----------------------------------------------------------------------------------------------------------------------------
int main(){
    cout<< "Calculate the total addition from values begining in 1 to N"<<endl; //Add introduction
    int N; //We declare value N as a number that is going to be chosen by user 
    cout<<"Type an integer numeric value for N: "<<endl; 
    cin>>N; //We use an input in order to save it on the N concept 

//Then we print out results 
    cout<< "The iterative addition from 1 to " << N << " is:"<< iterativeAddition(N) <<endl;
    cout<< "The recursive addition from 1 to " << N << " is:"<< recursiveAddition(N) <<endl;
    cout<< "The direct addition from 1 to " << N << " is:"<< directAddition(N) <<endl;
    cout<< "The factorial of N as: " << N << " is:"<< factorialAdd(N) <<endl;
    return 0; 
}