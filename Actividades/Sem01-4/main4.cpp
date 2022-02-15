#include <iostream>
using namespace std; 
//In the following code the main goal is to project multiples functions with recursión and iteration 

//1.- Develop a function that calculates the fibonacci number of a variable n that will be read from the keyboard, where n will 
//be an integer that the user will give; the fibonacci is calculated by adding the two previous fibonacci numbers, 
//therefore, the first two are not calculated

//Fibonacci Iterative
int fibonacciIterative(int n) {
    int fibo1 = 1; //Se definie 2 values that eventually are going to become consecutive.
    int fibo2 = 1;
    if (n > 2) { //As log as the fist value has been add to the other 
        for (int i = 3; i <= n; i++) {
            int aux = fibo1; //We develop an incognite value for the first number from this fibonacci order
            fibo1 = fibo2; 
            fibo2 = aux + fibo2; //We use the function/method aux in order to create a loop such as a x = x + 1 in python 
        }
        return fibo2; //We print the new value created.
    } else {
        return 1; //If the doesnt happen we just print the very first value instead
    }
}


//Fibonacci recrusive
int fibonacciRecursive(int n) {
    if (n == 1 || n == 2) {  //We equal both values showing slightly difference 
        return 1;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2); 
    }
}




//----------------------------------------------------------------------------------------------------------------------------


// 2.1 .- Bacteria's behavior growth with iterative method

int bacteriaIterative(int n) {
    int bacteria = 1; //We equal the amount to the very first value 
    for (int i = 1; i <= n; i++) {
        bacteria = bacteria * (1 + (3.78 - 2.34));  //We keep accumulating until we reach its max value
    }
    return bacteria;
}

// 2.2 .- Bacteria's behavior growth with recursive method

int bacteriaRecursive(int n){
    if(n>0)  //As long asw we can represet one bacteria 
    {
        return bacteriaRecursive(n-1) * (1 + (3.78 - 2.34));  //it goes accumulative at the same time we reduce the amount of times as long as we keep with the cicle
    }else{
        return 1;
    }
}


//----------------------------------------------------------------------------------------------------------------------------

// 3.1 .- Bank's interest growth with iterative method

int bankInterestIterative (int months, int initialBudget){  //We apply to values to analyze in this function 
    int budget = initialBudget;  //We asigne a value to accumulate including the very first initial budget 
    for (int i = 1; i <= months; i++){
        budget = budget * (1 + (18.75/100)); //We accumulate until we reach the top value
    } 
    return budget;    
}

// 3.2 .- Bank's interest growth with recursive method

int bankInterestRecursive(int months, int initialBudget){  //We remain applying both variable with this function method 
    if(months > 0) //As long as there's still some months to pay 
    {
        return bankInterestRecursive(months-1, initialBudget) * (1 + (18.75/100)); //We accumulate until we reach the top value
    }else{                                                           //As well we reduce the amount of months each time until we reach zero months of payment
        return initialBudget;
    }   
}
//-----------------------------------------------------------------------------------------------------------------------------

// 4.1 Exponent power with iterative method

int expPowerIterative(int base, int exponent) {
    int expPower = 1;  //We create kind of a default constructor in case its power is zero 
    for (int i = 1; i <= exponent; i++) {
        expPower = expPower * base;     //We add the amount of times of the exponent as an addition to it s base 
    }
    return expPower;
}
// 4.2 .- Exponent power with recursive method 

int expPowerRecursive(int base, int exponent){
    if (exponent > 0)
    {
        return expPowerRecursive(base, exponent-1)*base;
    }else{            //We add the amount of times of the exponent as an addition to it s base and we reduce the exponent counter each time this happens 
        return 1;  //Every exp that is 0 it becomes one
    }
}
//Main where you call all these functions
int main(){
    int n;
    cout << "Assign a value for N: ";
    cin >> n;
    cout << "The value that we obtain through iterative fobonacci for" << n << " is: " << fibonacciIterative(n) << endl;
    cout << "The value that we obtain through recursive fobonacci for " << n << " is: " << fibonacciRecursive(n) << endl;
    cout << "The value that we obtain through iterative bacteria calculation method for" << n << " es: " << bacteriaIterative(n) << endl;
    cout << "The value that we obtain through recursive bacteria calculation method for " << n << " es: " << bacteriaRecursive(n) << endl;
    cout << "Type the initial budget for your Credit Builder Chime Account: ";
    int initialBudget;
    cin >> initialBudget;
    cout << "Select the amount of months to pay back: ";
    int months;
    cin >> months;
    cout << "The iterative value for" << months << " months and its initial budget" << initialBudget << " is: " << bankInterestIterative (months, initialBudget) << endl;
    cout << "The recursive value for" << months << " months and its initial budget " << initialBudget << " is: " << bankInterestRecursive (months, initialBudget) << endl;
    cout << "Type the base's value: ";
    int base;
    cin >> base;
    cout << "Type the power's value: ";
    int exponent;
    cin >> exponent;
    cout << "The value for an iterative's power which its base is  " << base << " lifted up to " << exponent << " is: " << expPowerIterative(base, exponent) << endl;
    cout << "The value for an recursive's power which its base is " << base << " lifted up to " << exponent << " is: " << expPowerRecursive(base, exponent) << endl;
    
    return 0;
}