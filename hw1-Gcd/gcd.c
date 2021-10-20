#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}

int main() {
  int a, b;
  printf("Please input 2 integers:");
  scanf("%d %d", &a, &b);
  printf("The GCD of [%d] and [%d] is: %d\n", a, b, gcd(a, b));
}
