#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kartu {
    char nilai;
};

void swap(struct Kartu *a, struct Kartu *b) {
    struct Kartu temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(struct Kartu arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i].nilai);
    }
    printf("\n");
}

int minSteps(struct Kartu arr[], int n) {
    int steps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nilai > arr[j + 1].nilai) {
                swap(&arr[j], &arr[j + 1]);
                steps++;
                printf("\nPertukaran %d: ", steps);
                printArray(arr, n); 
            }
        }
    }
    return steps;
}

int main() {
    printf("Masukkan jumlah kartu: ");
    int n;
    scanf("%d", &n);

    struct Kartu arr[n];

    printf("Masukkan nilai kartu: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i].nilai);
    }

    int steps = minSteps(arr, n);
    printf("\nJumlah langkah minimum yang dibutuhkan: %d\n", steps);

    return 0;
}
