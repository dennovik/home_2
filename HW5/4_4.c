#include <stdio.h>

int main() {
    int a, b, c, d, e, max, min;
    printf("Enter five integers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

   
   max =  a > b ?  a : b;
   max = max> c ? max: c;
   max = max> d ? max: d;
   max = max> e ? max: e;
   
   min =  a < b ?  a : b;
   min = min< c ? min: c;
   min = min< d ? min: d;
   min = min< e ? min: e;
   
   int sum = max + min;

   printf("sum max+min: %d\n", sum);

   return 0;
}

