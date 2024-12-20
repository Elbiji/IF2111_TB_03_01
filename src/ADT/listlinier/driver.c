#include <stdio.h>
#include "dplinkedlist.h"

void testLinkedList() {
    List L;
    info_barang X;
    CreateEmptyLDP(&L);

    printf("\n=== TESTING CREATE AND CHECK EMPTY LIST ===\n");
    printf("List created and initialized as empty.\n");
    printf(IsEmptyLDP(L) ? "List is empty.\n" : "List is not empty.\n");

    printf("\n=== TESTING INSERTION ===\n");
    InsVFirst(&L, "Porsche 911");
    printf("Added 'Porsche 911' at the front of the list.\n");
    InsVLast(&L, "Ferrari 488");
    printf("Added 'Ferrari 488' at the back of the list.\n");
    printf("List after insertion:\n");
    PrintForward(L);

    printf("\n=== TESTING DELETION ===\n");
    DelVFirst(&L, &X);
    printf("Deleted '%s' from the front of the list.\n", X);
    DelVLast(&L, &X);
    printf("Deleted '%s' from the back of the list.\n", X);
    printf("List after deletion:\n");
    PrintForward(L);

    printf("\n=== TESTING SEARCH ===\n");
    InsVLast(&L, "Volkswagen Beetle");
    InsVLast(&L, "Honda Civic");
    InsVLast(&L, "Chevrolet Camaro");
    printf("Added 'Volkswagen Beetle', 'Honda Civic', and 'Chevrolet Camaro' for search test.\n");
    addressDP result = Search(L, "ItemB");
    printf("Search for 'ItemB': %s\n", result != Kosong ? "Found" : "Not Found");
    result = Search(L, "ItemZ");
    printf("Search for 'ItemZ': %s\n", result != Kosong ? "Found" : "Not Found");

    printf("\n=== TESTING PRINT FUNCTIONS ===\n");
    printf("List in forward order:\n");
    PrintForward(L);
    printf("List in backward order:\n");
    PrintBackward(L);

    printf("\n=== TESTING RESET LIST ===\n");
    ResetDP(&L);
    printf("Resetting list to empty state.\n");
    printf(IsEmptyLDP(L) ? "List is empty after reset.\n" : "List is not empty after reset.\n");

    printf("\n=== TESTING ELEMENT COUNT ===\n");
    InsVLast(&L, "AK-47");
    InsVLast(&L, "Remington 700");
    InsVLast(&L, "Winchester Model 70");
    printf("List count after adding elements: %d\n", CountElmt(L));
    ResetDP(&L);
    printf("List count after reset: %d\n", CountElmt(L));
}

int main() {
    testLinkedList();
    return 0;
}