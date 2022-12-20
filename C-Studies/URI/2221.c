#include <stdio.h>

float Golpe(int atk, int def, int lvl, int bonus){
    if (lvl % 2 == 0){
        return ((atk + def) / 2) + bonus;
    }else{
        return (atk + def) / 2;
    }
}

int main(void){
    int i, t, bonus, lvlG, lvlD;
    int atkG, defG, atkD, defD;
    float golpeG, golpeD;

    scanf("%d", &t);

    for (i = 0; i < t; i++){
        scanf("%d", &bonus);
        scanf("%d%d%d", &atkG, &defG, &lvlG);
        scanf("%d%d%d", &atkD, &defD, &lvlD);

        golpeG = Golpe(atkG, defG, lvlG, bonus);
        golpeD = Golpe(atkD, defD, lvlD, bonus);
        if (golpeG > golpeD){
            puts("Dabriel");
        }else if(golpeG == golpeD){
            puts("Empate");
        }else{
            puts("Guarte");
        }
    }

    return 0;
}
