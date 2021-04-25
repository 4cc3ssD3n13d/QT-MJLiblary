#include <QtCore>

int RandomInt(int Min, int Max){
    srand(time(0));
    return rand() % (Max - Min + 1 ) + Min;
}
