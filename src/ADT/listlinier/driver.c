#include <stdio.h>
#include "dplinkedlist.h"

void testLinkedList() {
    List L;
    info_barang X;
    addressDP P;
    CreateEmptyLDP(&L);

    printf("\n=== TESTING CREATE AND CHECK EMPTY LIST ===\n");
    printf("List created and initialized as empty.\n");
    printf(IsEmptyLDP(L) ? "List is empty.\n" : "List is not empty.\n");

    printf("\n=== TESTING INSERTION FUNCTIONS ===\n");
    InsertFirst(&L, "Porsche 911");
    printf("Inserted 'Porsche 911' at the front of the list.\n");
    InsertLast(&L, "Ferrari 488");
    printf("Inserted 'Ferrari 488' at the back of the list.\n");
    InsertLast(&L, "Volkswagen Beetle");
    printf("Inserted 'Volkswagen Beetle' at the back of the list.\n");
    InsertBefore(&L, AlokasiLDP("Ferrari 488"), "Honda Civic");
    printf("Inserted 'Honda Civic' before 'Ferrari 488'.\n");
    InsertAfter(&L, AlokasiLDP("Porsche 911"), "Chevrolet Camaro");
    printf("Inserted 'Chevrolet Camaro' after 'Porsche 911'.\n");
    printf("List after multiple insertions:\n");
    PrintForward(L);

    printf("\n=== TESTING DELETION FUNCTIONS ===\n");
    DelFirst(&L, &X);
    printf("Deleted '%s' from the front of the list.\n", X);
    DelLast(&L, &X);
    printf("Deleted '%s' from the back of the list.\n", X);
    DelP(&L, "Honda Civic");
    printf("Deleted 'Honda Civic' from the list.\n");
    printf("List after multiple deletions:\n");
    PrintForward(L);

    printf("\n=== TESTING SEARCH ===\n");
    P = Search(L, "Volkswagen Beetle");
    printf("Search for 'Volkswagen Beetle': %s\n", P != Kosong ? "Found" : "Not Found");
    P = Search(L, "ItemZ");
    printf("Search for 'ItemZ': %s\n", P != Kosong ? "Found" : "Not Found");

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
    InsertLast(&L, "AK-47");
    InsertLast(&L, "Remington 700");
    InsertLast(&L, "Winchester Model 70");
    printf("List count after adding elements: %d\n", CountElmt(L));
    ResetDP(&L);
    printf("List count after reset: %d\n", CountElmt(L));
}

int main() {
    testLinkedList();
    return 0;
}