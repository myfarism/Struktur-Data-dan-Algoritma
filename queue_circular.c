#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define MAX_SIZE 7

int antrian[MAX_SIZE];
int f = -1; // awal antrian
int r = -1; // akhir antrian

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int is_empty() {
    if (f == -1 && r == -1) {
        return 1;
    } else {
        return 0;
    }
}

int is_full() {
    if ((r + 1) % MAX_SIZE == f) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue() {
    int item;
    if (is_full()) {
        gotoxy(0, 5); printf("Antrian Penuh!");
        getchar();
        getchar();
    } else {
        if (is_empty()) {
            f = r = 0;
        } else {
            r = (r + 1) % MAX_SIZE;
        }
        printf("Masukkan nilai data: ");
        scanf("%d", &item);
        antrian[r] = item;
    }
}

void dequeue() {
    if (is_empty()) {
        gotoxy(0, 5); printf("Antrian Kosong!");
        getchar();
        getchar();
    } else {
        printf("Data yang dihapus: %d", antrian[f]);
        antrian[f] = 0;
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % MAX_SIZE;
        }
    }
}

int main() {
    int pil;
    do {
        system("cls");
        printf("ANTRIAN\n\n");
        printf("i\n");
        for (int i = 0; i < MAX_SIZE; i++) {
            gotoxy(i*3+5, 2); printf("%d", i);
        }
        printf("\nQ");
        for (int i = 0; i < MAX_SIZE; i++) {
            gotoxy(i*3+5, 3); printf("%d", antrian[i]);
        }
        printf("\n");
        printf("Front=%d, Rear=%d", f, r);
        if (is_empty()) {
            printf("\nQUEUE dalam keadaan KOSONG");
        } else {
            printf("\n");
        }
        printf("\n\n");
        printf("PILIHAN:\n");
        printf("----------------\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Keluar\n");
        printf("----------------\n");
        printf("Pilihan: "); scanf("%d", &pil);
        printf("\n\n");
        switch (pil) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            default:
                break;
        }
    } while (pil != 3);
    return 0;
}
