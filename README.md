# Explaining C linked lists
This repository aims to collect the most useful tips and tricks when dealing with linked lists.

#### [ ! ] WARNING
At the moment the code is italian commented.
## Structs used
Two main node structure.<br><code>node</code> aims to contain integer values , <code>nodeC</code> char values. They're pretty similar:
First field contains the (int/char) value, the second one a pointer to the next (same structure) node.

![Nodes](img/nodes.png)

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
