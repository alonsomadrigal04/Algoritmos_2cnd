#include <iostream>
#include <vector>

using namespace std;

int sumar(const vector<int> & v) {
   int suma = 0;
   for (int i = 0; i < v.size(); i++)
      suma += v[i];
   return suma;
}

// O(n) no hay mejor caso pues se sumarán todos los numeros que hayan en el vector

int sumar(const vector<int> & v) {
   if (v.size() == 0)
      return 0;
   if (v.size() == 1)
      return v[0];
   int suma = v[0];
   for (int i = 1; i < v.size(); i++)
      suma += v[i];
   return suma;
}

// No cambiaría nada por que independientemente ed su talla se tendrá
// que sumar todos los numeros del vector.