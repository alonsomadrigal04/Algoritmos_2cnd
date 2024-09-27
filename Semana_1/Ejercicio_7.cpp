#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

void paresMinimos(vector<double>& listaNumeros)
{
    double minimo = numeric_limits<double>::infinity();
    double resultado1;
    double resultado2;
    for(int i = 0; i < listaNumeros.size() - 1; i++)
    {
        for(int j = i + 1; j < listaNumeros.size(); j++)
        {
            double aux = abs(listaNumeros[i] - listaNumeros[j]);
            if(aux < minimo)
            {
                minimo = aux;
                resultado1 = listaNumeros[i];
                resultado2 = listaNumeros[j];
            }
        }
    }

    cout << resultado1 << " - " << resultado2 << " = " << minimo << endl;
}



int main()
{
    vector<double> v1 = {2, 5, 8, 9, 12};

    paresMinimos(v1);

    return 0;
}