/** ESTRUTURAS DE DADOS I**/
/** Trabalho III - SIMULADOR DE CIRCUITOS **/
/** Nome: Helbert Moreira Pinto 10716504**/

#include <stdio.h>
#include <stdlib.h>

#define AND     A
#define OR      O
#define NAND    D
#define NOR     R
#define XOR     X
#define NOT     N
#define ENTRADA E

#define MONTAGEM_LINHA  0
#define MONTAGEM_NO     1

int main(){
    int tipoMontagem;
    int qtdLinhas;
    fscanf("%d",&tipoMontagem);
    if(tipoMontagem == MONTAGEM_LINHA){
        fscanf("%d",&qtdLinhas);
    }else if(tipoMontagem == MONTAGEM_NO){

    }
    return 0;
}
