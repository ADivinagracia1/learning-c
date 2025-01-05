/**
 * Sample test routine for executing each function at least once.
 * Copyright Brian Fraser, 2020
 */

#include "list.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Macro for custom testing; does exit(1) on failure.
#define CHECK(condition) do{ \
    if (!(condition)) { \
        printf("ERROR: %s (@%d): failed condition \"%s\"\n", __func__, __LINE__, #condition); \
        exit(1);\
    }\
} while(0)



static void print_list(List* const pList) {

    printf("Head %p:\nSize: %d\nFlag: %d\n", pList, List_count(pList), pList->cursorFlag);
    if (pList->pCursor) printf("Current Item: %d\n", *((int*)List_curr(pList)));
    else printf("Current Item: NULL\n");

    Node* tmp = pList->pFirst;
    while (tmp != NULL) {

        printf("%d ", *((int*)tmp->pItem));
        
        tmp = tmp->pNext;
    }
    printf("\n\n");
}



// For checking the "free" function called
static int complexTestFreeCounter = 0;
static void complexTestFreeFn(void* pItem) 
{
    CHECK(pItem != NULL);
    complexTestFreeCounter++;
}

// For searching
static bool itemEquals(void* pItem, void* pArg) 
{
    return (pItem == pArg);
}

static void testComplex()
{

    // Empty list
    printf("Empty list test:\n");
    List* pList = List_create();
    CHECK(pList != NULL);
    CHECK(List_count(pList) == 0);
    print_list(pList);
    printf("PASSED\n\n");

    // Add 
    printf("Add test:\n");
    int added = 41;
    CHECK(List_add(pList, &added) == 0);
    CHECK(List_count(pList) == 1);
    CHECK(List_curr(pList) == &added);
    print_list(pList);
    printf("PASSED\n\n");

    // Insert
    printf("Insert test:\n");
    int inserted = 42;
    CHECK(List_insert(pList, &inserted) == 0);
    CHECK(List_count(pList) == 2);
    CHECK(List_curr(pList) == &inserted);
    print_list(pList);
    printf("PASSED\n\n");

    // Prepend
    printf("Prepend test:\n");
    int prepended = 43;
    CHECK(List_prepend(pList, &prepended) == 0);
    CHECK(List_count(pList) == 3);
    CHECK(List_curr(pList) == &prepended);
    print_list(pList);
    printf("PASSED\n\n");
    
    // Append
    printf("Append test:\n");
    int appended = 44;
    CHECK(List_append(pList, &appended) == 0);
    CHECK(List_count(pList) == 4);
    CHECK(List_curr(pList) == &appended);
    print_list(pList);
    printf("PASSED\n\n");
    
    // Next through it all (from before list)
    printf("Traversal test:\n");
    CHECK(List_first(pList) == &prepended);
    CHECK(List_prev(pList) == NULL);
    CHECK(List_next(pList) == &prepended);
    CHECK(List_next(pList) == &inserted);                     
    CHECK(List_next(pList) == &added);
    CHECK(List_next(pList) == &appended);                     
    CHECK(List_next(pList) == NULL);
    CHECK(List_next(pList) == NULL);

    // Prev through it all
    //   starting from past end
    CHECK(List_last(pList) == &appended);
    CHECK(List_next(pList) == NULL);
    CHECK(List_prev(pList) == &appended);
    CHECK(List_prev(pList) == &added);                        
    CHECK(List_prev(pList) == &inserted);                     
    CHECK(List_prev(pList) == &prepended);                    
    CHECK(List_prev(pList) == NULL);                          
    CHECK(List_prev(pList) == NULL);   
    printf("PASSED\n\n");                       

    // Remove first
    printf("Remove test:\n");
    CHECK(List_first(pList) == &prepended);
    CHECK(List_remove(pList) == &prepended);
    CHECK(List_curr(pList) == &inserted);          
    print_list(pList);   
    printf("PASSED\n\n");        

    // Trim last
    printf("Trim test:\n");
    CHECK(List_trim(pList) == &appended);
    CHECK(List_curr(pList) == &added);      
    print_list(pList);   
    printf("PASSED\n\n");               
                                                                
    // Free remaining 2 elements
    printf("Free test:\n");
    complexTestFreeCounter = 0;
    List_free(pList, complexTestFreeFn);
    CHECK(complexTestFreeCounter == 2);      
    print_list(pList);        
    printf("PASSED\n\n");         

    // Max out heads and nodes
    printf("Max test:\n");
    int i;
    int j = 0;
    List* lists[LIST_MAX_NUM_HEADS];
    int items[LIST_MAX_NUM_NODES];
	for (i = 0; i < LIST_MAX_NUM_NODES; i++) items[i] = i;
    for (i = 0; i < LIST_MAX_NUM_HEADS; i++) {
    	lists[i] = List_create();
    	for (int k = 0; k < (LIST_MAX_NUM_NODES / LIST_MAX_NUM_HEADS); k++)
    		List_append(lists[i], &items[j++]);
    }
    CHECK(List_create() == NULL);
    int rejectedItem = -1;
    CHECK(List_append(lists[0], &rejectedItem) == -1);

    // Free all nodes and heads
    complexTestFreeCounter = 0;
    for (i = 0; i < LIST_MAX_NUM_HEADS; i++) List_free(lists[i], complexTestFreeFn);
    CHECK(complexTestFreeCounter == LIST_MAX_NUM_NODES);
	printf("PASSED\n\n");

    // Concat
	printf("Concat test:\n");
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    List* pList1 = List_create();
    List_add(pList1, &one);
    List_add(pList1, &two);
    print_list(pList1);
    List* pList2 = List_create();
    List_add(pList2, &three);
    List_add(pList2, &four);
    print_list(pList2);
    
    List_concat(pList1, pList2);
    print_list(pList1);
    CHECK(List_count(pList1) == 4);
    CHECK(List_first(pList1) == &one);
    CHECK(List_last(pList1) == &four);     
    printf("PASSED\n\n");                   

    // Search
    printf("Search test:\n");
    List_first(pList1);
    CHECK(List_search(pList1, itemEquals, &two) == &two);       
    CHECK(List_search(pList1, itemEquals, &two) == &two);       
    CHECK(List_search(pList1, itemEquals, &one) == NULL);       
    printf("PASSED\n\n");
}

int main(int argCount, char *args[]) 
{
    testComplex();

    // We got here?!? PASSED!
    printf("********************************\n");
    printf("           PASSED\n");
    printf("********************************\n");
    return 0;
}