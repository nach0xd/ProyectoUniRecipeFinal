#include "list.h"
#include <stdlib.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

struct List {
    Node *head;
    Node *tail;
    Node *current;
};

List *list_create() {
    List *newList = (List *)malloc(sizeof(List));
    if (newList == NULL) {
        return NULL; 
    }
    newList->head = NULL;
    newList->tail = NULL;
    newList->current = NULL;
    return newList;
}

void *list_first(List *L) {
    if (L == NULL || L->head == NULL) {
        return NULL; 
    }
    L->current = L->head;
    return L->current->data;
}

void *list_next(List *L) {
    if (L == NULL || L->current == NULL || L->current->next == NULL) {
        return NULL; 
    }
    L->current = L->current->next;
    return L->current->data;
}

void list_pushFront(List *L, void *data) {
    if (L == NULL) {
        return; 
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return; 
    }
    newNode->data = data;
    newNode->next = L->head;
    L->head = newNode;
    if (L->tail == NULL) { 
        L->tail = newNode;
    }
}

void list_pushBack(List *L, void *data) {
    if (L == NULL) {
        return; 
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return; 
    }
    newNode->data = data;
    newNode->next = NULL;
    if (L->tail == NULL) { 
        L->head = newNode;
        L->tail = newNode;
    } else {
        L->tail->next = newNode;
        L->tail = newNode;
    }
}

void list_pushCurrent(List *L, void *data) {
    if (L == NULL || L->current == NULL) {
        return; 
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return; 
    }
    newNode->data = data;
    newNode->next = L->current->next;
    L->current->next = newNode;
    if (L->current == L->tail) {
        L->tail = newNode; 
    }
}

void list_sortedInsert(List *L, void *data, int (*lower_than)(void *data1, void *data2)) {
    if (L == NULL) {
        return; 
    }

    if (L->head == NULL || lower_than(data, L->head->data)) {
        list_pushFront(L, data);
        return;
    }

    Node *current = L->head;
    while (current->next != NULL && !lower_than(data, current->next->data)) {
        current = current->next;
    }

    L->current = current;

    list_pushCurrent(L, data);
}

void *list_popFront(List *L) {
    if (L == NULL || L->head == NULL) {
        return NULL; 
    }
    Node *temp = L->head;
    L->head = L->head->next;
    if (L->head == NULL) {
        L->tail = NULL; 
    }
    void *data = temp->data;
    free(temp);
    return data;
}

void *list_popBack(List *L) {
    if (L == NULL || L->head == NULL) {
        return NULL; 
    }
    if (L->head == L->tail) { 
        return list_popFront(L);
    }
    Node *current = L->head;
    while (current->next != L->tail) {
        current = current->next;
    }
    void *data = L->tail->data;
    free(L->tail);
    current->next = NULL;
    L->tail = current;
    return data;
}

void *list_popCurrent(List *L) {
    if (L == NULL || L->current == NULL) {
        return NULL; 
    }
    if (L->current == L->head) {
        return list_popFront(L);
    }
    Node *temp = L->head;
    while (temp != NULL && temp->next != L->current) {
        temp = temp->next;
    }

    temp->next = L->current->next;
    if (L->current == L->tail) {
        L->tail = temp; 
    }
    void *data = L->current->data;
    free(L->current);
    L->current = temp->next;
    return data;
}

void list_clean(List *L) {
    if (L == NULL) {
        return; 
    }
    Node *current = L->head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    L->head = NULL;
    L->tail = NULL;
    L->current = NULL;
}

int list_contains(List *list, void *element) {
    void *current = list_first(list);
    while (current != NULL) {
        if (current == element) {
            return 1;
        }
        current = list_next(list);
    }
    return 0;
}