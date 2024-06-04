#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

DoubleList* create_list() {
    DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_at_beginning(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;
    
    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }
    
    list->head = new_node;
}

void insert_at_end(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;
    
    if (list->tail != NULL) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    
    list->tail = new_node;
}

void insert_at_index(DoubleList* list, int data, int index) {
    if (index == 0) {
        insert_at_beginning(list, data);
        return;
    }
    
    Node* current = list->head;
    for (int i = 0; current != NULL && i < index - 1; ++i) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Index out of bounds\n");
        return;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = current->next;
    new_node->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = new_node;
    } else {
        list->tail = new_node;
    }
    
    current->next = new_node;
}

void delete_by_data(DoubleList* list, int data) {
    Node* current = list->head;
    
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Data not found\n");
        return;
    }
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }
    
    free(current);
}

Node* search_by_data(DoubleList* list, int data) {
    Node* current = list->head;
    
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    
    return current;
}

void print_list_forward(DoubleList* list) {
    Node* current = list->head;
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_list_backward(DoubleList* list) {
    Node* current = list->tail;
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void free_list(DoubleList* list) {
    Node* current = list->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(list);
}
