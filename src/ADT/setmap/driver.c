#include <stdio.h>
#include "map.h"
#include "../../misc.h"

void testMap() {
    Map M;
    CreateEmpty(&M);
    int choice;
    keytype key[50]; 
    valuetype value;
    char input[20];

    printf("\n--- Testing Map ---\n");
    do {
        printf("\nMenu:\n");
        printf("1. Insert Key-Value\n");
        printf("2. Delete Key\n");
        printf("3. Check Membership\n");
        printf("4. Get Value by Key\n");
        printf("5. Check if Map is Empty\n");
        printf("6. Check if Map is Full\n");
        printf("7. Display All Elements\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        readInput(input, 20);
        choice = atoi(input);

        switch (choice) {
            case 1:
                if (IsFullMap(M)) {
                    printf("Map is full. Can't add more elements.\n");
                } else {
                    printf("Enter key: ");
                    readInput(key, 50);

                    printf("Enter value: ");
                    readInput(input, 20);
                    value = atoi(input);

                    if (IsMember(M, key)) {
                        printf("Key '%s' already exists in the Map. Insert operation skipped.\n", key);
                    } else {
                        Insert(&M, key, value);
                        printf("Key-Value pair ('%s', %d) inserted into the Map.\n", key, value);
                    }
                }
                break;

            case 2:
                printf("Enter key to delete: ");
                readInput(key, 50);

                if (IsMember(M, key)) {
                    Delete(&M, key);
                    printf("Key '%s' deleted from the Map.\n", key);
                } else {
                    printf("Key '%s' is not found in the Map.\n", key);
                }
                break;

            case 3:
                printf("Enter key to check membership: ");
                readInput(key, 50);

                if (IsMember(M, key)) {
                    printf("Key '%s' is a member of the Map.\n", key);
                } else {
                    printf("Key '%s' is not a member of the Map.\n", key);
                }
                break;

            case 4:
                printf("Enter key to get value: ");
                readInput(key, 50);

                value = Value(M, key);
                if (value != Undefined) {
                    printf("Value for key '%s' is %d.\n", key, value);
                } else {
                    printf("Key '%s' is not found in the Map.\n", key);
                }
                break;

            case 5:
                if (IsEmptyMap(M)) {
                    printf("Map is empty.\n");
                } else {
                    printf("Map is not empty.\n");
                }
                break;

            case 6:
                if (IsFullMap(M)) {
                    printf("Map is full.\n");
                } else {
                    printf("Map is not full.\n");
                }
                break;

            case 7:
                if (IsEmptyMap(M)) {
                    printf("Map is empty.\n");
                } else {
                    printf("Current elements in the Map:\n");
                    for (int i = 0; i < M.Count; i++) {
                        printf("- Key: '%s', Value: %d\n", M.Elements[i].nama_barang_keranjang, M.Elements[i].jumlah_barang);
                    }
                }
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
    } while (choice != 8);
}

int main() {
    testMap();
    return 0;
}