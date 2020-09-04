#include "lib.h"

#define SKIP 0
#define MANUPULATION 0
#define VAL 2
#define CHAR 'a'
#define PATH "test.txt"

int main (int argc, char *argv[])
{

    puts("Start\n");
    srand((unsigned)time(NULL));
    char path[] = PATH; //definizione path

    /*
    -------CREAZIONE------- 
    */
    
         #if SKIP
    //creo lista seq
    node *l1=NULL;
    l1= createLISTseq(l1,10);
    puts("\nLista seq :\n");
    viewlist(l1);
    //creo lista rec
    node *l2 = NULL;
    l2= createLISTrec(l1,10);
    puts("\nLista rec :\n");
    viewlist(l2);

   
    
    //creo lista seq USER
    node *l3=NULL;
    l3= createLISTseqUSER(l3);
    puts("\nLista seq USER :\n");
    viewlist(l3);
    //creo lista rec USER
    node *l4=NULL;
    l4= createLISTrecUSER(l4);
    puts("\nLista rec USER :\n");
    viewlist(l4);

    nodeC *l5=NULL;
    l5 = createLISTseqFILE(l5,path);
    viewlistC(l5);

    #endif
    printf("Recursively creating list from '%s':\n",path);
    nodeC *l6=NULL;
    FILE *fp = fopen(path,"r");
    l6 = createLISTrecFILE(l6,fp);
    viewlistC(l6);
    /*
    -------MANIPOLAZIONE------- 
    */

    int find;
    #if MANIPULATION 
    if((find=findVAL(l1,VAL)) == 0)
        printf("Il valore %d non e' stato trovato nella lista.\n",VAL);
    else
    {
        printf("Il valore e' %d stato trovato nella lista %d volte.\n",VAL,find);
    }
    if((find=findCHAR(l5,CHAR)) == 0)
        printf("Il carattere '%c' non e' stato trovato nella lista.\n",CHAR);
    else
    {
        printf("Il valore '%c' e' stato trovato nella lista %d volte.\n",CHAR,find);
    }

    l1 = removeVAL(l1,VAL);
    findVAL(l1,VAL)==0 ? puts("\nRimosso correttamente\n") : puts("\nErrore rimozione.\n");
    viewlist(l1);

    selectiveUPPER(l6,CHAR);
    viewlistC(l6);

    selectiveINSERT(l6,'.');
    viewlistC(l6);
    #endif
    




    return 0;
}