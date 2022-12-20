#include <stdio.h>
#include <string.h>

char JogoBazinga(const char *sheldon, const char *raj){
    //sheldon jogou te's'oura
    if (sheldon[2] == 's'){
        if (raj[2] == 'p' || raj[2] == 'g'){
            return 'G';
        }else if (raj[2] == 'o' || raj[2] == 'd'){
            return 'P';
        }
    }
    //sheldon jogou pa'p'el
    if (sheldon[2] == 'p'){
        if (raj[2] == 'd' || raj[2] == 'o'){
            return 'G';
        }else if (raj[2] == 's' || raj[2] == 'g'){
            return 'P';
        }
    }
    //sheldon jogou pe'd'ra
    if (sheldon[2] == 'd'){
        if (raj[2] == 'g' || raj[2] == 's'){
            return 'G';
        }else if (raj[2] == 'p' || raj[2] == 'o'){
            return 'P';
        }
    }
    //sheldon jogou la'g'arto
    if (sheldon[2] == 'g'){
        if (raj[2] == 'p' || raj[2] == 'o'){
            return 'G';
        }else if (raj[2] == 'd' || raj[2] == 's'){
            return 'P';
        }
    }
    //sheldon jogou Sp'o'ck
    if (sheldon[2] == 'o'){
        if (raj[2] == 's' || raj[2] == 'd'){
            return 'G';
        }else if (raj[2] == 'g' || raj[2] == 'p'){
            return 'P';
        }
    }
    return 'E';//empate
}

int main(void){
    int T, i;
    char sheldon[8], raj[8];

    scanf("%d", &T);
    for (i = 0; i < T; i++){
        scanf("%*c");
        scanf("%s", sheldon);
        scanf("%s", raj);
        switch (JogoBazinga(sheldon, raj)){
            case 'G':
                printf("Caso #%d: Bazinga!\n", i+1);//sheldon ganhou
                break;
            case 'P':
                printf("Caso #%d: Raj trapaceou!\n", i+1);//sheldon perdeu
                break;
            default:
                printf("Caso #%d: De novo!\n", i+1);//empate
        }
    }

    return 0;
}
