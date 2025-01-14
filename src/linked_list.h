#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    struct Node *next;
    char *value;
} Node;

typedef struct LinkedList {
    Node *start;
    int len;
} LinkedList;

LinkedList *newLinkedList();

void add(LinkedList *lista, String *value);
String *toArray(LinkedList *lista);
void freeAll(LinkedList *lista);

#endif;