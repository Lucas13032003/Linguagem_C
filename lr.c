#include<stdio.h>
#include<stdlib.h>

// int main() {

//     int v[5];
//     float m;

//     v[0] = 10;
//     v[1] = 20;
//     v[2] = 30;
//     v[3] = 40;
//     v[4] = 50;

//     m = (v[0]+v[1]+v[2]+v[3]+v[4])/5;

//     printf("Resultado: %2.f\n", m);

//     return 0;
// }

int main() {
    int i;
    float v[5] = {10, 20, 30, 40, 50};
    float s;

    for ( i = 0; i < 5; i++)
        s += v[i];
    {
      
        printf("Resultado %2.f\n", s/5);
    }
    

return 0;

}