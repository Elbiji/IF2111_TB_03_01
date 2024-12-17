#include "../Header/history.h"

History *createHistory() {
    History *history = (History *)malloc(sizeof(History));
    if (history == NULL) { 
        printf("Error: Alokasi memori gagal!\n");
        exit(1);
    }
    history->head = NULL;
    history->count = 0;
    return history;
}

void addPurchase(History *history, char *itemName, int quantity) {
    if (history == NULL || itemName == NULL) {
        printf("Error: Parameter tidak valid pada addPurchase!\n");
        return;
    }

    Purchase *newPurchase = (Purchase *)malloc(sizeof(Purchase));
    if (newPurchase == NULL) { 
        printf("Error: Alokasi memori gagal!\n");
        exit(1);
    }

    int i = 0;
    while (itemName[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
        newPurchase->itemName[i] = itemName[i];
        i++;
    }
    newPurchase->itemName[i] = '\0';

    newPurchase->quantity = quantity;
    newPurchase->next = history->head;

    history->head = newPurchase;
    history->count++;
}

void displayHistory(History *history, int n) {
    if (history == NULL) {
        printf("Error: Parameter tidak valid pada displayHistory!\n");
        return;
    }

    if (history->count == 0) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");

    Purchase *current = history->head;
    int displayed = 0;

    while (current != NULL && displayed < n) {
        printf("%d. %s %d\n", displayed + 1, current->itemName, current->quantity);
        current = current->next;
        displayed++;
    }

    printf("\n");
}

void freeHistory(History *history) {
    if (history == NULL) {
        return;
    }

    Purchase *current = history->head;

    while (current != NULL) {
        Purchase *temp = current;
        current = current->next;
        free(temp);
    }

    free(history);
}
