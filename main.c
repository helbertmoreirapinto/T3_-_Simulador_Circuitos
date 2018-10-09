/** ESTRUTURAS DE DADOS I**/
/** Trabalho III - SIMULADOR DE CIRCUITOS **/
/** Nome: Helbert Moreira Pinto 10716504**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTAGEM_NO_A_NO        0
#define MONTAGEM_ENTRADA_DIRETA 1

enum TP{
    PORTA_AND = 'A',
    PORTA_OR = 'O',
    PORTA_NAND = 'D',
    PORTA_NOR = 'R',
    PORTA_XOR = 'X',
    PORTA_NOT = 'N',
    ENTRADA = 'E'
} TipoPorta;

struct Porta{
    struct Porta* pai;
    struct Porta* esq;
    struct Porta* dir;
    char tipoPorta;
    char tag[3];
};

typedef struct Porta Porta;
typedef Porta* Porta_PTR;
typedef Porta** Porta_PTR_PTR;

int insere_arvore(Porta_PTR_PTR, char*);
Porta_PTR consultar_porta(Porta_PTR, char*);

int main(){
    int tipoMontagem;
    int qtdLinhas;
    char entradaPorta[4];
    setbuf(stdin, NULL);
    fscanf(stdin, "%d", &tipoMontagem);
    Porta_PTR raiz = NULL;
    if(tipoMontagem == MONTAGEM_NO_A_NO){
        setbuf(stdin, NULL);
        fscanf(stdin, "%d",&qtdLinhas);
        getchar();

        for(int i = 0; i < qtdLinhas; i++){
            fscanf(stdin, "%s", entradaPorta);
            insere_arvore(&raiz, entradaPorta);

            if(entradaPorta[0] != PORTA_NOT){
                fscanf(stdin, "%s", entradaPorta);
                insere_arvore(&raiz, entradaPorta);

            }

            fscanf(stdin, "%s", entradaPorta);
            insere_arvore(&raiz, entradaPorta);
        }
    }else if(tipoMontagem == MONTAGEM_ENTRADA_DIRETA){
        getchar();
    }
    return 0;
}


int insere_arvore(Porta_PTR_PTR raiz, char* tag){
    Porta_PTR elem = (Porta_PTR) calloc(1, sizeof(Porta));
    elem->tipoPorta = tag[0];
    strcpy(elem->tag, &tag[1]);

    if(!(*raiz)){
        (*raiz) = elem;
        return 1;
    }
    Porta_PTR proc = consultar_porta(*raiz, tag);
    if(!proc)
        return 2;

    if(!proc->esq){
        proc->esq = elem;
    }else if(!proc->dir){
        proc->dir = elem;
    }else{
        return 3;
    }
    return 0;
}

Porta_PTR consultar_porta(Porta_PTR elem, char* tag){
    if(!elem)
        return NULL;
    if(elem->tipoPorta == tag[0] && !strcmp(elem->tag, &tag[1]))
        return elem;
    Porta_PTR retorno = NULL;
    if(elem->esq){
        retorno = consultar_porta(elem->esq, tag);
        if(retorno) return retorno;
    }
    if(elem->dir){
        retorno = consultar_porta(elem->dir, tag);
        if(retorno) return retorno;
    }
    return NULL;
}
