long long fibonacciRecursiva(int n) {
   if (n <= 1) return n;
   return fibonacciRecursiva(n - 1) + fibonacciRecursiva(n - 2);
}