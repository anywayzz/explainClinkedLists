# Explaining C linked lists
This repository aims to collect the most useful tips and tricks when dealing with linked lists.

#### [ ! ] WARNING
At the moment the code is italian commented.

## Table of Contents
---
1. [Structs used](#Structs-used)
2. [Recurring algorithm patterns](#Recurring-algorithm-patterns)
    1. [Iterative creation of a list](#Iterative-creation-of-a-list)
    2. [Recursive creation of a list](#Recursive-creation-of-a-list)
    3. [Iterative deleting node](#Iterative-deleting-node)
3. [Functions](#Functions)
    1. [viewlist](#viewlist-node-head)
    2. [viewlistC](#viewlistc-nodec-head)
    3. [createListseq](#createlistseq-node-head-int-pos)
    4. [createListrec](#createlistrec-node-head-int-pos)
___
## Structs used

<table>
<tr>
    <td>
        Two main node structure.<br><code>node</code> aims to contain integer values , <code>nodeC</code> char values. They're pretty similar:
        First field contains the (int/char) value, the second one a pointer to the next (same structure) node.
    </td>
    <td style="width:30%">
        <img src="img/nodes.png"></img>
    </td>
</tr>
</table> 

## Recurring algorithm patterns
---
When dealing with creation of a list, insering and deleting a node, there are recurring functions patterns:

### Iterative creation of a list

```c
    node *tail=NULL;
    while ( /*CONDITION TO STOP NODE CREATION*/ )
    {
        if (head == NULL)
        {
            head = malloc(sizeof(node));
            tail = head;
            head->value = /*VALUE*/ ;
            head->nextNode = NULL;
        }
        else
        {
            node *temp = malloc(sizeof(node));
            tail->nextNode = temp;
            tail = temp;
            temp->value = /*VALUE*/ ;
            temp->nextNode = NULL;
        }
        //...OTHER INSTRUCTION FOR CONDITION
    }
    return head;
```
---

### Recursive creation of a list

```c
node *recursive(node *head, /*VARIABLE FOR ITERATION*/ )
{
    if ( /*CONDITION TO STOP NODE CREATION*/ )
    {
        return NULL;
    }
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        head->value = /*VALUE*/ ;
        head->nextNode = recursive(head->nextNode,
        /*MODIFIED VARIABLE FOR ITERATION*/);
        return head;
    }
    else
    {
        node *temp = malloc(sizeof(node));
        temp->value = /*VALUE*/;
        temp->nextNode = recursive(head->nextNode,
        /*MODIFIED VARIABLE FOR ITERATION*/);
        return temp;
    }
}
```
---
### Iterative deleting node

```c
    node *temp = head;
    node *previous = NULL;
    node *newHead = head;
    while (temp != NULL)
    {
        if (/*NODE CONDITION TO GET DELETED*/)
        {
            if (previous != NULL) 
            {
                previous->nextNode = temp->nextNode;
                node *toFREE=temp;
                temp = temp->nextNode;
                free(toFREE);
            }
            else 
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

```
---

## Functions
---
All functions are written in lib.c file. Below are explained.

### viewlist (node *head)
- *description*: 
    <br>Recursively print all linked nodes form a given head pointer. 
- *param*:
    <br> <code>node *head</code>: pointer to the first node of the linked list.
- *return*:
    <br> void
- *see*: 
    <br> prints only <code>node</code> type of nodes.

Execution<br>
![viewlist](img/gif/viewlist.gif)

### viewlistC (nodeC *head)
- *description*: 
    <br>Recursively print all linked nodes form a given head pointer. 
- *param*:
    <br> <code>nodeC *head</code>: pointer to the first node of the linked list.
- *return*:
    <br> void
- *see*: 
    <br> prints only <code>nodeC</code> type of nodes.
Execution:<br>
see viewlist.


### createLISTseq (node *head, int pos)
- *description*: 
    <br>Sequentially create a list with random value between 0 and GENMAX.
- *param*:
    <br> <code>node *head</code>: pointer to the first node of the linked list.
    <br> <code>int pos</code>: number of nodes to generate.
- *return*:
    <br> <code>node *</code>
- *see*: 
    <br> -

Execution:<br>
![createseq](img/gif/createlistseq.gif)

### createLISTrec (node *head, int pos)
- *description*: 
    <br>Recursively create a list with random value between 0 and GENMAX.
- *param*:
    <br> <code>node *head</code>: pointer to the first node of the linked list.
    <br> <code>int pos</code>: number of nodes to generate.
- *return*:
    <br> <code>node *</code>
- *see*: 
    <br> -

Execution:<br>
![createrec](img/gif/createlistrec.gif)
