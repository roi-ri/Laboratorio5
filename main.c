#include <stdio.h>
#include "double_list.h"

void test_insert_at_beginning(DoubleList* list) {
    printf("\nTest Insertar al Inicio\n");
    insert_at_beginning(list, 10);
    insert_at_beginning(list, 20);
    insert_at_beginning(list, 30);
    print_list_forward(list);
}

void test_insert_at_end(DoubleList* list) {
    printf("\nTest Insertar al Final\n");
    insert_at_end(list, 40);
    insert_at_end(list, 50);
    insert_at_end(list, 60);
    print_list_forward(list);
}

void test_insert_at_index(DoubleList* list) {
    printf("\nTest Insertar en Índice Específico\n");
    insert_at_index(list, 25, 2); // Insertar 25 en la posición 2
    insert_at_index(list, 35, 4); // Insertar 35 en la posición 4
    print_list_forward(list);
}

void test_delete_by_data(DoubleList* list) {
    printf("\nTest Eliminar por Dato\n");
    delete_by_data(list, 20); // Eliminar el primer nodo con dato 20
    delete_by_data(list, 60); // Eliminar el primer nodo con dato 60
    print_list_forward(list);
}

void test_search_by_data(DoubleList* list) {
    printf("\nTest Buscar por Dato\n");
    Node* found_node = search_by_data(list, 25);
    if (found_node != NULL) {
        printf("Nodo encontrado con data 25\n");
    } else {
        printf("Nodo no encontrado con data 25\n");
    }

    found_node = search_by_data(list, 100);
    if (found_node != NULL) {
        printf("Nodo encontrado con data 100\n");
    } else {
        printf("Nodo no encontrado con data 100\n");
    }
}

void test_print_list_forward(DoubleList* list) {
    printf("\nTest Imprimir Lista hacia Adelante\n");
    print_list_forward(list);
}

void test_print_list_backward(DoubleList* list) {
    printf("\nTest Imprimir Lista hacia Atrás\n");
    print_list_backward(list);
}



int main() {
    DoubleList* list = create_list();

    // Ejecutar pruebas
    test_insert_at_beginning(list);
    test_insert_at_end(list);
    test_insert_at_index(list);
    test_delete_by_data(list);
    test_search_by_data(list);
    test_print_list_forward(list);
    test_print_list_backward(list);

    // Liberar memoria de la lista
    free_list(list);

    return 0;
}

