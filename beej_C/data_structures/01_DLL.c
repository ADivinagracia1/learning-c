#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    double value;
    struct list *prev, *next;
} List;

List *create(double value) {
    List *new_list = (List *)malloc(sizeof(List));
    new_list->value = value;
    new_list->next = NULL;
    new_list->prev = NULL;
    return new_list;
}

List *insert(List *list, double value, int pos) {
    
    // Handling an Empty List
    if ( list == NULL ) { list = create(value); return list;}

    // Check which position to insert new element
    if ( pos > 0 ) {
        List *cpy = list, *temp = cpy;
        int flag = 1, index = 1, size = 0;

        // Move temp to the end of the list
        while ( temp != NULL ) { size++; temp=temp->next; }

        // create new node at first position case (new node pushes everything else)
        if ( pos == 1) {
            List* new_node = create(value);
            new_node->next = cpy; 
            list = new_node;
            return list;
        }

        // insert at specified position
        if (size + 2 > pos) {
            // traverse to insertion position
            while (cpy->next != NULL && index < pos ) {
                flag++; 
                index++;
                cpy = cpy->next; // cpy is on the position where the new node is inserted
            }
        }

        // Create node and perform insert ===================
        List *new_node = (List *)malloc(sizeof(List));
        new_node->value = value;
        // position into list with no pointer for NULL
        if (flag == pos)
        {
            cpy->prev->next = new_node;
            new_node->next = cpy;
            new_node->prev = cpy->prev;
            cpy->prev = new_node;
        }
        // last position case
        if (flag < pos) {
            new_node->next = cpy->next;
            new_node->prev = cpy;
            cpy->next = new_node;
        }
    }
    return list;
}

// NOTE: Copy is cursor 

List *delete(List *list, int pos) {
    
    if (list == NULL) return list;

    if (pos > 0) {
        List *cpy = list, *tmp = cpy;
        int flag = 1, index = 1, size = 0;

        // count size, use tmp as end of list
        while (tmp != NULL) { size++; tmp=tmp->next; }
    
        // Deleting the first position
        if (pos == 1) {
            if (size == NULL) { return NULL; }
            cpy = cpy->next;
            cpy->prev = NULL;
            return cpy;
        }

        // Position existing within a range
        if (size + 2 > pos) {
            while (cpy->next != NULL && index < pos) {
                flag++;
                index++;
                cpy = cpy->next;
            }
            
            // Perform the deleting of that positoin
            if (flag == pos) {
                if (cpy->next != NULL){
                    cpy->prev->next = cpy->next;
                    cpy->next->prev = cpy->prev;
                }
                else {
                    cpy->prev->next = NULL;
                }
            }
        }

    }

}

int search(List *list, double value){
    if (list == NULL) return 0;
    if (list->value == value) return 1;
    search(list->next, value);
}

void print(List *list){
    if (list != NULL){
        printf("%f - ", list->value);
        print(list->next); // recursive function
    }
    printf("\n");
}

void example()
{
    List *my_list = NULL;
    double node_value = 0;
    int searching;

    my_list = create(node_value);
    my_list = insert(my_list, 3, 1);
    my_list = insert(my_list, 5, 3);
    my_list = insert(my_list, 10, 3);
    my_list = insert(my_list, 20, 3);
    print(my_list);

    searching = search(my_list, 20);
    printf("\n%d\n", searching);

    my_list = delete (my_list, 1);
    print(my_list);
    my_list = delete (my_list, 1);
    print(my_list);


    searching = search(my_list, 20);
    printf("\n%d\n", searching);
        
}

int main(void){
    example();
    return 0;
}

