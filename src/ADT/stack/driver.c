#include <stdio.h>
#include "stack.h"
#include "../../misc.h"

void testStack() {
    Stack S;
    infotype X;
    CreateEmpty(&S);
    int choice;
    char input[20];

    printf("\n--- Testing Stack ---\n");
    do {
        printf("\nMenu:\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Check if Stack is Empty\n");
        printf("4. Check if Stack is Full\n");
        printf("5. Display Top Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        readInput(input, 20);
        choice = atoi(input);

        switch (choice) {
            case 1:
                if (IsFull(S)) {
                    printf("Stack is full. Cannot push more elements.\n");
                } else {
                    printf("Enter an integer to push: ");
                    readInput(input, 20);
                    X = atoi(input);
                    Push(&S, X);
                    printf("Element %d pushed onto the stack.\n", X);
                }
                break;

            case 2:
                if (IsEmpty(S)) {
                    printf("Stack is empty. Cannot pop elements.\n");
                } else {
                    Pop(&S, &X);
                    printf("Element %d popped from the stack.\n", X);
                }
                break;

            case 3:
                printf(IsEmpty(S) ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;

            case 4:
                printf(IsFull(S) ? "Stack is full.\n" : "Stack is not full.\n");
                break;

            case 5:
                if (IsEmpty(S)) {
                    printf("Stack is empty. No top element to display.\n");
                } else {
                    printf("Top element of the stack is: %d\n", InfoTop(S));
                }
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);
}

int main() {
    testStack();
    return 0;
}