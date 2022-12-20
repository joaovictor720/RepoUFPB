#include <stdio.h>

int main(void){
    float sal, nsal, gsal; //sal, nsal, gsal são salário, novo salário e ganho de salário, respectivamente

    scanf("%f", &sal);

    if (sal <= 400.00){
        nsal = sal * 1.15;
        gsal = nsal - sal;
        printf("Novo salario: %.2f\n", nsal);
        printf("Reajuste ganho: %.2f\n", gsal);
        printf("Em percentual: 15 %%\n");
    }else if (sal <= 800.00){
        nsal = sal * 1.12;
        gsal = nsal - sal;
        printf("Novo salario: %.2f\n", nsal);
        printf("Reajuste ganho: %.2f\n", gsal);
        printf("Em percentual: 12 %%\n");
    }else if (sal <= 1200.00){
        nsal = sal * 1.1;
        gsal = nsal - sal;
        printf("Novo salario: %.2f\n", nsal);
        printf("Reajuste ganho: %.2f\n", gsal);
        printf("Em percentual: 10 %%\n");
    }else if (sal <= 2000.00){
        nsal = sal * 1.07;
        gsal = nsal - sal;
        printf("Novo salario: %.2f\n", nsal);
        printf("Reajuste ganho: %.2f\n", gsal);
        printf("Em percentual: 7 %%\n");
    }else{
        nsal = sal * 1.04;
        gsal = nsal - sal;
        printf("Novo salario: %.2f\n", nsal);
        printf("Reajuste ganho: %.2f\n", gsal);
        printf("Em percentual: 4 %%\n");
    }

    return 0;
}
