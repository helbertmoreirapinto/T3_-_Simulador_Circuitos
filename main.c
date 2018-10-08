/** ESTRUTURAS DE DADOS I**/
/** Trabalho III - SIMULADOR DE CIRCUITOS **/
/** Nome: Helbert Moreira Pinto 10716504**/

#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int tipoMontagem;
    int qtdLinhas;
    setbuf(stdin, NULL);
    fscanf(stdin, "%d", &tipoMontagem);
    Porta_PTR no;
    if(tipoMontagem == MONTAGEM_NO_A_NO){
        setbuf(stdin, NULL);
        fscanf(stdin, "%d",&qtdLinhas);

        getchar();
        for(int i = 0; i < qtdLinhas; i++){
            no = (Porta_PTR) calloc(1, sizeof(Porta));
            no->tipoPorta = fgetc(stdin);
            fscanf(stdin, "%s", no->tag);
            no->tag[2] = '\0';
            printf("%c%s\n", no->tipoPorta, no->tag);

            if(no->tipoPorta != PORTA_NOT){
                system("PAUSE");
                no = (Porta_PTR) calloc (1, sizeof(Porta));
                no->tipoPorta = fgetc(stdin);
                fscanf(stdin, "%s", no->tag);
                no->tag[2] = '\0';
                printf("%c%s\n", no->tipoPorta, no->tag);
            }

            no = (Porta_PTR) calloc(1, sizeof(Porta));
            no->tipoPorta = fgetc(stdin);
            fscanf(stdin, "%s", no->tag);
            no->tag[2] = '\0';
            printf("%c%s\n", no->tipoPorta, no->tag);
        }
    }else if(tipoMontagem == MONTAGEM_ENTRADA_DIRETA){
        getchar();
    }
    return 0;
}
