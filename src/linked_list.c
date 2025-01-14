#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "strings.h"

typedef struct Node {
    struct Node *next;
    String *value;
} Node;

Node *newNode(String *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

typedef struct LinkedList {
    Node *start;
    int len;
} LinkedList;

LinkedList *newLinkedList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->len = 0;
    list->start = NULL;
    return list;
}

void add_next(Node *node, Node *nNode) {
    if (node->next == NULL)
        node->next = nNode;
    else 
        add_next(node->next, nNode);
}

void add(LinkedList *lista, String *value) {
    Node *node = newNode(value);
    if (lista->len == 0) 
        lista->start = node; 
    else 
        add_next(lista->start, node); 
    lista->len += 1;
}

char **toArray(LinkedList *lista) {
    printf("toArray\n");
    // String *lines = (String *)malloc(sizeof(String) * lista->len);
    char **lines = malloc(sizeof(char *) * lista->len);
    
    Node *sup = lista->start;
    int count = 0;
    while (sup != NULL) {
        lines[count] = (char *)malloc(sizeof(char) * (sup->value->len - 1));
        for (int i = 0; i < sup->value->len; i++) 
            lines[count][i] = sup->value->str[i];
        
        // memcpy(lines[count], sup->value->str, sup->value->len);
        printf("%s\n", lines[count]);
        count += 1;
        sup = sup->next;
    }

    return lines;
}

void freeNode(Node *n) {
    if (n == NULL) 
        return;
    
    freeNode(n->next);

    free(n->next);
    free(n->value);
}

void freeAll(LinkedList *lista) {
    if (lista->len > 0)
        freeNode(lista->start);            
    free(lista);
}






