#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

int main() {
    int item, choice, i;
    int arr_queue[MAX_SIZE];
    int rear = 0;
    int front = 0;
    int exit = 1;

    for (i = 0; i < MAX_SIZE; i++) {
        arr_queue[i] = -1;
    }

    do {
        system("CLS");
        printf("Queue\n");
        printf("\ni");
        for (i = 0; i < MAX_SIZE; i++) {
            printf("  %d ", i);
        }
        printf("\n");
        printf("Q");
        for (i = 0; i < MAX_SIZE; i++) {
            if (arr_queue[i] == -1) {
                printf("    ");
            }
            else {
                printf("  %d ", arr_queue[i]);
            }
        }
        printf("\nF=%d, R=%d", front == NULL ? 0 : front - 1, rear == NULL ? 0 : rear - 1);
        printf("\n\nPILIHAN:\n");
        printf("----------------\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Keluar\n");
        printf("----------------\n");
        printf("\nPilihan : ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (rear == MAX_SIZE){
                printf("\nAntrian Penuh!");
                getchar();
                getchar();
            }
            else {
                printf("\nMasukan nilai data : ");
                scanf("%d", &item);
                arr_queue[rear++] = item;
            }
        }
        else if (choice == 2) {
            if (front == rear){
                printf("\nAntrian Kosong!");
                getchar();
                getchar();
            }
            else {
                arr_queue[front++] = -1;
            }
        }
        else {
            exit = 0;
        }
    } while (exit);

    return 0;
}
