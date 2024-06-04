#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList* list = create_list();

    insert_at_beginning(list, 10);
    insert_at_beginning(list, 20);
    insert_at_end(list, 30);
    insert_at_index(list, 25, 2);
    
    printf("Lista hacia adelante:\n");
    print_list_forward(list);

    printf("Lista hacia atrás:\n");
    print_list_backward(list);
    
    Node* found_node = search_by_data(list, 25);
    if (found_node != NULL) {
        printf("Nodo encontrado con data 25\n");
    } else {
        printf("Nodo no encontrado con data 25\n");
    }
    
    delete_by_data(list, 20);
    printf("Lista después de eliminar el nodo con data 20:\n");
    print_list_forward(list);
    
    free_list(list);
    return 0;
}

