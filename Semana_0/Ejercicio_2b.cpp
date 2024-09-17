
// solucion recursiva
long long fibonacciRecursiva(int n) {
   if (n <= 1) return n;
   return fibonacciRecursiva(n - 1) + fibonacciRecursiva(n - 2);
}

// solucion iterativa
long long fibonacciIterativa(int n)
{
   if(n <= 1) return n;

   long long fiboAnt = 1, fiboAntAnt = 0, res = 0;
   for(int i = 2; i < n; i++)
   {
      res = fiboAnt + fiboAntAnt;
      fiboAntAnt = fiboAnt;
      fiboAnt = res;
   }
   return res;
}