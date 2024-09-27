#include <iostream>
#include <vector>

using namespace std;

int cuantosRepetidos(const vector<int>& v1, const vector<int>& v2, int i, int j)
{
    if(i >= v1.size() || j >= v2.size()) return 0;

    if(v1[i] == v2[j]){ return 1 + cuantosRepetidos(v1, v2, ++i, ++j);}
    else if(v1[i] > v2[j]) return cuantosRepetidos(v1, v2, i, ++j);
    else return cuantosRepetidos(v1, v2, ++i, j); 
}

int cuantosRepetidos(const vector<int>& v1, const vector<int>& v2)
{
    return cuantosRepetidos(v1, v2, 0, 0);
}


int main ()
{
    vector<int> v1 = {10, 25, 37, 48, 51, 62};
    vector<int> v2 = {30, 37, 38, 40, 51};

    int resultado = cuantosRepetidos(v1, v2);

    cout << resultado << endl;
    return 0;
}