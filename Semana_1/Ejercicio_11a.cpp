#include <iostream>
#include <vector>

using namespace std;

int cuantosRepetidos(vector<int> v1, vector<int> v2)
{
    int cnt;
    int j= 0, i = 0; 

    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] == v2[j]){ ++cnt; ++j; ++i;}
        else if(v1[i] > v2[j]) ++j;
        else if(v1[i] < v2[j]) ++i;
    }

    return cnt; 
}

// Mejor caso y pero caso O(min(a, b)) pues puede ser que el primer elemento del un vector sea mas grande que todos
// los elementos del otro vector, recorriendo solamente el primero.

// Peor caso O(a + b) tendrá que recorrer todos los numeros de los dos vectores.

int main ()
{
    vector<int> v1 = {10, 25, 37, 48, 51, 62};
    vector<int> v2 = {30, 37, 38, 40, 51};

    int resultado = cuantosRepetidos(v1, v2);

    cout << resultado << endl;
    return 0;
}