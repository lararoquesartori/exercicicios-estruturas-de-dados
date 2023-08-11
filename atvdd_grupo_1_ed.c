#include <stdio.h>
#include <stdlib.h>
typedef struct ImoveisDaRua{
    char imovelComercial;
    int numero;
    char * complemento;
    struct ImoveisDaRua *proximo_imovel;
}IDR;

int main(){
    IDR * casa342 =malloc(sizeof(IDR)) ;
    IDR * apartamento17 =malloc(sizeof(IDR)) ;
    IDR * mercantil =malloc(sizeof(IDR)) ;

    //casa
    casa342->imovelComercial = 'N';
    casa342->numero = 342;
    casa342->complemento =malloc(12);
    casa342->complemento = "Casa, 284m2.";
    casa342->proximo_imovel = apartamento17;

    //apartamento
    apartamento17->imovelComercial = 'N';
    apartamento17->numero = 17;
    apartamento17->complemento =malloc(26);
    apartamento17->complemento = "Predio, 4 andares, 182m2.";
    apartamento17->proximo_imovel = mercantil;

    //mercantil
    mercantil->imovelComercial = 'N';
    mercantil->numero = 1;
    mercantil->complemento =malloc(22);
    mercantil->complemento = "Casa Comercial, 521m2.";
    mercantil->proximo_imovel = NULL;

    //caso queira imprimir é só "descomentar" o codigo abaixo
    /*IDR * caminha_rua = casa342;
    for(int i = 0; i < 3; i++){
        printf("Imovel Comercial: %c\n", caminha_rua->imovelComercial);
        printf("Numero do imóvel : %d\n", caminha_rua->numero);
        printf("Complemento de Dados do imóvel : %s\n", caminha_rua->complemento);
            caminha_rua = caminha_rua->proximo_imovel;
    }
    */
    return 0;

}
