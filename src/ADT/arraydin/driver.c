#include "arraydin.h"
#include <stdio.h>
#include "../../misc.h"


void testArrayDinBarang(){
    ArrayDinBarang array;
    MakeArrayDinBarang(&array);

    // data dummy untuk pengujian awal
    printf("Adding dummy data for testing...\n");
    Barang dummy1 = {"tomato", 100};
    Barang dummy2 = {"dimsum", 150};
    InsertBarang(&array, dummy1, 0);
    InsertBarang(&array, dummy2, 1);
    printf("Dummy data added.\n");

    int choice;
    char input[2];
    printf("\n--- Testing Arraydin ---\n");

    do {
        printf("\nMenu:\n");
        printf("1. Insert Barang\n");
        printf("2. Delete Barang\n");
        printf("3. Print Array\n");
        printf("4. Grow Array\n");
        printf("5. Decrease Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        readInput(input, 5);
        choice = strToInt(input);

        switch (choice) {
            case 1: {
                Barang newBarang;
                printf("Enter name (max %d characters): ", MAX_LEN);
                readInput(newBarang.name, MAX_LEN);

                printf("Enter price: ");
                char priceInput[20];
                readInput(priceInput, 20);
                newBarang.price = strToInt(priceInput);

                printf("Enter index (0-based): ");
                readInput(input, 5);
                int idx = strToInt(input);

                InsertBarang(&array, newBarang, idx);
                printf("Barang inserted successfully.\n");
                break;
            }

            case 2: {
                printf("Enter index to delete (0-based): ");
                readInput(input, 5);
                int idx = strToInt(input);

                DeleteAt(&array, idx);
                printf("Barang deleted successfully.\n");
                break;
            }

            case 3:
                if (IsEmpty(array)) {
                    printf("Array is empty.\n");
                } else {
                    printf("Current Array:\n");
                    for (int i = 0; i < array.Neff; i++) {
                        printf("Index %d: Name = %s, Price = %d\n",
                               i, array.A[i].name, array.A[i].price);
                    }
                }
                break;

            case 4:
                GrowArray(&array);
                printf("Array capacity increased to %d.\n", GetCapacity(array));
                break;

            case 5:
                DecreaseArray(&array);
                printf("Array capacity decreased to %d.\n", GetCapacity(array));
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    DeallocateArrayDinBarang(&array);
}

int main() {
    testArrayDinBarang();
    return 0;
}