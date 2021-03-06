#include "lib.h"

#define GENMAX 3
#define VAL 2
#define CHAR 'a'
#define PATH "test.txt" //for char log uses
#define PATHVAL "val.txt" //for int log uses
#define MAXLEN 255

void logo()
{
    system("@cls||clear");
    puts("╦  ┬┌┐┌┬┌─┌─┐┌┬┐  ┬  ┬┌─┐┌┬┐┌─┐  ┌─┐┬  ┌─┐┬ ┬┬─┐┌─┐┌─┐┌┬┐\r");
    puts("║  ││││├┴┐├┤  ││  │  │└─┐ │ └─┐  ├─┘│  ├─┤└┬┘├┬┘│ ││ ││││\r");
    puts("╩═╝┴┘└┘┴ ┴└─┘─┴┘  ┴─┘┴└─┘ ┴ └─┘  ┴  ┴─┘┴ ┴ ┴ ┴└─└─┘└─┘┴ ┴\r");
    puts("---------------------------------------------------------");
    puts("More at: https://github.com/anywayzz/explainClinkedLists\n");
    printf("current VAL: %d\n",VAL);
    printf("current CHAR: %c\n",CHAR);
    printf("current PATH: %s\n",PATH);
    printf("current PATHVAL: %s\n",PATHVAL);
    puts("---------------------------------------------------------\n");
    return;
}

node* create_menu()
{
    int choice=0;
    node *currentlist=NULL;
    int i=0;

    logo();
    puts("1. Create a new list.");
    puts("2. Exit.");
    printf("\n> ");scanf("%d",&choice);
    if(choice==1)
    {
        logo();
        puts("1. Linked list of values\n");
        puts("2. Linked list of characters\n");
        printf("\n> ");scanf("%d",&choice);
        if(choice==1)
        {
            logo();
            puts("1. Random values\n");
            puts("2. Keyboard input\n");
            printf("\n> ");scanf("%d",&choice);
            if(choice==1)
            {
                logo();
                puts("1. Sequential creation\n");
                puts("2. Recursive creation\n");
                printf("\n> ");scanf("%d",&choice);
                if(choice==1)
                {
                    int nodes=0;
                    logo();
                    puts("How many nodes?\t");
                    do
                    {
                        printf("\n> ");scanf("%d",&nodes);
                    } while (nodes<=0);
                    //create list seq
                }
                if(choice==2)
                {
                    logo();
                    //create list rec;
                }
                else
                {
                    return create_menu();
                }
                
            }
            if(choice==2)
            {
                logo();
                puts("1. Sequential creation\n");
                puts("2. Recursive creation\n");
                printf("\n> ");scanf("%d",&choice);
                if(choice==1)
                {
                    logo();
                    //create list seq user
                }
                if(choice==2)
                {
                    logo();
                    //create list rec user;
                }
                else
                {
                    return create_menu();
                }
                
            }
            else
            {
                return create_menu();
            }
            
        }
        if(choice==2)
        {
            logo();
            puts("1. Linked list from file\n");
            puts("2. Linked list by keyboard\n");
            printf("\n> ");scanf("%d",&choice);
            if(choice==1)
            {
                logo();
                puts("1. Sequential creation\n");
                puts("2. Recursive creation\n");
                printf("\n> ");scanf("%d",&choice);
                if(choice==1)
                {
                    //create list seq file
                }
                if(choice ==2)
                {
                    //create list rec file
                }
                else
                {
                    return create_menu();
                }
            }
            if(choice ==2)
            {
                #if skip
                    puts("Inserisci una frase:\n");
                    char string[MAXLEN];
                    scanf("%[^\n]s",string);
                    nodeC *l7=createStringList(l7, string);
                    viewlistC(l7);
                #endif
            }
            else
            {
                return create_menu();
            }
            
        }
        else
        {
            return create_menu();
        }
    }
    else if(choice==2)
    {
        return currentlist;
    }
    else
    {
        puts("Wrong input.\n");
        return create_menu();
    }
    return currentlist;
}

void viewlist(node *head)
{
    if (head == NULL)
    {
        puts("NULL\n");
        return;
    }
    else
    {
        printf("%d ->", head->value);
        return viewlist(head->nextNode);
    }
}

node *createLISTseq(node *head, int pos)
{
    node *tail=NULL;
    while (pos != 0)
    {
        if (head == NULL)
        {
            head = malloc(sizeof(node));
            tail = head;
            head->value = rand() % GENMAX;
            head->nextNode = NULL;
        }
        else
        {
            node *temp = malloc(sizeof(node));
            tail->nextNode = temp;
            tail = temp;
            temp->value = rand() % GENMAX;
            temp->nextNode = NULL;
        }
        pos = pos-1;
    }
    return head;
}

node *createLISTrec(node *head, int pos)
{
    if (pos == 0)
    {
        return NULL;
    }
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        head->value = rand() % GENMAX;
        head->nextNode = createLISTrec(head->nextNode,pos-1);
        return head;
    }
    else
    {
        node *temp = malloc(sizeof(node));
        temp->value = rand() % GENMAX;
        temp->nextNode = createLISTrec(head->nextNode,pos-1);
        return temp;
    }
}

node *createLISTseqUSER(node *head)
{
    node *tail=NULL;
    int val=-1;
    puts("Inserisci valori, per terminare premi 0.\n");
    while (val != 0)
    {
        scanf("%d",&val);
        if(val==0)
            return head;
        if (head == NULL)
        {
            head = malloc(sizeof(node));
            tail = head;
            head->value = val;
            head->nextNode = NULL;
        }
        else
        {
            node *temp = malloc(sizeof(node));
            tail->nextNode = temp;
            tail = temp;
            temp->value = val;
            temp->nextNode = NULL;
        }
    }
    return head;
}

node *createLISTrecUSER(node *head)
{
    int val=-1;
    scanf("%d",&val);
    if (val == 0)
    {
        return NULL;
    }
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        head->value = val;
        head->nextNode = createLISTrecUSER(head->nextNode);
        return head;
    }
    else
    {
        node *temp = malloc(sizeof(node));
        temp->value = val;
        temp->nextNode = createLISTrecUSER(head->nextNode);
        return temp;
    }
}

void viewlistC(nodeC *head)
{
    if (head == NULL)
    {
        puts("NULL\n");
        return;
    }
    else
    {
        printf("%c ->", head->value);
        return viewlistC(head->nextNode);
    }
}

nodeC *createLISTseqFILE(nodeC *head,char path[])
{
    printf("Creating list from '%s':\n",path);
    FILE *fp = fopen(path,"r");
    nodeC *tail=NULL;
    char c= 0;
    while((c=fgetc(fp))!=EOF)
    {
            if (head == NULL)
            {
                head = malloc(sizeof(node));
                tail = head;
                head->value = c;
                head->nextNode = NULL;
            }
            else
            {
                nodeC *temp = malloc(sizeof(node));
                tail->nextNode = temp;
                tail = temp;
                temp->value = c;
                temp->nextNode = NULL;
            }
    }
    
    fclose(fp);
    return head;
}

nodeC *createLISTrecFILE(nodeC *head,FILE *fp)
{
    char c;
    if ((c=fgetc(fp))==EOF)
    {
        return NULL;
    }
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        head->value = c;
        head->nextNode = createLISTrecFILE(head->nextNode,fp);
        return head;
    }
    else
    {
        nodeC *temp = malloc(sizeof(node));
        temp->value = c;
        temp->nextNode = createLISTrecFILE(head->nextNode,fp);
        return temp;
    }
}

int findVAL(node *head,int val)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        if(head->value == val)
        {
            return 1 + findVAL(head->nextNode,val);
        }
        return findVAL(head->nextNode,val);
    }
}

node *removeVAL(node *head,int val)
{
    node *temp = head;
    node *previous = NULL;
    node *newHead = head;
    while (temp != NULL)
    {
        if (temp->value == val)
        {
            if (previous != NULL) //inmezzo
            {
                previous->nextNode = temp->nextNode;
                node *toFREE=temp;
                temp = temp->nextNode;
                free(toFREE);
            }
            else //primo
            {
                node *toFREE=temp;
                temp = temp->nextNode;
                newHead = temp;
                free(toFREE);
            }
        }
        else
        {
            previous = temp;
            temp = temp->nextNode;
        }
    }
    return newHead;
}

int findCHAR(nodeC *head, char c)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        if(head->value == c)
        {
            return 1+findCHAR(head->nextNode,c);
        }
        return findCHAR(head->nextNode,c);
    }
    
}

nodeC *selectiveUPPER(nodeC *head, char c)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        if(head->value == c)
        {
            head->value = head->value-32;
        }
        return selectiveUPPER(head->nextNode,c);
    }
}

nodeC *selectiveINSERT(nodeC *head,char c) //ad ogni punto va a capo.
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        if(head->value == c)
        {
            nodeC *toINSERT = malloc(sizeof(node));
            toINSERT->value= 10;
            toINSERT->nextNode=head->nextNode;
            head->nextNode=toINSERT;
        }
        return selectiveINSERT(head->nextNode,c);
    }
    
}

nodeC *createStringList(nodeC* head,char string[])
{
    nodeC *tail=head;
    for(int i=0; i<strlen(string);i++)
    {
        if(i==0)
        {
            head=malloc(sizeof(nodeC));
            head->value = string[i];
            head->nextNode = NULL;
            tail = head;
        }
        else
        {
            nodeC *temp = malloc(sizeof(nodeC));
            tail->nextNode = temp;
            tail = temp;
            temp->value = string[i];
            temp->nextNode = NULL;
        }
    }
    return head;
}

void logChar(nodeC *head,char *path)
{
    FILE *fp = fopen(path,"a+");
    fputc(10,fp);
    fputs("[LOG]: ",fp);
    while(head!=NULL)
    {
        fputc(head->value,fp);
        head = head->nextNode;
    }
    fclose(fp);
}

void logVal(node *head, char *path)
{
    FILE *fp = fopen(path,"a+");
    while(head!=NULL)
    {
        char str[5]; //max 5 cifre
        sprintf(str, "[%d] ",head->value);
        fputs(str,fp);
        head = head->nextNode;
    }
    fputs("NULL\n",fp);
    fclose(fp);
    return;
}

nodeC *squareWords(nodeC *head)
{
    //TODO: efficiency
    int cont=0;
    nodeC *newHead=head,*temp=head;
    while(temp!=NULL)
    {
        if(cont==0)
        {
            newHead=malloc(sizeof(nodeC));
            newHead->nextNode = head;
            newHead->value = '[';   
        }
        if(temp->value== ' ')
        {
            nodeC *square = malloc(sizeof(nodeC));
            square->value= ' ';
            temp->value= ']';
            square->nextNode = temp->nextNode;
            temp->nextNode = square->nextNode;
        }
        if(temp->value == ']')
        {
            nodeC *square = malloc(sizeof(nodeC));
            square->value='[';
            square->nextNode = temp->nextNode;
            temp->nextNode=square;
        }
        if(temp->nextNode==NULL)
        {
            nodeC *square = malloc(sizeof(nodeC));
            square->value=']';
            square->nextNode = NULL;
            temp->nextNode = square;
            head = newHead;
            return head;
        }
        cont++;
        temp= temp->nextNode;
    }
    head = newHead;
    return head;
}


