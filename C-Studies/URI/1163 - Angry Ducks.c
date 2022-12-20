#include <stdio.h>
#include <math.h>

void ResolveEquacao2Grau(double a, double b, double c, double *x1, double *x2){
    double delta;

    delta = b*b - 4*a*c;
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
}

int main(void){
    unsigned short p1, p2, i, n;
    double h, alfa, V, Alc;
    double t1, t2;
    const double g = 9.80665, pi = 3.14159;

    while (scanf("%lf", &h) != EOF){
        scanf("%hu %hu", &p1, &p2);
        scanf("%hu", &n);

        for (i = 0; i < n; i++){
            scanf("%lf %lf", &alfa, &V);

            alfa = alfa*(pi / 180);
            ResolveEquacao2Grau(-g/2, V*sin(alfa), h, &t1, &t2);

            if (t1 > 0){
                Alc = V * cos(alfa) * t1;
            }else{
                Alc = V * cos(alfa) * t2;
            }

            if (p1 < Alc && Alc < p2){
                printf("%.5lf -> DUCK\n", Alc);
            }else{
                printf("%.5lf -> NUCK\n", Alc);
            }
        }
    }

    return 0;
}
