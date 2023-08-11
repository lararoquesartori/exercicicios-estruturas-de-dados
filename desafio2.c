#include <stdio.h>
#include <stdlib.h>

typedef struct pessoas{  
    int cpf;
    struct pessoas * proxima_pessoa;
}pessoas;

pessoas * ponteiro_apontador_do_inicio = NULL;
pessoas * ponteiro_apontador_do_fim = NULL;
int tamanho_da_lista = 0;

void add(int cpf, int posicao_na_lista){
    
    if(posicao_na_lista >= 0 && posicao_na_lista <= tamanho_da_lista){
    
        pessoas * nova_pessoa = malloc(sizeof(pessoas));
        nova_pessoa->cpf = cpf;
        nova_pessoa->proxima_pessoa= NULL;
    
        if(ponteiro_apontador_do_inicio == NULL){ //lista vazia
            ponteiro_apontador_do_inicio = nova_pessoa;
            ponteiro_apontador_do_fim = nova_pessoa;
            tamanho_da_lista++;
        }else if(posicao_na_lista == 0){ //ponteiro_apontador_do_inicio
            nova_pessoa->proxima_pessoa= ponteiro_apontador_do_inicio;
            ponteiro_apontador_do_inicio = nova_pessoa;
            tamanho_da_lista++;
        }else if(posicao_na_lista == tamanho_da_lista){ //ponteiro_apontador_do_fim
            ponteiro_apontador_do_fim->proxima_pessoa= nova_pessoa;
            ponteiro_apontador_do_fim = nova_pessoa;
            tamanho_da_lista++;
        }else{ // "pessoas meio"
            
            pessoas * ponteiro_caminhador = ponteiro_apontador_do_inicio;
            for(int i = 0; i < posicao_na_lista-1; i++){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                ponteiro_caminhador = ponteiro_caminhador->proxima_pessoa;
            
            }
            nova_pessoa->proxima_pessoa= ponteiro_caminhador->proxima_pessoa;
            ponteiro_caminhador->proxima_pessoa= nova_pessoa;
            tamanho_da_lista++;
            
        }
    
    }else{
        printf("deu ruim!!\n");
    }
}

int remover(){

    pessoas *pessoa_a_ser_extinta;
    int retorno;
    int metade_pessoas = (int)tamanho_da_lista/2;

     for (int i = 0; i < metade_pessoas ; i++)
    {
        int posicao_na_lista = rand() % tamanho_da_lista;

        if(posicao_na_lista >= 0 && posicao_na_lista < tamanho_da_lista){

            if(posicao_na_lista == 0){
                pessoa_a_ser_extinta = ponteiro_apontador_do_inicio;
                if(tamanho_da_lista==1){
                    ponteiro_apontador_do_inicio = NULL;
                }else{
                    ponteiro_apontador_do_inicio = ponteiro_apontador_do_inicio->proxima_pessoa;
                }
            }else{
                pessoas *ponteiro_caminhador = ponteiro_apontador_do_inicio;
                for (int i = 0; i < posicao_na_lista- 1; i++){
                    ponteiro_caminhador = ponteiro_caminhador->proxima_pessoa;
                }
                pessoa_a_ser_extinta = ponteiro_caminhador ->proxima_pessoa;
                ponteiro_caminhador->proxima_pessoa = pessoa_a_ser_extinta->proxima_pessoa;
            }
            retorno = pessoa_a_ser_extinta->cpf;
            free(pessoa_a_ser_extinta);
            tamanho_da_lista--;
        }
    }
    return retorno;
}

void imprimir(){
    pessoas * ponteiro_caminhador = ponteiro_apontador_do_inicio;
    for(int i = 0; i < tamanho_da_lista; i++){
        printf("CPF: %d\n", ponteiro_caminhador->cpf);
            ponteiro_caminhador = ponteiro_caminhador->proxima_pessoa;
    }
}


int main(){
    add(2, 0);//0 
    add(1, 0);//0 1
    add(3, 2);//2
    add(4, 3);//3
    add(5, 4);//4
    printf("Pessoas vivas: \n");
    imprimir();

    remover();
    printf("Pessoas restantes apos a selecao randomica de Thanos: \n");
    imprimir();
    return 0;
}