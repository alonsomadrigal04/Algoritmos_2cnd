#include <iostream>
#include <vector>

using namespace std;

int cuantosRepetidos(vector<int> v1, vector<int> v2)
{
    vector<int> minimo;

    if(v1.size() < v2.size()) minimo = v1;
    else minimo = v2;

    for(int i = 0 ; i < minimo.size();i++)
    {
        
    }
}

int main ()
{
    vector<int> v1 = {10, 25, 37, 48, 51, 62};
    vector<int> v2 = {30, 37, 38, 40, 51};

    int resultado = cuantosRepetidos(v1, v2);

    cout << resultado << endl;
    return 0;
}