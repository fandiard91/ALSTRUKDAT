#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("List (memory address & data):\n");
    do {
        printf("(%p, %d) ", current, current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void sortList(struct Node** head) {
    if (*head == NULL) return;

    struct Node* current;
    struct Node* last = (*head)->prev;
    int swapped;

    do {
        swapped = 0;
        current = *head;

        while (current->next != *head) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

int main() {
    struct Node* head = NULL;
    int N, data;

    printf("Enter the number of data (N): ");
    scanf("%d", &N);

    printf("Enter %d data:\n", N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    }

    printf("List before sorting:\n");
    displayList(head);

    sortList(&head);

    printf("List after sorting:\n");
    displayList(head);

    struct Node* current = head;
    do {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

    return 0;
}
