#include <iostream>
#include <vector>

using namespace std;

int busquedaSecuencial(const vector<int> & v, int dato) {
   for (int i = 0; i < v.size(); i++)
      if (v[i] == dato)
         return i;
   return -1;
}

// Meojor caso O(1) pues el mejor caso sería que el primer dato fuera el numero que bsucamos

// Peor caso O(n) pues sería recorer todo el vector por que no estaría dentro
