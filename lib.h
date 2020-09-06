#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    int value;
    struct node* nextNode;
}node;

typedef struct nodeC
{
    char value;
    struct nodeC* nextNode;
}nodeC;

void viewlist(node *head); //2

node *createLISTseq(node* head,int pos); //3

node *createLISTrec(node *head,int pos); //3

node *createLISTseqUSER(node *head); //4

node *createLISTrecUSER(node *head); //4

void viewlistC(nodeC *head); 

nodeC *createLISTseqFILE(nodeC *head,char path[]); //5

nodeC *createLISTrecFILE(nodeC *head,FILE *fp); //5

int findVAL(node *head,int val); //6

node *removeVAL(node *head,int val); //6a

int findCHAR(nodeC *head, char c); //7

nodeC *selectiveUPPER(nodeC *head, char c); //7a

nodeC *selectiveINSERT(nodeC *head,char c); //7b

nodeC *createStringList(nodeC* head,char string[]);

void logChar(nodeC *head, char *path);

void logVal(node *head, char *path);

nodeC* squareWords(nodeC *head);

