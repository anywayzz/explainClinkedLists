#include "lib.h"

#define SKIP 0
#define MANUPULATION 0
#define VAL 2
#define CHAR 'a'
#define PATH "test.txt" //for char log uses
#define PATHVAL "val.txt" //for int log uses
#define MAXLEN 255

int main (int argc, char *argv[])
{

    puts("Start\n");
    srand((unsigned)time(NULL));
    char path[] = PATH; //definizione path

    /*
    -------CREAZIONE------- 
    */
    
    //creo lista seq

    node *l1=NULL;
    l1= createLISTseq(l1,10);
    puts("\nLista seq :\n");
    viewlist(l1);
    #if SKIP


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

    //creo lista seq FILE

    nodeC *l5=NULL;
    l5 = createLISTseqFILE(l5,path);
    viewlistC(l5);

    //creo lista rec FILE

    printf("Recursively creating list from '%s':\n",path);
    nodeC *l6=NULL;
    FILE *fp = fopen(path,"r");
    l6 = createLISTrecFILE(l6,fp);
    viewlistC(l6);

    #endif
    //creo lista seq da USER

    puts("Inserisci una frase:\n");
    char string[MAXLEN];
    scanf("%[^\n]s",string);
    nodeC *l7=createStringList(l7, string);
    viewlistC(l7);
    

    /*
    -------MANIPOLAZIONE------- 
    */

    int find;
    #if MANIPULATION 
    //cerco valore intero in lista

    if((find=findVAL(l1,VAL)) == 0)
        printf("Il valore %d non e' stato trovato nella lista.\n",VAL);
    else
    {
        printf("Il valore e' %d stato trovato nella lista %d volte.\n",VAL,find);
    }

    //cerco carattere in lista
    if((find=findCHAR(l5,CHAR)) == 0)
        printf("Il carattere '%c' non e' stato trovato nella lista.\n",CHAR);
    else
    {
        printf("Il valore '%c' e' stato trovato nella lista %d volte.\n",CHAR,find);
    }

    //rimuovo valore intero da lista, controllo e visualizzo
    l1 = removeVAL(l1,VAL);
    findVAL(l1,VAL)==0 ? puts("\nRimosso correttamente\n") : puts("\nErrore rimozione.\n");
    viewlist(l1);

    //Rendo maiuscolo il carattere indicato
    selectiveUPPER(l6,CHAR);
    viewlistC(l6);

    //inserisco un a capo dopo ogni punto
    selectiveINSERT(l6,'.');
    viewlistC(l6);

    //aggiungo una frase ad un file da una lista precreata.
    logChar(l7,PATH);
    //loggo i nodi con valori interi in un file.
    logVal(l1,PATHVAL);
    #endif

    l7 = squareWords(l7);
    viewlistC(l7);


    




    return 0;
}