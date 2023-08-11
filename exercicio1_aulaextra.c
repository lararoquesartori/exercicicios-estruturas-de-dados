#include <stdio.h>
#include <stdlib.h>


typedef struct No{
 
    //dados da conta bancaria
    char *nome;
    int numero;
    int senha;
    double saldo;
    
    //mecanismo p/ unir nos!
    struct No * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


//adiciona ordenado pelo saldo! :D
void cadastrarConta(char *nome, int numero, int senha, double saldo){

    
        //1 - preparo o nó para entrar na lista
        NO * novo = malloc(sizeof(NO));
        novo->nome = nome;
        novo->numero = numero;
        novo->senha = senha;
        novo->saldo = saldo;
        novo->prox = NULL;
    
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
           
        }else if(novo->saldo <= inicio->saldo){ //inicio
            novo->prox = inicio;
            inicio = novo;
         
        }else if(novo->saldo >= fim->saldo){ //fim
            fim->prox = novo;
            fim = novo;
          
        }else{ // "no meio"
            
            NO * aux = inicio;
            
            while(aux->prox->saldo < novo->saldo){//enquanto o saldo da frente for menor que o novo que desejo adicionar ele cotinua caminhando
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            
        }
    tam++;
    
}


void visualizar(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Nome: %s\n", aux->nome);
        printf("Saldo: %f\n", aux->saldo);
        aux = aux->prox;
    }
}

void removerConta(int numero){
    
        //remover!
        if(inicio->numero == numero){ //inicio!
            
            NO *lixo = inicio;
            inicio = inicio->prox;
            free(lixo);
            tam--;
            if(tam == 1){
                fim = NULL;
            }
            
        }else { //meio e fim
            
            NO * aux = inicio;
            while(aux->prox->numero != numero){
                //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
                aux = aux->prox;
            
            }
            NO *lixo = aux->prox;
            aux->prox = aux->prox->prox;
            if(lixo->prox == NULL){
                fim = aux;
            }
            free(lixo);
            tam--;
          
        }

}

void depositar(int numero, int senha, float valor){
     NO * aux = inicio;
            while(aux->numero != numero){//busca a conta
                aux = aux->prox;        
            }    
            if(aux->senha == senha){//correto
                aux->saldo = aux->saldo + valor;
            //como  a lista é reordenada por saldo ent tem que realocar a posição do item na lista
            removerConta(aux->numero);
            cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);  
            }
}

void sacar(int numero, int senha, float valor){
     NO * aux = inicio;
            while(aux->numero != numero){//busca a conta
                aux = aux->prox;        
            }    
            if(aux->senha == senha){//correto
                aux->saldo = aux->saldo - valor;
            //como  a lista é reordenada por saldo ent tem que realocar a posição do item na lista
            removerConta(aux->numero);
            cadastrarConta(aux->nome, aux->numero, aux->senha, aux->saldo);  
            }
}

int main(){

    cadastrarConta("Yoshi", 74837, 12345, 50.0);
   // cadastrarConta("Bowser", 3456, 12345, 359.9);
   // cadastrarConta("Mario", 3333, 12345, 150.0);
    cadastrarConta("Luigi", 3434, 12345, 200.0);
   // cadastrarConta("Peach", 5555, 12345, 359.9);
    cadastrarConta("Dayse", 3776, 12345, 250.0);
    printf("lista apos as adicoes: ");
    visualizar();
    //removerConta(5555);
    //removerConta(3456);
    //printf("lista apos as remocoes: ");
    //visualizar();
    depositar(3434, 12345, 64.55);
    printf("lista apos deposito: ");
    visualizar();

    sacar(3434, 12345, 64.55);
    printf("lista apos saque: ");
    visualizar();
    
    return 0;
}