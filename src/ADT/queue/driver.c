#include <stdio.h>
#include "queue.h"
#include "../../misc.h"

void testQueue() {
    Queue q;
    nama_barang item;

    CreateQueue(&q);

    // data dummy untuk pengujian awal
    nama_barang dummy1 = {"tokyo"};
    nama_barang dummy2 = {"berlin"};
    enqueue(&q, dummy1);
    enqueue(&q, dummy2);
    printf("Initial Queue: ");
    displayQueue(q); // tampil [tokyo, berlin]

    int choice;
    char input[10];
    printf("\n--- Testing Queue ---\n");

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        readInput(input, 10);
        choice = strToInt(input);

        switch (choice) {
            case 1: {
                // Enqueue
                if (isFull(q)) {
                    printf("Queue is full. Cannot add more items.\n");
                } else {
                    printf("Enter item name (max %d characters): ",50);
                    readInput(item.name, 50);
                    if (strLength(item.name) >= 50) {
                        printf("Name too long! Please enter a name with fewer than %d characters.\n", 50);
                    } else {
                        enqueue(&q, item);
                        printf("Item '%s' added to the queue.\n", item.name);
                    }
                }
                break;
            }

            case 2: {
                // Dequeue
                if (!isEmpty(q)) {
                    dequeue(&q, &item);
                    printf("Item '%s' removed from the queue.\n", item.name);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;
            }

            case 3:
                // Display Queue
                printf("Current Queue: ");
                if (isEmpty(q)) {
                    printf("[]\n");
                } else {
                    displayQueue(q);
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
}

int main() {
    testQueue();
    return 0;
}