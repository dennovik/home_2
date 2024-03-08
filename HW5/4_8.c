#include <stdio.h>

int main() {
    int a, b, c, d, e,  min;
    printf("Enter five integers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

   
   min =  a < b ?  a : b;
   min = min< c ? min: c;
   min = min< d ? min: d;
   min = min< e ? min: e;
   


   printf("min: %d\n", min);

   return 0;
}
