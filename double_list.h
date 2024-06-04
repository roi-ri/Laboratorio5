#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoubleList {
    Node* head;
    Node* tail;
} DoubleList;

// Funciones para manejar la lista
DoubleList* create_list();
void insert_at_beginning(DoubleList* list, int data);
void insert_at_end(DoubleList* list, int data);
void insert_at_index(DoubleList* list, int data, int index);
void delete_by_data(DoubleList* list, int data);
Node* search_by_data(DoubleList* list, int data);
void print_list_forward(DoubleList* list);
void print_list_backward(DoubleList* list);
void free_list(DoubleList* list);

#endif
