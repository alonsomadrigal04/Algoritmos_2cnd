#include <iostream>
#include <vector>

using namespace std;

// Numero exponencial recursivo


float exponencialPositivo(float x, int n)
{
    float resultado = exponencialPositivo(x, n /2);
    if (n == 0) return 1;
    if(n % 2) return resultado * resultado;
    return resultado * resultado * x;
}

float exponencialRecursivo(float x, int n)
{
    if(n<0) (1 / exponencialPositivo(x,n));
    return exponencialPositivo(x,n);
}