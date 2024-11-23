#include "array.h"
#include <stdio.h>
#include "../../../misc.h"

void testArray() {
    TabUser users;
    char username[50], password[50], input[10];
    int index, money;
    int choice;

    MakeEmpty(&users);

    // data dummy untuk pengujian awal
    printf("Adding dummy data for testing...\n");
    copystrng(users.TC[0].name, "perry");
    copystrng(users.TC[0].password, "senengbgt");
    users.TC[0].money = 5000;

    copystrng(users.TC[1].name, "kdos");
    copystrng(users.TC[1].password, "kdoskdos");
    users.TC[1].money = 10000;
    users.Neff = 2; 

    printf("Dummy data added.\n");

    printf("\n--- Testing Array ---\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add User\n");
        printf("2. Reset User Array\n");
        printf("3. Get Number of Elements\n");
        printf("4. Get Maximum Capacity\n");
        printf("5. Get First Index\n");
        printf("6. Get Last Index\n");
        printf("7. Get User Info by Index\n");
        printf("8. Set User Money\n");
        printf("9. Check if Index is Valid\n");
        printf("10. Check if Index is Effective\n");
        printf("11. Check if Array is Empty\n");
        printf("12. Check if Array is Full\n");
        printf("13. Print All Users\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        readInput(input, 10);
        choice = atoi(input);

        switch (choice) {
            case 1:
                if (!IsFull(users)) {
                    printf("Enter username (no spaces): ");
                    readInput(username, 50);
                    printf("Enter password (no spaces): ");
                    readInput(password, 50);
                    printf("Enter initial money: ");
                    readInput(input, 10);
                    money = atoi(input);

                    copystrng(users.TC[users.Neff].name, username);
                    copystrng(users.TC[users.Neff].password, password);
                    users.TC[users.Neff].money = money;
                    users.Neff++;
                    printf("User added successfully.\n");
                } else {
                    printf("Array is full.\n");
                }
                break;

            case 2:
                ResetTabUser(&users);
                printf("User array reset successfully.\n");
                break;

            case 3:
                printf("Number of elements: %d\n", NbElmt(users));
                break;

            case 4:
                printf("Maximum capacity: %d\n", MaxNbEl(users));
                break;

            case 5:
                if (!IsUserEmpty(users)) {
                    printf("First index: %d\n", GetFirstIdx(users));
                } else {
                    printf("Array is empty.\n");
                }
                break;

            case 6:
                if (!IsUserEmpty(users)) {
                    printf("Last index: %d\n", GetLastIdx(users));
                } else {
                    printf("Array is empty.\n");
                }
                break;

            case 7:
                if (!IsUserEmpty(users)) {
                    printf("Enter index (1-based): ");
                    readInput(input, 10);
                    index = atoi(input);

                    if (IsIdxEff(users, index)) {
                        printf("Username: %s\n", GetUserName(users, index));
                        printf("Password: %s\n", GetPassword(users, index));
                        printf("Money: %d\n", GetMoney(users, index));
                    } else {
                        printf("Index is out of range.\n");
                    }
                } else {
                    printf("Array is empty.\n");
                }
                break;

            case 8:
                if (!IsUserEmpty(users)) {
                    printf("Enter index (1-based): ");
                    readInput(input, 10);
                    index = atoi(input);

                    if (IsIdxEff(users, index)) {
                        printf("Enter new money value: ");
                        readInput(input, 10);
                        money = atoi(input);
                        SetMoney(&users, index, money);
                        printf("Money updated successfully.\n");
                    } else {
                        printf("Index is out of range.\n");
                    }
                } else {
                    printf("Array is empty.\n");
                }
                break;

            case 9:
                printf("Enter index to check (1-based): ");
                readInput(input, 10);
                index = atoi(input);

                if (IsIdxValid(users, index)) {
                    printf("Index %d is valid.\n", index);
                } else {
                    printf("Index %d is invalid.\n", index);
                }
                break;

            case 10:
                printf("Enter index to check (1-based): ");
                readInput(input, 10);
                index = atoi(input);

                if (IsIdxEff(users, index)) {
                    printf("Index %d is effective.\n", index);
                } else {
                    printf("Index %d is not effective.\n", index);
                }
                break;

            case 11:
                if (IsUserEmpty(users)) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array is not empty.\n");
                }
                break;

            case 12:
                if (IsFull(users)) {
                    printf("Array is full.\n");
                } else {
                    printf("Array is not full.\n");
                }
                break;

            case 13:
                TulisIsi(users);
                break;

            case 14:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 14.\n");
                break;
        }
    } while (choice != 14);
}

int main() {
    testArray();
    return 0;
}