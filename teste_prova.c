#include <stdio.h>

int main(){
    int vector[5];
    vector[0] = 10;
    vector[1] = 1;
    vector[2] = 5;
    vector[3] = 1;
    vector[4] = 1;
    int i = 0;
    int maior_numero = (int)vector[0];
        while(i < 4){
            if(maior_numero < vector[i+1])
                maior_numero = (int)vector[i+1];
            i++;
        }

    printf("o maior numero é: %d", maior_numero);
    return 0;
}