#include <iostream>
#include <string>
using namespace std;

typedef struct {
    bool aquatico;
    bool predador;
    bool domestico;
    bool voador;
    bool noturno;
} tBicho;

string QualBicho(tBicho *bicho){
    if (bicho->domestico){
        return "galinha";
    }
    if (bicho->aquatico){
        if (bicho->predador){
            if (bicho->voador){
                if (bicho->noturno){
                    return "garça";
                }else{
                    return "gaivota";
                }
            }else{
                return "pinguim";
            }
        }else{
            return "pato";
        }
    }else{
        if (bicho->predador){
            if (bicho->voador){
                if (bicho->noturno){
                    return "coruja";
                }else{
                    return "falcão";
                }
            }else{
                return "ema";
            }
        }else{
            if (bicho->voador){
                return "pardal";
            }else{
                return "avestruz";
            }
        }
    }
}

int main (void){
    tBicho bicho;
    bool boolean;

    cin >> bicho.aquatico
    >> bicho.predador
    >> bicho.domestico
    >> bicho.voador
    >> bicho.noturno;

    cout << QualBicho(&bicho) << endl;

    return 0;
}
